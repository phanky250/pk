#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QAction;
class QLabel;
class FindDialog;
class Spreadsheet;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;
private:
    void        createContextMenu();
    void        createToolBar();
    void        createActions();
    void        createMenus();
    void        createStatusBar();
    QAction     *fileAction;
    QToolBar    *fileToolBar;
    QMenu       *fileMenu;
    QLabel      *location;
};

#endif // MAINWINDOW_H
