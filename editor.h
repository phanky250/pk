#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>

class Editor : public QWidget {
    Q_OBJECT
public:
    explicit Editor(QWidget *parent = nullptr);
    void setImage(const QImage &);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QRect pixelRect(int, int) const;
    QImage image;
signals:

};

#endif // EDITOR_H
