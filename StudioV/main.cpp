#include <iostream>
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    std::cout << "Studio V version 1.0.0 by Delirium Technologies." << std::endl;

    QApplication app(argc, argv);
    app.setObjectName("_application");

    QWidget root;
    root.setObjectName("_application_root");

    MainWindow window(&root);
    window.setStyleSheet("QMainWindow { background-color: #3d3d3d }");
    window.show();

    return app.exec();
}