#include <QtGui>

#include "editor.h"
#include "resource.h"
Editor::Editor(QWidget *parent) : QWidget(parent) {
    //  image = QImage(320, 320, QImage::Format_ARGB32);
    //image.fill(qRgba(155, 55, 25, 255));
    image = QImage("mouse.png");
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

    for (int i = 0; i < image.width(); ++i) {
        for (int j = 0; j < image.height(); ++j) {
            QColor color = QColor::fromRgba(image.pixel(i, j));
            painter.fillRect(QRect(i, j, 1, 1), color);

        }
    }

}

void Editor::setImagePixel(const QPoint &pos, bool wht) {
    int i = pos.x();
    int j = pos.y();

    if (image.rect().contains(i, j)) {
        if (!wht) {
            image.setPixel(i, j, qRgba(0, 0, 0, 255));
        } else {
            image.setPixel(i, j, qRgba(255, 255, 255, 255));
        }

        update();
    }
}

