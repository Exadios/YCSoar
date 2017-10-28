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

#include "ConfigModel.hpp"
#include "Computer/Settings.hpp"
#include "SystemFilesEditor.hpp"
#include <QStandardItem>
#include <QString>

#include <iostream>

//------------------------------------------------------------------------------
ConfigModel::ConfigModel()
  {
  QStandardItem *rootNode = this->invisibleRootItem(); 

  ConfigItem *r1 = new ConfigItem("Site Files", ConfigModel::SYSTEMFILES);
  rootNode->appendRow(r1);
  ConfigItem *r2 = new ConfigItem("Map Display", ConfigModel::NONE, false);
  rootNode->appendRow(r2);
    {
    ConfigItem *i1 = new ConfigItem("Orientation", ConfigModel::ORIENTATION);
    r2->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Elements", ConfigModel::ELEMENTS);
    r2->appendRow(i2);
    ConfigItem *i3 = new ConfigItem("Waypoints", ConfigModel::WAYPOINTS);
    r2->appendRow(i3);
    ConfigItem *i4 = new ConfigItem("Terrain", ConfigModel::TERRAIN);
    r2->appendRow(i4);
    ConfigItem *i5 = new ConfigItem("Airspace", ConfigModel::AIRSPACE);
    r2->appendRow(i5);
    }
  ConfigItem *r3 = new ConfigItem("Glide Computer",
                                  ConfigModel::NONE,
                                  false);
  rootNode->appendRow(r3);
    {
    ConfigItem *i1 = new ConfigItem("Safety Factors",
                                    ConfigModel::SAFTEYFACTORS);
    r3->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Glide Computer",
                                    ConfigModel::GLIDECOMPUTER);
    r3->appendRow(i2);
    ConfigItem *i3 = new ConfigItem("Wind", ConfigModel::WIND);
    r3->appendRow(i3);
    ConfigItem *i4 = new ConfigItem("Route", ConfigModel::ROUTE);
    r3->appendRow(i4);
    ConfigItem *i5 = new ConfigItem("Reach", ConfigModel::REACH);
    r3->appendRow(i5);
    ConfigItem *i6 = new ConfigItem("Scoring", ConfigModel::SCORING);
    r3->appendRow(i6);
    }
  ConfigItem *r4 = new ConfigItem("Gauges", ConfigModel::NONE, false);
  rootNode->appendRow(r4);
    {
    ConfigItem *i1 = new ConfigItem("FLARM and Other",
                                    ConfigModel::DECORATIONS);
    r4->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Vario", ConfigModel::VARIO);
    r4->appendRow(i2);
    ConfigItem *i3 = new ConfigItem("Audio", ConfigModel::AUDIO);
    r4->appendRow(i3);
    }
  ConfigItem *r5 = new ConfigItem("Task Defaults",
                                  ConfigModel::NONE,
                                  false);
  rootNode->appendRow(r5);
    {
    ConfigItem *i1 = new ConfigItem("Rules", ConfigModel::RULES);
    r5->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Turnpoint Types",
                                    ConfigModel::TURNPOINTTYPES);
    r5->appendRow(i2);
    }
  ConfigItem *r6 = new ConfigItem("Look", ConfigModel::NONE, false);
  rootNode->appendRow(r6);
    {
    ConfigItem *i1 = new ConfigItem("Language and Input",
                                    ConfigModel::INPUT);
    r6->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Screen", ConfigModel::LAYOUT);
    r6->appendRow(i2);
    ConfigItem *i3 = new ConfigItem("Pages", ConfigModel::PAGES);
    r6->appendRow(i3);
      {
      // \todo Implement 8 infobox selections.
      }
    ConfigItem *i4 = new ConfigItem("Infobox Sets", ConfigModel::SETNAMES);
    r6->appendRow(i4);
      {
      // \todo Implement 8 page selections.
      }
    }
  ConfigItem *r7 = new ConfigItem("General", ConfigModel::NONE, false);
  rootNode->appendRow(r7);
    {
    ConfigItem *i1 = new ConfigItem("Logger", ConfigModel::LOGGER);
    r7->appendRow(i1);
    ConfigItem *i2 = new ConfigItem("Units", ConfigModel::UNITS);
    r7->appendRow(i2);
    ConfigItem *i3 = new ConfigItem("Time", ConfigModel::TIME);
    r7->appendRow(i3);
    ConfigItem *i4 = new ConfigItem("Tracking", ConfigModel::TRACKING);
    r7->appendRow(i4);
    }
  }

//------------------------------------------------------------------------------
ConfigModel::~ConfigModel()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Action(ConfigModel::ActionIndex what)
  {
  switch (what)
    {
    case ConfigModel::SYSTEMFILES:
      this->SystemFiles();
      break;
    case ConfigModel::ORIENTATION:
      this->Orientation();
      break;
    case ConfigModel::ELEMENTS:
      this->Elements();
      break;
    case ConfigModel::WAYPOINTS:
      this->Waypoints();
      break;
    case ConfigModel::TERRAIN:
      this->Terrain();
      break;
    case ConfigModel::AIRSPACE:
      this->Airspace();
      break;
    case ConfigModel::SAFTEYFACTORS:
      this->SafteyFactors();
      break;
    case ConfigModel::GLIDECOMPUTER:
      this->GlideComputer();
      break;
    case ConfigModel::WIND:
      this->Wind();
      break;
    case ConfigModel::ROUTE:
      this->Route();
      break;
    case ConfigModel::REACH:
      this->Reach();
      break;
    case ConfigModel::SCORING:
      this->Scoring();
      break;
    case ConfigModel::DECORATIONS:
      this->Decorations();
      break;
    case ConfigModel::VARIO:
      this->Vario();
      break;
    case ConfigModel::AUDIO:
      this->Audio();
      break;
    case ConfigModel::RULES:
      this->Rules();
      break;
    case ConfigModel::TURNPOINTTYPES:
      this->TurnpointTypes();
      break;
    case ConfigModel::INPUT:
      this->Input();
      break;
    case ConfigModel::LAYOUT:
      this->Layout();
      break;
    case ConfigModel::PAGES:
      this->Pages();
      break;
    case ConfigModel::SETNAMES:
      this->SetNames();
      break;
    case ConfigModel::LOGGER:
      this->Logger();
      break;
    case ConfigModel::UNITS:
      this->Units();
      break;
    case ConfigModel::TIME:
      this->Time();
      break;
    case ConfigModel::TRACKING:
      this->Tracking();
      break;
    case ConfigModel::ActionIndexEnd:
    case ConfigModel::NONE:
    default:
      break;
    }
  }

#if 0
//------------------------------------------------------------------------------
WindSettings &
ConfigModel::Wind()
  {
  return this->computer.wind;
  }

//------------------------------------------------------------------------------
AirspaceComputerSettings &
ConfigModel::Airspace()
  {
  return this->computer.airspace;
  }

//------------------------------------------------------------------------------
TaskBehaviour &
ConfigModel::Task()
  {
  return this->computer.task;
  }

//------------------------------------------------------------------------------
LoggerSettings &
ConfigModel::Logger()
  {
  return this->computer.logger;
  }
#endif

//------------------------------------------------------------------------------
void
ConfigModel::SystemFiles()
  {
  std::cout << "ConfigModel::SystemFiles" << std::endl;
#if 0
  SystemFilesEditor *s = new SystemFilesEditor;
  s->exec();
#else
  SystemFilesEditor s;
  s.exec();
#endif
  }

//------------------------------------------------------------------------------
void
ConfigModel::Orientation()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Elements()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Waypoints()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Terrain()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Airspace()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::AirspaceFilter()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::AirspaceColors()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::SafteyFactors()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::GlideComputer()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Wind()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Route()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Reach()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Scoring()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Decorations()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Vario()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Audio()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Rules()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::TurnpointTypes()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Input()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Layout()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Pages()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::SetNames()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Set()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Logger()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Units()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Time()
  {
  }

//------------------------------------------------------------------------------
void
ConfigModel::Tracking()
  {
  }
   
//------------------------------------------------------------------------------
void
ConfigModel::None()
  {
  }

//------------------------------------------------------------------------------
ConfigItem::ConfigItem(QString text,
                       ConfigModel::ActionIndex dispatch,
                       bool selectable)
  : QStandardItem(text),
    what(dispatch)
  {
  this->setEditable(false);
  this->setSelectable(selectable);
  }

//------------------------------------------------------------------------------
QVariant
ConfigItem::data(int role) const
  {
  if (role < Qt::UserRole)
    return QStandardItem::data(role);
  if (role == ConfigItem::DispatchIndex)
    return int(this->what);
  return QVariant();
  }
  
#include <QStringList>

//------------------------------------------------------------------------------
TreeItem::TreeItem(const QList<QVariant> &data, TreeItem *parent)
  {
  this->parent_item = parent;
  this->item_data = data;
  }

//------------------------------------------------------------------------------
TreeItem::~TreeItem()
  {
  qDeleteAll(this->child_items);
  }

//------------------------------------------------------------------------------
void
TreeItem::appendChild(TreeItem *item)
  {
  this->child_items.append(item);
  }

//------------------------------------------------------------------------------
TreeItem *
TreeItem::child(int row)
  {
  return this->child_items.value(row);
  }

//------------------------------------------------------------------------------
int
TreeItem::childCount() const
  {
  return this->child_items.count();
  }

//------------------------------------------------------------------------------
int
TreeItem::columnCount() const
  {
  return this->item_data.count();
  }

//------------------------------------------------------------------------------
QVariant
TreeItem::data(int column) const
  {
  return this->item_data.value(column);
  }

//------------------------------------------------------------------------------
TreeItem *
TreeItem::parentItem()
  {
  return this->parent_item;
  }

//------------------------------------------------------------------------------
int
TreeItem::row() const
  {
  if (this->parent_item)
    return this->parent_item->child_items.indexOf(const_cast<TreeItem*>(this));

  return 0;
  }
