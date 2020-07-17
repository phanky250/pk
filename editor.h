#ifndef EDITOR_H
#define EDITOR_H

#include "axissetting.h"
#include <QWidget>
#include <QToolButton>
class Editor : public QWidget {
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
    void setImage(const QImage &newImage);

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    void setAxisSetting(const AxisSetting &setting);
    void setImagePixel(const QPoint &pos, bool opaque);
    void refreshPixmap();

    QPixmap pixmap;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QVector<AxisSetting> zoomStack;
    unsigned int curZoom;
signals:

};

#endif // EDITOR_H
