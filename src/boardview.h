#pragma once
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <optional>
#include <vector>

enum class ColorFicha { Ninguno, Rojo, Azul };

struct Ficha {
    ColorFicha color = ColorFicha::Ninguno;
    bool reina = false;
};

struct Destino {
    int fila;
    int col;
    bool captura;
    int fila_medio;
    int col_medio;
};

struct ItemFicha : QGraphicsEllipseItem {
    using QGraphicsEllipseItem::QGraphicsEllipseItem;
    bool reina = false;
    void paint(QPainter* p, const QStyleOptionGraphicsItem* o, QWidget* w) override;
};

struct BoardView : QGraphicsView {
    static constexpr int N = 10;

    QGraphicsScene* escena = nullptr;
    Ficha tablero[N][N]{};
    ItemFicha* items[N][N]{};
    double tam = 0;
    ColorFicha turno = ColorFicha::Rojo;
    std::optional<std::pair<int, int>> sel;
    bool en_cadena = false;

    BoardView(QWidget* parent = nullptr);

    void iniciar();
    void repintar();
    void cambiarTurno();
    void coronar(int f, int c);

    bool enRango(int f, int c) const;
    bool vacia(int f, int c) const;
    QPointF pos(int f, int c) const;
    std::pair<int, int> celda(const QPointF&) const;

    std::vector<Destino> movimientos(int f, int c, bool solo_capturas) const;
    bool hayCaptura(ColorFicha jugador) const;
    bool hayMovimientos(ColorFicha jugador) const;

    void resizeEvent(QResizeEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void contextMenuEvent(QContextMenuEvent*) override;

    void menuNuevo();
    void menuReglas();
    void menuSalir();
};
