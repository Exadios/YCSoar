#include <QTreeView>
#include "../../XCSoarThunk/ConfigModel.hpp"

#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include "ConfigModel.hpp"

#include <iostream>

int main(int argc, char *argv[])
  {
  QApplication a(argc, argv);
  QTreeView treeView;
  ConfigModel model;
  treeView.setModel(&model);
  treeView.show();
  return a.exec();
  }
