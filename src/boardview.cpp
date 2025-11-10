#include "boardview.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QContextMenuEvent>
#include <cmath>

static constexpr QColor CLARO(205, 205, 205);
static constexpr QColor OSCURO(94, 94, 94);

void ItemFicha::paint(QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) {
    QGraphicsEllipseItem::paint(p, o, w);
    if (reina) {
        p->setBrush(QColor(240, 200, 0));
        p->setPen(Qt::NoPen);
        auto r = rect();
        double radio = std::min(r.width(), r.height()) * 0.16;
        p->drawEllipse(r.center(), radio, radio);
    }
}

BoardView::BoardView(QWidget* parent)
    : QGraphicsView(parent), escena(new QGraphicsScene(this)) {
    setScene(escena);
    setRenderHint(QPainter::Antialiasing, true);
    setMinimumSize(800, 800);
    resize(900, 900);
    iniciar();
    repintar();
}

void BoardView::iniciar() {
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c) {
        tablero[f][c] = {};
        items[f][c] = nullptr;
    }
    for (int f = 0; f < 4; ++f) for (int c = 0; c < N; ++c)
        if ((f + c) % 2 == 1) tablero[f][c] = { ColorFicha::Azul,false };
    for (int f = N - 4; f < N; ++f) for (int c = 0; c < N; ++c)
        if ((f + c) % 2 == 1) tablero[f][c] = { ColorFicha::Rojo,false };
    turno = ColorFicha::Rojo;
    sel.reset();
    en_cadena = false;
    setWindowTitle(QStringLiteral("Turno: Rojo"));
}

void BoardView::resizeEvent(QResizeEvent*) {
    tam = std::floor(std::min(width(), height()) / double(N));
    escena->setSceneRect(0, 0, tam * N, tam * N);
    repintar();
}

bool BoardView::enRango(int f, int c) const { return f >= 0 && f < N && c >= 0 && c < N; }
bool BoardView::vacia(int f, int c) const { return tablero[f][c].color == ColorFicha::Ninguno; }
QPointF BoardView::pos(int f, int c) const { return { c * tam, f * tam }; }
std::pair<int, int> BoardView::celda(const QPointF& p) const { return { int(p.y() / tam), int(p.x() / tam) }; }

void BoardView::coronar(int f, int c) {
    if (!tablero[f][c].reina) {
        if (tablero[f][c].color == ColorFicha::Rojo && f == 0) tablero[f][c].reina = true;
        if (tablero[f][c].color == ColorFicha::Azul && f == N - 1) tablero[f][c].reina = true;
    }
}

std::vector<Destino> BoardView::movimientos(int f, int c, bool solo_capturas) const {
    std::vector<Destino> r;
    if (!enRango(f, c)) return r;
    const Ficha& P = tablero[f][c];
    if (P.color == ColorFicha::Ninguno) return r;

    auto oscura = [&](int ff, int cc) { return enRango(ff, cc) && ((ff + cc) % 2 == 1); };
    auto libre = [&](int ff, int cc) { return oscura(ff, cc) && vacia(ff, cc); };
    auto rival = [&](int ff, int cc) { return enRango(ff, cc) && !vacia(ff, cc) && tablero[ff][cc].color != P.color; };

    if (!P.reina) {
        int dir = (P.color == ColorFicha::Rojo) ? -1 : 1;
        if (!solo_capturas) {
            if (libre(f + dir, c + 1)) r.push_back({ f + dir, c + 1, false, -1, -1 });
            if (libre(f + dir, c - 1)) r.push_back({ f + dir, c - 1, false, -1, -1 });
        }
        for (int dc : {-1, 1}) {
            int f1 = f + dir, c1 = c + dc, f2 = f + 2 * dir, c2 = c + 2 * dc;
            if (!enRango(f2, c2) || !enRango(f1, c1)) continue;
            if (!libre(f2, c2)) continue;
            if (rival(f1, c1)) r.push_back({ f2,c2,true,f1,c1 });
        }
        return r;
    }

    for (int df : {-1, 1}) for (int dc : {-1, 1}) {
        int fr = f + df, cr = c + dc;
        while (enRango(fr, cr) && oscura(fr, cr) && vacia(fr, cr)) {
            if (!solo_capturas) r.push_back({ fr,cr,false,-1,-1 });
            fr += df; cr += dc;
        }
        if (!enRango(fr, cr)) continue;
        if (!rival(fr, cr)) continue;
        int f2 = fr + df, c2 = cr + dc;
        while (enRango(f2, c2) && oscura(f2, c2) && vacia(f2, c2)) {
            r.push_back({ f2,c2,true,fr,cr });
            f2 += df; c2 += dc;
        }
    }
    return r;
}

bool BoardView::hayCaptura(ColorFicha j) const {
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c)
        if (tablero[f][c].color == j && !movimientos(f, c, true).empty())
            return true;
    return false;
}

bool BoardView::hayMovimientos(ColorFicha j) const {
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c) {
        if (tablero[f][c].color != j) continue;
        if (!movimientos(f, c, true).empty()) return true;
        if (!movimientos(f, c, false).empty()) return true;
    }
    return false;
}

void BoardView::repintar() {
    escena->clear();
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c)
        escena->addRect(c * tam, f * tam, tam, tam, Qt::NoPen, ((f + c) % 2 == 0) ? CLARO : OSCURO);
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c) {
        if (tablero[f][c].color == ColorFicha::Ninguno) continue;
        auto p = pos(f, c);
        double r = tam * 0.15;
        auto* it = new ItemFicha(QRectF(p.x() + r, p.y() + r, tam - 2 * r, tam - 2 * r));
        it->setBrush(tablero[f][c].color == ColorFicha::Rojo ? QColor(220, 50, 50) : QColor(50, 120, 220));
        it->setPen(Qt::NoPen);
        it->reina = tablero[f][c].reina;
        escena->addItem(it);
        items[f][c] = it;
    }
    setWindowTitle(turno == ColorFicha::Rojo ? QStringLiteral("Turno: Rojo") : QStringLiteral("Turno: Azul"));
}

void BoardView::cambiarTurno() {
    turno = (turno == ColorFicha::Rojo) ? ColorFicha::Azul : ColorFicha::Rojo;
    sel.reset();
    en_cadena = false;
    repintar();
    ColorFicha op = (turno == ColorFicha::Rojo) ? ColorFicha::Azul : ColorFicha::Rojo;
    int cnt_op = 0;
    for (int f = 0; f < N; ++f) for (int c = 0; c < N; ++c)
        if (tablero[f][c].color == op) ++cnt_op;
    if (cnt_op == 0 || !hayMovimientos(op)) {
        QMessageBox::information(this, QStringLiteral("Fin del juego"),
            turno == ColorFicha::Rojo ? QStringLiteral("Gana Rojo") : QStringLiteral("Gana Azul"));
        iniciar();
        repintar();
    }
}

void BoardView::mousePressEvent(QMouseEvent* e) {
    auto [f, c] = celda(mapToScene(e->pos()));
    if (!enRango(f, c)) return;
    if (!sel) {
        if (tablero[f][c].color != turno) return;
        sel = { f,c };
        if (hayCaptura(turno)) {
            auto caps = movimientos(f, c, true);
            if (caps.empty()) {
                QMessageBox::information(this, QStringLiteral("Movimiento no permitido"),
                    QStringLiteral("Hay captura obligatoria."));
                sel.reset();
            }
        }
        return;
    }
    auto [sf, sc] = *sel;
    bool obligatorio = hayCaptura(turno);
    auto opciones = movimientos(sf, sc, obligatorio);
    Destino elegido{};
    bool ok = false;
    for (const auto& d : opciones) if (d.fila == f && d.col == c) { elegido = d; ok = true; break; }
    if (!ok) {
        QMessageBox::information(this, QStringLiteral("Movimiento no permitido"),
            obligatorio ? QStringLiteral("Debe capturar.") : QStringLiteral("Casilla inválida."));
        sel.reset();
        return;
    }
    Ficha pieza = tablero[sf][sc];
    tablero[sf][sc] = {};
    tablero[f][c] = pieza;
    bool comio = elegido.captura;
    if (comio) tablero[elegido.fila_medio][elegido.col_medio] = {};
    coronar(f, c);
    if (comio) {
        sel = std::make_pair(f, c);
        auto mas = movimientos(f, c, true);
        if (!mas.empty()) { en_cadena = true; repintar(); return; }
    }
    cambiarTurno();
}

void BoardView::contextMenuEvent(QContextMenuEvent* ev) {
    QMenu m(this);
    QAction* a1 = m.addAction(QStringLiteral("Nuevo"));
    QAction* a2 = m.addAction(QStringLiteral("Reglas"));
    QAction* a3 = m.addAction(QStringLiteral("Salir"));
    QAction* a = m.exec(ev->globalPos());
    if (a == a1) { iniciar(); repintar(); }
    else if (a == a2) {
        QMessageBox::information(this, QStringLiteral("Reglas"),
            QStringLiteral("Tablero 10x10. Movimiento diagonal en casillas oscuras. ")
            + QStringLiteral("Fichas normales: caminan y capturan solo hacia adelante. ")
            + QStringLiteral("Damas: mueven y capturan en cualquier distancia y dirección. ")
            + QStringLiteral("Captura obligatoria y cadenas. Gana quien deja al rival sin piezas o sin movimientos."));
    }
    else if (a == a3) close();
}
