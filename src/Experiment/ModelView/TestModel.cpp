#include <QTreeView>

#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QString>

#include <iostream>

int main(int argc, char *argv[])
  {
  QApplication a(argc, argv);
  QTreeView treeView;
  QStandardItemModel model;
  QStandardItem *parentItem = model.invisibleRootItem();

  for (int i = 0; i < 4; i++)
    {
    QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
    parentItem->appendRow(item);
    parentItem = item;
    }
  treeView.setModel(&model);
  treeView.show();
  return a.exec();
  }
