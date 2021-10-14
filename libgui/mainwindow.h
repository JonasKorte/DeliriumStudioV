#pragma once
#include "api.h"
#include "resourceloader.h"
#include "views/arrangement.h"
#include "components/toolbar.h"
#include <iostream>
#include <vector>
#include <QMainWindow>
#include <QTabWidget>
#include <QGraphicsDropShadowEffect>
#include <QMenuBar>
#include <QAction>
#include <QKeySequence>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QAction>
#include <QLabel>
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

    void CreateViews();

private:
    QMenuBar *m_menuBar;
    Toolbar* m_toolBar;
    ArrangementView* m_arrangement;
    std::vector<bool> m_openViews;
    QTabWidget* m_tabWidget;

    bool m_currentProjectSaved;
};