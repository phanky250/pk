#include <QtGui>

#include "editor.h"
Editor::Editor(QWidget *parent) : QWidget(parent) {
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);
    setFocusPolicy(Qt::StrongFocus);
    zoomInButton = new QToolButton(this);
    zoomOutButton = new QToolButton(this);
    connect(zoomInButton, SIGNAL(clicked()), this, SLOT(zoomIn()));
    connect(zoomOutButton, SIGNAL(clicked()), this, SLOT(zoomOut()));
    setAxisSetting(AxisSetting());
}

void Editor::setAxisSetting(const AxisSetting &setting) {
    zoomStack.clear();
    zoomStack.append(setting);
    curZoom = 0;
    zoomInButton->hide();
    zoomOutButton->hide();
    refreshPixmap();
}

void Editor::zoomIn() {
    if (curZoom < zoomStack.count() - 1) {
        ++curZoom;
        zoomInButton->setEnabled(curZoom < zoomStack.count() - 1);
        zoomOutButton->setEnabled(true);
        zoomOutButton->show();
        refreshPixmap();
    }
}

void Editor::zoomOut() {
    if (curZoom > 0) {
        --curZoom;
        zoomOutButton->setEnabled(curZoom > 0);
        zoomInButton->setEnabled(true);
        zoomInButton->show();
        refreshPixmap();
    }
}
void Editor::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        setImagePixel(event->pos(), true);
    } else if (event->button() == Qt::RightButton) {
        setImagePixel(event->pos(), false);
    }
}

void Editor::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        setImagePixel(event->pos(), true);
    } else if (event->buttons() & Qt::RightButton) {
        setImagePixel(event->pos(), false);
    }
}

void Editor::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(palette().foreground().color());


}


