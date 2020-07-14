#ifndef ITEMLIST_H
#define ITEMLIST_H
#include <QListWidget>

class ItemList : public QListWidget {
    Q_OBJECT
public:
    ItemList(QWidget * parent = 0);

private slots:
    void itemClicked(QListWidgetItem *);

private:
    void addItem();
};

#endif // ITEMLIST_H
