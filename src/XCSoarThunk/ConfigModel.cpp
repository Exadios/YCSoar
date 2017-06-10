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
#include <QStandardItem>
#include <QString>

//------------------------------------------------------------------------------
ConfigModel::ConfigModel()
  {
  QStandardItem *rootNode = this->invisibleRootItem(); 

  QStandardItem *r1 = new QStandardItem("Site Files");
  r1->setToolTip("Site Files");
  rootNode->appendRow(r1);
    {
    QStandardItem *n1 = new QStandardItem("Map Database");
    QStandardItem *n2 = new QStandardItem("Waypoints");
    QStandardItem *n3 = new QStandardItem("Additional Waypoints");
    QStandardItem *n4 = new QStandardItem("Watched Waypoints");
    QStandardItem *n5 = new QStandardItem("Airspaces");
    QStandardItem *n6 = new QStandardItem("Additional Airspaces");
    QStandardItem *n7 = new QStandardItem("Waypoint Details");
    r1->appendRow(n1);
    r1->appendRow(n2);
    r1->appendRow(n3);
    r1->appendRow(n4);
    r1->appendRow(n5);
    r1->appendRow(n6);
    r1->appendRow(n7);
    }
  QStandardItem *r2 = new QStandardItem("Map Display");
  rootNode->appendRow(r2);
    {
    QStandardItem *i1 = new QStandardItem("Orientation");
    r2->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("Cruise");
      QStandardItem *n2 = new QStandardItem("Circling");
      QStandardItem *n3 = new QStandardItem("Circling Zoom");
      QStandardItem *n4 = new QStandardItem("Map Shift Reference");
      QStandardItem *n5 = new QStandardItem("Glider Position Offset");
      QStandardItem *n6 = new QStandardItem("Max Auto Zoom");
      QStandardItem *n7 = new QStandardItem("Distinct Page Zoom");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    QStandardItem *i2 = new QStandardItem("Elements");
    r2->appendRow(i2);
      {
      QStandardItem *n1 = new QStandardItem("Ground track");
      QStandardItem *n2 = new QStandardItem("FLARM traffic");
      QStandardItem *n3 = new QStandardItem("Trail length");
      QStandardItem *n4 = new QStandardItem("Trail drift");
      QStandardItem *n5 = new QStandardItem("Trail type");
      QStandardItem *n6 = new QStandardItem("Trail scaled");
      QStandardItem *n7 = new QStandardItem("Detour cost markers");
      QStandardItem *n8 = new QStandardItem("Aircraft symbol");
      QStandardItem *n9 = new QStandardItem("Wind arrow");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      i2->appendRow(n7);
      i2->appendRow(n8);
      i2->appendRow(n9);
      }
    QStandardItem *i3 = new QStandardItem("Waypoints");
    r2->appendRow(i3);
      {
      QStandardItem *n1 = new QStandardItem("Label format");
      QStandardItem *n2 = new QStandardItem("Label style");
      QStandardItem *n3 = new QStandardItem("Label visibilty");
      QStandardItem *n4 = new QStandardItem("Arrival height");
      QStandardItem *n5 = new QStandardItem("Landable symbols");
      QStandardItem *n6 = new QStandardItem("Detailed landables");
      QStandardItem *n7 = new QStandardItem("Landable size");
      QStandardItem *n8 = new QStandardItem("Scale runway length");
      i3->appendRow(n1);
      i3->appendRow(n2);
      i3->appendRow(n3);
      i3->appendRow(n4);
      i3->appendRow(n5);
      i3->appendRow(n6);
      i3->appendRow(n7);
      i3->appendRow(n8);
      }
    QStandardItem *i4 = new QStandardItem("Terrain");
    r2->appendRow(i4);
      {
      QStandardItem *n1 = new QStandardItem("Terrain display");
      QStandardItem *n2 = new QStandardItem("Topography display");
      i4->appendRow(n1);
      i4->appendRow(n2);
      }
    QStandardItem *i5 = new QStandardItem("Airspace");
    r2->appendRow(i5);
      {
      QStandardItem *n1 = new QStandardItem("Airspace display");
      QStandardItem *n2 = new QStandardItem("Label visibility");
      QStandardItem *n3 = new QStandardItem("Warnings");
      QStandardItem *n4 = new QStandardItem("Warnings dialog");
      QStandardItem *n5 = new QStandardItem("Warning time");
      QStandardItem *n6 = new QStandardItem("Repetitive sound");
      QStandardItem *n7 = new QStandardItem("Acknowledge time");
      QStandardItem *n8 = new QStandardItem("Use black outline");
      QStandardItem *n9 = new QStandardItem("Airspace fill node");
      i5->appendRow(n1);
      i5->appendRow(n2);
      i5->appendRow(n3);
      i5->appendRow(n4);
      i5->appendRow(n5);
      i5->appendRow(n6);
      i5->appendRow(n7);
      i5->appendRow(n8);
      i5->appendRow(n9);
      }
    }
  QStandardItem *r3 = new QStandardItem("Glide Computer");
  rootNode->appendRow(r3);
    {
    QStandardItem *i1 = new QStandardItem("Safety Factors");
    r3->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("Arrival height");
      QStandardItem *n2 = new QStandardItem("Terrain height");
      QStandardItem *n3 = new QStandardItem("Alternates mode");
      QStandardItem *n4 = new QStandardItem("Polar degradation");
      QStandardItem *n5 = new QStandardItem("Auto bugs");
      QStandardItem *n6 = new QStandardItem("Safety MC");
      QStandardItem *n7 = new QStandardItem("STF risk factor");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    QStandardItem *i2 = new QStandardItem("Glide Computer");
    r3->appendRow(i2);
      {
      QStandardItem *n1 = new QStandardItem("Auto MC mode");
      QStandardItem *n2 = new QStandardItem("Block soeed to fly");
      QStandardItem *n3 = new QStandardItem("Nav. by baro altitude");
      QStandardItem *n4 = new QStandardItem("Flaps forces cruise");
      QStandardItem *n5 = new QStandardItem("GR average period");
      QStandardItem *n6 = new QStandardItem("Predict wind drift");
      QStandardItem *n7 = new QStandardItem("Wave assistant");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      }
    QStandardItem *i3 = new QStandardItem("Wind");
    r3->appendRow(i3);
      {
      QStandardItem *n1 = new QStandardItem("Auto wind");
      QStandardItem *n2 = new QStandardItem("External wind");
      i3->appendRow(n1);
      i3->appendRow(n2);
      }
    QStandardItem *i4 = new QStandardItem("Route");
    r3->appendRow(i4);
      {
      QStandardItem *n1 = new QStandardItem("Route mode");
      QStandardItem *n2 = new QStandardItem("Route climb");
      QStandardItem *n3 = new QStandardItem("Route ceiling");
      i4->appendRow(n1);
      i4->appendRow(n2);
      i4->appendRow(n3);
      }
    QStandardItem *i5 = new QStandardItem("Reach");
    r3->appendRow(i5);
      {
      QStandardItem *n1 = new QStandardItem("Reach mode");
      QStandardItem *n2 = new QStandardItem("Reach polar");
      QStandardItem *n3 = new QStandardItem("Reach display");
      i5->appendRow(n1);
      i5->appendRow(n2);
      i5->appendRow(n3);
      }
    QStandardItem *i6 = new QStandardItem("Scoring");
    r3->appendRow(i6);
      {
      QStandardItem *n1 = new QStandardItem("On-Line Contest");
      QStandardItem *n2 = new QStandardItem("Predict contest");
      QStandardItem *n3 = new QStandardItem("FAI triangle areas");
      i6->appendRow(n1);
      i6->appendRow(n2);
      i6->appendRow(n3);
      }
    }
  QStandardItem *r4 = new QStandardItem("Gauges");
  rootNode->appendRow(r4);
    {
    QStandardItem *i1 = new QStandardItem("FLARM and Other");
    r4->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("FLARM radar");
      QStandardItem *n2 = new QStandardItem("Auto close FLARM");
      QStandardItem *n3 = new QStandardItem("Thermal assitant");
      QStandardItem *n4 = new QStandardItem("Thermal band");
      QStandardItem *n5 = new QStandardItem("Final glide bar");
      QStandardItem *n6 = new QStandardItem("Final glide bar MC0");
      QStandardItem *n7 = new QStandardItem("Vario bar");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    QStandardItem *i2 = new QStandardItem("Vario");
    r4->appendRow(i2);
      {
      QStandardItem *n1 = new QStandardItem("Speed arrows");
      QStandardItem *n2 = new QStandardItem("Show average");
      QStandardItem *n3 = new QStandardItem("Show MacReady");
      QStandardItem *n4 = new QStandardItem("Show bugs");
      QStandardItem *n5 = new QStandardItem("Show ballast");
      QStandardItem *n6 = new QStandardItem("Show gross");
      QStandardItem *n7 = new QStandardItem("Averager needle");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      }
    QStandardItem *i3 = new QStandardItem("Audio");
    r4->appendRow(i3);
      {
      QStandardItem *n1 = new QStandardItem("Audio vario");
      QStandardItem *n2 = new QStandardItem("Volume");
      QStandardItem *n3 = new QStandardItem("Enable deadband");
      QStandardItem *n4 = new QStandardItem("Min. frequency");
      QStandardItem *n5 = new QStandardItem("Zero frequency");
      QStandardItem *n6 = new QStandardItem("Max. frequency");
      QStandardItem *n7 = new QStandardItem("Deadband min. lift");
      QStandardItem *n8 = new QStandardItem("Deadband max. lift");
      i3->appendRow(n1);
      i3->appendRow(n2);
      i3->appendRow(n3);
      i3->appendRow(n4);
      i3->appendRow(n5);
      i3->appendRow(n6);
      i3->appendRow(n7);
      i3->appendRow(n8);
      }
    }
  QStandardItem *r5 = new QStandardItem("Task Defaults");
  rootNode->appendRow(r5);
    {
    QStandardItem *i1 = new QStandardItem("Rules");
    r5->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("Start max. speed");
      QStandardItem *n2 = new QStandardItem("Start max. speed margin");
      QStandardItem *n3 = new QStandardItem("Start max. height");
      QStandardItem *n4 = new QStandardItem("Start max. height margin");
      QStandardItem *n5 = new QStandardItem("Start height ref.");
      QStandardItem *n6 = new QStandardItem("Finish min. height");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      }
    QStandardItem *i2 = new QStandardItem("Turnpoint Types");
    r5->appendRow(i2);
      {
      QStandardItem *n1 = new QStandardItem("Start line");
      QStandardItem *n2 = new QStandardItem("Gate width");
      QStandardItem *n3 = new QStandardItem("Finish point");
      QStandardItem *n4 = new QStandardItem("Radius");
      QStandardItem *n5 = new QStandardItem("Turn point");
      QStandardItem *n6 = new QStandardItem("Radius");
      QStandardItem *n7 = new QStandardItem("Task");
      QStandardItem *n8 = new QStandardItem("AAT min. time");
      QStandardItem *n9 = new QStandardItem("Optimization margin");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      i2->appendRow(n8);
      i2->appendRow(n9);
      }
    }
  QStandardItem *r6 = new QStandardItem("Look");
  rootNode->appendRow(r6);
    {
    QStandardItem *i1 = new QStandardItem("Language and Input");
    r6->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("Text size");
      QStandardItem *n2 = new QStandardItem("Events");
      QStandardItem *n3 = new QStandardItem("Language");
      QStandardItem *n4 = new QStandardItem("Menu timeout");
      QStandardItem *n5 = new QStandardItem("Text input style");
      QStandardItem *n6 = new QStandardItem("Haptic feedback");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      }
    QStandardItem *i2 = new QStandardItem("Screen");
    r6->appendRow(i2);
      {
      QStandardItem *n1 = new QStandardItem("Display orientation");
      QStandardItem *n2 = new QStandardItem("Infobox geometry");
      QStandardItem *n3 = new QStandardItem("FLARM display");
      QStandardItem *n4 = new QStandardItem("Tab dialog style");
      QStandardItem *n5 = new QStandardItem("Message display");
      QStandardItem *n6 = new QStandardItem("Inverse infoboxes");
      QStandardItem *n7 = new QStandardItem("Colored infoboxes");
      QStandardItem *n8 = new QStandardItem("Infobox border");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      i2->appendRow(n8);
      }
    QStandardItem *i3 = new QStandardItem("Pages");
    r6->appendRow(i3);
      {
      // \todo Implement 8 infobox selections.
      }
    QStandardItem *i4 = new QStandardItem("Infobox Sets");
    r6->appendRow(i4);
      {
      // \todo Implement 8 page selections.
      }
    }
  QStandardItem *r7 = new QStandardItem("General");
  rootNode->appendRow(r7);
    {
    QStandardItem *i1 = new QStandardItem("Logger");
    r7->appendRow(i1);
      {
      QStandardItem *n1 = new QStandardItem("Pilot name");
      QStandardItem *n2 = new QStandardItem("Time step cruise");
      QStandardItem *n3 = new QStandardItem("Time step circling");
      QStandardItem *n4 = new QStandardItem("Auto logger");
      QStandardItem *n5 = new QStandardItem("NMEA logger");
      QStandardItem *n6 = new QStandardItem("Log book");
      QStandardItem *n7 = new QStandardItem("Logger ID");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    QStandardItem *i2 = new QStandardItem("Units");
    r7->appendRow(i2);
      {
      QStandardItem *n1  = new QStandardItem("Preset");
      QStandardItem *n2  = new QStandardItem("Aircraft/Wind speed");
      QStandardItem *n3  = new QStandardItem("Distance");
      QStandardItem *n4  = new QStandardItem("Lift");
      QStandardItem *n5  = new QStandardItem("Altitude");
      QStandardItem *n6  = new QStandardItem("Temperature");
      QStandardItem *n7  = new QStandardItem("Task speed");
      QStandardItem *n8  = new QStandardItem("Pressure");
      QStandardItem *n9  = new QStandardItem("Mass");
      QStandardItem *n10 = new QStandardItem("Wing loading");
      QStandardItem *n11 = new QStandardItem("Lat/Lon");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      i2->appendRow(n8);
      i2->appendRow(n9);
      i2->appendRow(n10);
      i2->appendRow(n11);
      }
    QStandardItem *i3 = new QStandardItem("Time");
    r7->appendRow(i3);
      {
      QStandardItem *n1 = new QStandardItem("UTC offset");
      QStandardItem *n2 = new QStandardItem("Use GPS time");
      i3->appendRow(n1);
      i3->appendRow(n2);
      }
    QStandardItem *i4 = new QStandardItem("Tracking");
    r7->appendRow(i4);
      {
      QStandardItem *n1 = new QStandardItem("Skylines");
      QStandardItem *n2 = new QStandardItem("Roaming");
      QStandardItem *n3 = new QStandardItem("Tracking interval");
      QStandardItem *n4 = new QStandardItem("Track friends");
      QStandardItem *n5 = new QStandardItem("Show nearby traffic"); // 6.8.2?
      QStandardItem *n6 = new QStandardItem("Key");
      QStandardItem *n7 = new QStandardItem("XCSoar Cloud");  // 6.8.2?
      i4->appendRow(n1);
      i4->appendRow(n2);
      i4->appendRow(n3);
      i4->appendRow(n4);
      i4->appendRow(n5);
      i4->appendRow(n6);
      i4->appendRow(n7);
      }
    }
  }

//------------------------------------------------------------------------------
ConfigModel::~ConfigModel()
  {
  }

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

//------------------------------------------------------------------------------
QVariant
ConfigModel::data(const QModelIndex &index, int role) const
  {
  if (role == Qt::DisplayRole)
    {
    return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() +
                                                               1);
    }
  return QVariant(QVariant::Invalid); // Invalid.
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
