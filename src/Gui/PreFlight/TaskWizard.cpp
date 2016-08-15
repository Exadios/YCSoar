/*
Copyright_License {

  G-Meter INU.
  Copyright (C) 2013-2015 Peter F Bradshaw
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

#include <QWidget>
#include <QWizard>
#include <QLabel>
#include <QVBoxLayout>

#include "TaskWizard.hpp"

//------------------------------------------------------------------------------
TaskWizard::TaskWizard()
  {
  this->createRulesPage();
  this->createTurpointPage();
  this->createFinalPage();
  }

//------------------------------------------------------------------------------
TaskWizard::~TaskWizard()
  {
  delete this->rulesPage;
  delete this->turpointPage;
  delete this->finalPage;
  }

//------------------------------------------------------------------------------
void
TaskWizard::createRulesPage()
  {
  this->rulesPage = new QWizardPage;
  this->rulesPage->setTitle("Task Rules");
  QLabel *label = new QLabel("Create or edit a task");
  label->setWordWrap(true);
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  this->rulesPage->setLayout(layout);
  }

//------------------------------------------------------------------------------
void
TaskWizard::createTurpointPage()
  {
  }

//------------------------------------------------------------------------------
void
TaskWizard::createFinalPage()
  {
  }

