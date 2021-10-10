#pragma once
#include "api.h"
#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <QFile>
#include <QTextStream>
#include <Qt>

class EXPORTED MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent);
    ~MainWindow();

private:
    QGridLayout *m_layout;
    QMenuBar *m_menuBar;
};