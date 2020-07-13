#include "mainwindow.h"
#include <QtGui>
#include <QAction>
#include <QStatusBar>
#include <QMenuBar>
#include <QToolBar>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    setWindowTitle("phanky");
    resize(600, 400);
    createActions();
    createMenus();
    createContextMenu();
    createToolBar();
    createStatusBar();
}

MainWindow::~MainWindow() {
}
void MainWindow::createStatusBar() {
    location = new QLabel("phanky");
    statusBar()->addWidget(location);
}
void MainWindow::createActions() {
    fileAction = new QAction(tr("&New"), this);
    fileAction->setShortcut(QKeySequence::New);
}
void MainWindow::createMenus() {
    fileMenu = menuBar()-> addMenu(tr("&File"));
    fileMenu->addAction(fileAction);
}
void MainWindow::createContextMenu() {
    addAction(fileAction);
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void MainWindow::createToolBar() {
    fileToolBar = addToolBar(tr("&File"));
    fileToolBar->addAction(fileAction);
}
void closeEvent(QCloseEvent *event) {
    event->accept();
}
