/*
Copyright_License {

  YCSoar Glide Computer.
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
#include <QLabel>
#include <QVBoxLayout>
#include <QListView>
#include <QPushButton>
#include <QFileDialog>

#include "TaskWizard.hpp"
#include "LocalPathThunk.hpp"
#include "Engine/Task/Ordered/OrderedTask.hpp"
#include "Engine/Waypoint/Waypoints.hpp"
#include "Terrain/RasterTerrain.hpp"
#include "Operation/VerboseOperationEnvironment.hpp"
#include "IO/FileCache.hpp"
#include "Task/DefaultTask.hpp"
#include "Waypoint/WaypointGlue.hpp"
#include "Interface.hpp"
#include "UIState.hpp"
#include "windef.h"

#include "ProfileThunk.hpp"

#include <iostream>

//------------------------------------------------------------------------------
TaskWizard::TaskWizard()
  {
  this->createFilePage();
  this->createRulesPage();
  this->createTurpointPage();
  this->createFinalPage();
  this->addPage(this->filePage);
  this->addPage(this->rulesPage);
  this->addPage(this->turpointPage);
  this->addPage(this->finalPage);
  this->setWindowTitle("Task Definition");
  }

//------------------------------------------------------------------------------
TaskWizard::~TaskWizard()
  {
  delete this->filePage;
  delete this->rulesPage;
  delete this->turpointPage;
  delete this->finalPage;
  }

//------------------------------------------------------------------------------
void
TaskWizard::browseOrNew()
  {
  LocalPathThunk *lp;
  lp = &LocalPathThunk::Instance();
  QFileDialog fileSelector(this,
                           "Task File",
                           QString(lp->primaryDataPath()) + QString("/tasks"),
                           "*.tsk;;*.*");
  fileSelector.setFileMode(QFileDialog::AnyFile);
  fileSelector.setViewMode(QFileDialog::Detail);
  if (fileSelector.exec())
    {
    QStringList names = fileSelector.selectedFiles();
    std::cerr << "Selected: " << names.at(0).toLocal8Bit().constData() << std::endl;
    }
  // \todo Return a filename.
  }

//------------------------------------------------------------------------------
void
TaskWizard::createFilePage()
  {
  this->filePage = new QWizardPage;
  this->filePage->setTitle("Task");
  QLabel *label = new QLabel("Select current or new task");
  label->setWordWrap(true);
  QPushButton *newTask = new QPushButton("New or Load");
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addWidget(label);
  layout->addWidget(newTask);
  connect(newTask, SIGNAL(clicked()), this, SLOT(browseOrNew()));

  CommonInterface::SetUISettings().SetDefaults();
  CommonInterface::SetSystemSettings().SetDefaults();
  CommonInterface::SetComputerSettings().SetDefaults();
  CommonInterface::SetUIState().Clear();
  LocalPathThunk *lp = &LocalPathThunk::Instance();
  FileCache *file_cache = new FileCache(lp->cacheDataPath());
  VerboseOperationEnvironment operation;
  RasterTerrain *terrain = RasterTerrain::OpenTerrain(file_cache, operation);
  Waypoints waypoints;
  WaypointGlue::LoadWaypoints(waypoints, terrain, operation);
  OrderedTask *defaultTask = LoadDefaultTask(CommonInterface::GetComputerSettings().task,
                                             &waypoints);
  defaultTask->CheckDuplicateWaypoints(waypoints);
  waypoints.Optimise();
  this->filePage->setLayout(layout);
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
//  ProfileThunk *ProfileThunk = &ProfileThunk::Instance();
  }

//------------------------------------------------------------------------------
void
TaskWizard::createTurpointPage()
  {
  this->turpointPage = new QWizardPage;
  this->turpointPage->setTitle("Turn Point");
  QVBoxLayout *layout = new QVBoxLayout;
  QListView *turnpointList = new QListView;
  layout->addWidget(turnpointList);
  this->turpointPage->setLayout(layout);
  }

//------------------------------------------------------------------------------
void
TaskWizard::createFinalPage()
  {
  this->finalPage = new QWizardPage;
  }

