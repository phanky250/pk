#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

class Editor : public QWidget {
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
    void setImage(const QImage &newImage);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QRect pixelRect(int, int) const;
    void setImagePixel(const QPoint &pos, bool opaque);
    QImage image;
signals:

};

#endif // EDITOR_H
