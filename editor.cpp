#include <QtGui>
#include <QStylePainter>
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
    QRect rect(0, 0, width(), height());

    if (event->button() == Qt::LeftButton) {
        rubberBandIsShown = true;
        rubberBandRect.setTopLeft(event->pos());
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
        setCursor(Qt::CrossCursor);
    }
}

void Editor::mouseMoveEvent(QMouseEvent *event) {
    if (rubberBandIsShown) {
        rubberBandRect.setBottomRight(event->pos());
        updateRubberBandRegion();
    }
}

void Editor::mouseReleaseEvent(QMouseEvent *event) {
    if ((event->button() == Qt::LeftButton) && rubberBandIsShown) {
        rubberBandIsShown = false;
        updateRubberBandRegion();
        unsetCursor();
        QRect rect = rubberBandRect.normalized();

        if (rect.width() < 4 || rect.height() < 4)
            return;
    }
}
void Editor::paintEvent(QPaintEvent *) {
    QStylePainter painter(this);
    painter.drawPixmap(0, 0, pixmap);

    if (rubberBandIsShown) {
        painter.setPen(palette().light().color());
        painter.drawRect(rubberBandRect.normalized());
    }

}

void Editor::resizeEvent(QResizeEvent *) {
    int x = width() - (zoomInButton->width() + zoomOutButton->width() + 10);
    zoomInButton->move(x, 5);
    zoomOutButton->move(x + zoomInButton->width() + 5, 5);
    refreshPixmap();
}

void Editor::updateRubberBandRegion() {
    update();
}

void Editor::refreshPixmap() {

}
