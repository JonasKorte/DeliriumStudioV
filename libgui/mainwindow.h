#pragma once
#include "api.h"
#include <iostream>
#include <QMainWindow>
#include <QGridLayout>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <Qt>

class EXPORTED MainWindow : public QMainWindow
{
public:
    MainWindow(QWidget *parent);
    ~MainWindow();

    void CreateFileMenu();
    void CreateEditMenu();
    void CreateViewMenu();
    void CreateAddMenu();
    void CreateExportMenu();
    void CreateHelpMenu();

    void NewProjectClicked();

    void CreateNewProject();

    int SaveChangesDialog();

    const char *SaveCurrentProject();

private:
    QGridLayout *m_layout;
    QMenuBar *m_menuBar;

    bool m_currentProjectSaved;
};