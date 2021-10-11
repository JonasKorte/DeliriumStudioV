#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->m_currentProjectSaved = true;

    this->setWindowTitle("Delirium Studio V");
    this->setWindowState(Qt::WindowState::WindowMaximized);
    this->setBaseSize(1920, 1080);
    this->setWindowIcon(QIcon(":/res/img/logo.png"));
    this->setObjectName("_main_window");

    this->m_layout = new QGridLayout(this);

    this->setLayout(this->m_layout);

    this->m_menuBar = new QMenuBar(this);
    this->m_menuBar->setObjectName("_main_menu_bar");

    this->CreateFileMenu();
    this->CreateEditMenu();
    this->CreateViewMenu();
    this->CreateAddMenu();
    this->CreateExportMenu();
    this->CreateHelpMenu();

    QFile menuBarStyleSheet(":/res/qts/menuBar.qts");
    if (menuBarStyleSheet.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&menuBarStyleSheet);

        QString data = "";

        while (!in.atEnd())
        {
            QString line = in.readLine();

            data.append(line);
            data.append(" ");
        }

        this->m_menuBar->setStyleSheet(data);
    }
    else
    {
        std::cerr << "Failed to load stylesheet at qrc:/res/qts/menuBar.qts!" << std::endl;
    }

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this->m_menuBar);

    shadow->setBlurRadius(10.0);
    shadow->setColor(QColor::fromRgb(0, 0, 0, 128));
    shadow->setXOffset(0.0);
    shadow->setYOffset(2.0);

    this->m_menuBar->setGraphicsEffect(shadow);

    this->setMenuBar(this->m_menuBar);
}

MainWindow::~MainWindow()
{
    delete (this->m_menuBar);
    delete (this->m_layout);
    QMainWindow::~QMainWindow();
}

void MainWindow::CreateFileMenu()
{
    QMenu *fileMenu = new QMenu("File", this->m_menuBar);
    fileMenu->setObjectName("_file_menu");

    QAction *newAction = new QAction("New Project", fileMenu);
    newAction->setShortcuts(QKeySequence::New);
    newAction->setStatusTip("Creates a new project. Ctrl + N");

    connect(newAction, &QAction::triggered, this, &MainWindow::NewProjectClicked);

    fileMenu->addAction(newAction);

    this->m_menuBar->addMenu(fileMenu);
}

void MainWindow::CreateEditMenu()
{
    QMenu *editMenu = new QMenu("Edit", this->m_menuBar);
    editMenu->setObjectName("_edit_menu");

    this->m_menuBar->addMenu(editMenu);
}

void MainWindow::CreateViewMenu()
{
    QMenu *viewMenu = new QMenu("View", this->m_menuBar);
    viewMenu->setObjectName("_view_menu");

    this->m_menuBar->addMenu(viewMenu);
}

void MainWindow::CreateAddMenu()
{
    QMenu *addMenu = new QMenu("Add", this->m_menuBar);
    addMenu->setObjectName("_add_menu");

    this->m_menuBar->addMenu(addMenu);
}

void MainWindow::CreateExportMenu()
{
    QMenu *exportMenu = new QMenu("Export", this->m_menuBar);
    exportMenu->setObjectName("_export_menu");

    this->m_menuBar->addMenu(exportMenu);
}

void MainWindow::CreateHelpMenu()
{
    QMenu *helpMenu = new QMenu("Help", this->m_menuBar);
    helpMenu->setObjectName("_help_menu");

    this->m_menuBar->addMenu(helpMenu);
}

void MainWindow::NewProjectClicked()
{
    if (!this->m_currentProjectSaved)
    {
        int result = this->SaveChangesDialog();

        if (result == 0)
        {
            std::cout << SaveCurrentProject() << std::endl;
        }
        else if (result == 1)
        {
            this->CreateNewProject();
        }
        else if (result == 2)
        {
            return;
        }
    }
    else
    {
        this->CreateNewProject();
    }
}

void MainWindow::CreateNewProject()
{
}

int MainWindow::SaveChangesDialog()
{
    QMessageBox::StandardButton reply;

    reply = QMessageBox::question(this, "Save Project", "Do you want to save changes to the current project?", QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    if (reply == QMessageBox::Save)
    {
        return 0;
    }
    else if (reply == QMessageBox::Discard)
    {
        return 1;
    }
    else if (reply == QMessageBox::Cancel)
    {
        return 2;
    }
}

const char *MainWindow::SaveCurrentProject()
{
    bool success = true;

    if (success)
    {
        this->m_currentProjectSaved = true;

        return "Saved successfully!";
    }

    this->m_currentProjectSaved = false;

    return "Error saving project!";
}