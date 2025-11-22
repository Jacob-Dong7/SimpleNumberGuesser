#include <iostream>
#include <QApplication>
#include "Generator.h"
#include "mainwindow.h"
//Simple number generator
//Generates a random number within user specified ranges
//ranges cannot be smaller than 0

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow main;
    main.show();

    return app.exec();
}