#include "editor.h"
#include "resource.h"
#include <QtGui>
Editor::Editor(QWidget *parent) : QWidget(parent) {
    image = QImage(300, 300, QImage::Format_ARGB32);
    image.fill(qRgba(0, 0, 0, 0));
}
void Editor::setImage(const QImage & newImage) {
    if (newImage != image) {
        image = newImage.convertToFormat(QImage::Format_ARGB32);
        update();
        updateGeometry();
    }
}
QRect Editor::pixelRect(int i, int j) const {
    return QRect(i, j, editor::rectWidth, editor::rectHeight);

}
void Editor::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(palette().foreground().color());

    for (int i = 0; i <= image.width(); i += 10) {
        painter.drawLine(i, 0,
                         i, image.height());
    }

//    for (int i = 0; i < image.width(); i += 10) {
//        for (int j = 0; j < image.height(); j += 10) {
//            QRect rect = pixelRect(i, j);

//            if (!event->region().intersect(rect).isEmpty()) {
//                QColor color = QColor::fromRgba(image.pixel(i, j));

//                if (color.alpha() < 255)
//                    painter.fillRect(rect, Qt::white);

//                painter.fillRect(rect, color);
//            }
//        }
//    }
}

