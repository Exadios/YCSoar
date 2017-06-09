/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2016 Peter F Bradshaw
  A detailed list of copyright holders can be found in the file "AUTHORS".

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
}
*/

#include <QTreeView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QItemSelectionModel>
#include "ConfigWindow.hpp"
#include "../../XCSoarThunk/ConfigModel.hpp"

//------------------------------------------------------------------------------
ConfigWindow::ConfigWindow()
  {
  this->model = new ConfigModel;
  this->view = new QTreeView;
  this->view->setModel(this->model);
  this->view->show();
  QItemSelectionModel *sm = this->view->selectionModel();
  connect(sm,
          SIGNAL(selectionChanged(const QItemSelection &,
                                  const QItemSelection &)),
          this,
          SLOT(selectionChangedSlot(const QItemSelection &,
                                    const QItemSelection &))
         );

  QGridLayout *editorLayout = new QGridLayout;
  editorLayout->addWidget(view, 0, 0);

  QPushButton *closeButton = new QPushButton(tr("Close"));
  connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
  QHBoxLayout *buttonsLayout = new QHBoxLayout;
  buttonsLayout->addStretch(1);
  buttonsLayout->addWidget(closeButton);
  
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(editorLayout);
  mainLayout->addStretch(1);
  mainLayout->addSpacing(12);
  mainLayout->addLayout(buttonsLayout);

  this->setLayout(mainLayout);
  this->setWindowTitle("Configuration");
  this->setSizeGripEnabled(true);
  }

//------------------------------------------------------------------------------
ConfigWindow::~ConfigWindow()
  {
  delete this->view;
  delete this->model;
  }

//------------------------------------------------------------------------------
void
ConfigWindow::selectionChangedSlot(const QItemSelection & /*newSelection*/,
                                   const QItemSelection & /*oldSelection*/)
  {
  //get the text of the selected item
  const QModelIndex index = this->view->selectionModel()->currentIndex();
  QString selectedText = index.data(Qt::DisplayRole).toString();
  //find out the hierarchy level of the selected item
  int hierarchyLevel=1;
  QModelIndex seekRoot = index;
  while(seekRoot.parent() != QModelIndex())
    {
    seekRoot = seekRoot.parent();
    hierarchyLevel++;
    }
  QString showString = QString("%1, Level %2").arg(selectedText).arg(hierarchyLevel);
  setWindowTitle(showString);
  }

