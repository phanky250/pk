#include "mainwindow.h"
#include "itemlist.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    ItemList *leftWidget = new ItemList;
    leftWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QFrame *vFrame = new QFrame;
    vFrame->setFrameShape(QFrame::VLine);

    QWidget *rightWidget = new QWidget;
    rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(leftWidget);
    layout->addWidget(vFrame);
    layout->addWidget(rightWidget);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
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
