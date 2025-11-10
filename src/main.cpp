#include <QApplication>
#include "boardview.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    BoardView ventana;
    ventana.show();
    return app.exec();
}