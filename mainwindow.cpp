#include "mainwindow.h"
#include "itemlist.h"
#include "editor.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {

    leftPanel = new ItemList;
    leftPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QFrame *vFrame = new QFrame;
    vFrame->setFrameShape(QFrame::VLine);

    Editor *editorPanel = new Editor;
    editorPanel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(leftPanel);
    layout->addWidget(vFrame);
    layout->addWidget(editorPanel);

    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    setCentralWidget(widget);
    setWindowTitle("phanky");
    resize(600, 600);

    createActions();
    createMenus();
    //createContextMenu();
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
