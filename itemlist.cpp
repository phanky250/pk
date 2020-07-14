#include "itemlist.h"
#include <QtWidgets>
ItemList::ItemList(QWidget *parent) : QListWidget(parent) {
    addItem();
    connect(this, SIGNAL(itemClicked(QListWidgetItem *)),
            this, SLOT(itemClicked(QListWidgetItem *)));
}
void ItemList::itemClicked(QListWidgetItem *item) {
    //item->setText("213");
    QMessageBox::about(this, tr("phanky"), item->text());
}
void ItemList::addItem() {
    QListWidget::addItem("C++");
    QListWidget::insertItem(0, "Java");
}
