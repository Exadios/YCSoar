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

  ConfigItem *r1 = new ConfigItem("Site Files");
  r1->setToolTip("Site Files");
  rootNode->appendRow(r1);
    {
    ConfigItem *n1 = new ConfigItem("Map Database");
    ConfigItem *n2 = new ConfigItem("Waypoints");
    ConfigItem *n3 = new ConfigItem("Additional Waypoints");
    ConfigItem *n4 = new ConfigItem("Watched Waypoints");
    ConfigItem *n5 = new ConfigItem("Airspaces");
    ConfigItem *n6 = new ConfigItem("Additional Airspaces");
    ConfigItem *n7 = new ConfigItem("Waypoint Details");
    r1->appendRow(n1);
    r1->appendRow(n2);
    r1->appendRow(n3);
    r1->appendRow(n4);
    r1->appendRow(n5);
    r1->appendRow(n6);
    r1->appendRow(n7);
    }
  ConfigItem *r2 = new ConfigItem("Map Display");
  rootNode->appendRow(r2);
    {
    ConfigItem *i1 = new ConfigItem("Orientation");
    r2->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("Cruise");
      ConfigItem *n2 = new ConfigItem("Circling");
      ConfigItem *n3 = new ConfigItem("Circling Zoom");
      ConfigItem *n4 = new ConfigItem("Map Shift Reference");
      ConfigItem *n5 = new ConfigItem("Glider Position Offset");
      ConfigItem *n6 = new ConfigItem("Max Auto Zoom");
      ConfigItem *n7 = new ConfigItem("Distinct Page Zoom");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    ConfigItem *i2 = new ConfigItem("Elements");
    r2->appendRow(i2);
      {
      ConfigItem *n1 = new ConfigItem("Ground track");
      ConfigItem *n2 = new ConfigItem("FLARM traffic");
      ConfigItem *n3 = new ConfigItem("Trail length");
      ConfigItem *n4 = new ConfigItem("Trail drift");
      ConfigItem *n5 = new ConfigItem("Trail type");
      ConfigItem *n6 = new ConfigItem("Trail scaled");
      ConfigItem *n7 = new ConfigItem("Detour cost markers");
      ConfigItem *n8 = new ConfigItem("Aircraft symbol");
      ConfigItem *n9 = new ConfigItem("Wind arrow");
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
    ConfigItem *i3 = new ConfigItem("Waypoints");
    r2->appendRow(i3);
      {
      ConfigItem *n1 = new ConfigItem("Label format");
      ConfigItem *n2 = new ConfigItem("Label style");
      ConfigItem *n3 = new ConfigItem("Label visibilty");
      ConfigItem *n4 = new ConfigItem("Arrival height");
      ConfigItem *n5 = new ConfigItem("Landable symbols");
      ConfigItem *n6 = new ConfigItem("Detailed landables");
      ConfigItem *n7 = new ConfigItem("Landable size");
      ConfigItem *n8 = new ConfigItem("Scale runway length");
      i3->appendRow(n1);
      i3->appendRow(n2);
      i3->appendRow(n3);
      i3->appendRow(n4);
      i3->appendRow(n5);
      i3->appendRow(n6);
      i3->appendRow(n7);
      i3->appendRow(n8);
      }
    ConfigItem *i4 = new ConfigItem("Terrain");
    r2->appendRow(i4);
      {
      ConfigItem *n1 = new ConfigItem("Terrain display");
      ConfigItem *n2 = new ConfigItem("Topography display");
      i4->appendRow(n1);
      i4->appendRow(n2);
      }
    ConfigItem *i5 = new ConfigItem("Airspace");
    r2->appendRow(i5);
      {
      ConfigItem *n1 = new ConfigItem("Airspace display");
      ConfigItem *n2 = new ConfigItem("Label visibility");
      ConfigItem *n3 = new ConfigItem("Warnings");
      ConfigItem *n4 = new ConfigItem("Warnings dialog");
      ConfigItem *n5 = new ConfigItem("Warning time");
      ConfigItem *n6 = new ConfigItem("Repetitive sound");
      ConfigItem *n7 = new ConfigItem("Acknowledge time");
      ConfigItem *n8 = new ConfigItem("Use black outline");
      ConfigItem *n9 = new ConfigItem("Airspace fill node");
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
  ConfigItem *r3 = new ConfigItem("Glide Computer");
  rootNode->appendRow(r3);
    {
    ConfigItem *i1 = new ConfigItem("Safety Factors");
    r3->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("Arrival height");
      ConfigItem *n2 = new ConfigItem("Terrain height");
      ConfigItem *n3 = new ConfigItem("Alternates mode");
      ConfigItem *n4 = new ConfigItem("Polar degradation");
      ConfigItem *n5 = new ConfigItem("Auto bugs");
      ConfigItem *n6 = new ConfigItem("Safety MC");
      ConfigItem *n7 = new ConfigItem("STF risk factor");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    ConfigItem *i2 = new ConfigItem("Glide Computer");
    r3->appendRow(i2);
      {
      ConfigItem *n1 = new ConfigItem("Auto MC mode");
      ConfigItem *n2 = new ConfigItem("Block soeed to fly");
      ConfigItem *n3 = new ConfigItem("Nav. by baro altitude");
      ConfigItem *n4 = new ConfigItem("Flaps forces cruise");
      ConfigItem *n5 = new ConfigItem("GR average period");
      ConfigItem *n6 = new ConfigItem("Predict wind drift");
      ConfigItem *n7 = new ConfigItem("Wave assistant");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      }
    ConfigItem *i3 = new ConfigItem("Wind");
    r3->appendRow(i3);
      {
      ConfigItem *n1 = new ConfigItem("Auto wind");
      ConfigItem *n2 = new ConfigItem("External wind");
      i3->appendRow(n1);
      i3->appendRow(n2);
      }
    ConfigItem *i4 = new ConfigItem("Route");
    r3->appendRow(i4);
      {
      ConfigItem *n1 = new ConfigItem("Route mode");
      ConfigItem *n2 = new ConfigItem("Route climb");
      ConfigItem *n3 = new ConfigItem("Route ceiling");
      i4->appendRow(n1);
      i4->appendRow(n2);
      i4->appendRow(n3);
      }
    ConfigItem *i5 = new ConfigItem("Reach");
    r3->appendRow(i5);
      {
      ConfigItem *n1 = new ConfigItem("Reach mode");
      ConfigItem *n2 = new ConfigItem("Reach polar");
      ConfigItem *n3 = new ConfigItem("Reach display");
      i5->appendRow(n1);
      i5->appendRow(n2);
      i5->appendRow(n3);
      }
    ConfigItem *i6 = new ConfigItem("Scoring");
    r3->appendRow(i6);
      {
      ConfigItem *n1 = new ConfigItem("On-Line Contest");
      ConfigItem *n2 = new ConfigItem("Predict contest");
      ConfigItem *n3 = new ConfigItem("FAI triangle areas");
      i6->appendRow(n1);
      i6->appendRow(n2);
      i6->appendRow(n3);
      }
    }
  ConfigItem *r4 = new ConfigItem("Gauges");
  rootNode->appendRow(r4);
    {
    ConfigItem *i1 = new ConfigItem("FLARM and Other");
    r4->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("FLARM radar");
      ConfigItem *n2 = new ConfigItem("Auto close FLARM");
      ConfigItem *n3 = new ConfigItem("Thermal assitant");
      ConfigItem *n4 = new ConfigItem("Thermal band");
      ConfigItem *n5 = new ConfigItem("Final glide bar");
      ConfigItem *n6 = new ConfigItem("Final glide bar MC0");
      ConfigItem *n7 = new ConfigItem("Vario bar");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    ConfigItem *i2 = new ConfigItem("Vario");
    r4->appendRow(i2);
      {
      ConfigItem *n1 = new ConfigItem("Speed arrows");
      ConfigItem *n2 = new ConfigItem("Show average");
      ConfigItem *n3 = new ConfigItem("Show MacReady");
      ConfigItem *n4 = new ConfigItem("Show bugs");
      ConfigItem *n5 = new ConfigItem("Show ballast");
      ConfigItem *n6 = new ConfigItem("Show gross");
      ConfigItem *n7 = new ConfigItem("Averager needle");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      }
    ConfigItem *i3 = new ConfigItem("Audio");
    r4->appendRow(i3);
      {
      ConfigItem *n1 = new ConfigItem("Audio vario");
      ConfigItem *n2 = new ConfigItem("Volume");
      ConfigItem *n3 = new ConfigItem("Enable deadband");
      ConfigItem *n4 = new ConfigItem("Min. frequency");
      ConfigItem *n5 = new ConfigItem("Zero frequency");
      ConfigItem *n6 = new ConfigItem("Max. frequency");
      ConfigItem *n7 = new ConfigItem("Deadband min. lift");
      ConfigItem *n8 = new ConfigItem("Deadband max. lift");
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
  ConfigItem *r5 = new ConfigItem("Task Defaults");
  rootNode->appendRow(r5);
    {
    ConfigItem *i1 = new ConfigItem("Rules");
    r5->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("Start max. speed");
      ConfigItem *n2 = new ConfigItem("Start max. speed margin");
      ConfigItem *n3 = new ConfigItem("Start max. height");
      ConfigItem *n4 = new ConfigItem("Start max. height margin");
      ConfigItem *n5 = new ConfigItem("Start height ref.");
      ConfigItem *n6 = new ConfigItem("Finish min. height");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      }
    ConfigItem *i2 = new ConfigItem("Turnpoint Types");
    r5->appendRow(i2);
      {
      ConfigItem *n1 = new ConfigItem("Start line");
      ConfigItem *n2 = new ConfigItem("Gate width");
      ConfigItem *n3 = new ConfigItem("Finish point");
      ConfigItem *n4 = new ConfigItem("Radius");
      ConfigItem *n5 = new ConfigItem("Turn point");
      ConfigItem *n6 = new ConfigItem("Radius");
      ConfigItem *n7 = new ConfigItem("Task");
      ConfigItem *n8 = new ConfigItem("AAT min. time");
      ConfigItem *n9 = new ConfigItem("Optimization margin");
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
  ConfigItem *r6 = new ConfigItem("Look");
  rootNode->appendRow(r6);
    {
    ConfigItem *i1 = new ConfigItem("Language and Input");
    r6->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("Text size");
      ConfigItem *n2 = new ConfigItem("Events");
      ConfigItem *n3 = new ConfigItem("Language");
      ConfigItem *n4 = new ConfigItem("Menu timeout");
      ConfigItem *n5 = new ConfigItem("Text input style");
      ConfigItem *n6 = new ConfigItem("Haptic feedback");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      }
    ConfigItem *i2 = new ConfigItem("Screen");
    r6->appendRow(i2);
      {
      ConfigItem *n1 = new ConfigItem("Display orientation");
      ConfigItem *n2 = new ConfigItem("Infobox geometry");
      ConfigItem *n3 = new ConfigItem("FLARM display");
      ConfigItem *n4 = new ConfigItem("Tab dialog style");
      ConfigItem *n5 = new ConfigItem("Message display");
      ConfigItem *n6 = new ConfigItem("Inverse infoboxes");
      ConfigItem *n7 = new ConfigItem("Colored infoboxes");
      ConfigItem *n8 = new ConfigItem("Infobox border");
      i2->appendRow(n1);
      i2->appendRow(n2);
      i2->appendRow(n3);
      i2->appendRow(n4);
      i2->appendRow(n5);
      i2->appendRow(n6);
      i2->appendRow(n7);
      i2->appendRow(n8);
      }
    ConfigItem *i3 = new ConfigItem("Pages");
    r6->appendRow(i3);
      {
      // \todo Implement 8 infobox selections.
      }
    ConfigItem *i4 = new ConfigItem("Infobox Sets");
    r6->appendRow(i4);
      {
      // \todo Implement 8 page selections.
      }
    }
  ConfigItem *r7 = new ConfigItem("General");
  rootNode->appendRow(r7);
    {
    ConfigItem *i1 = new ConfigItem("Logger");
    r7->appendRow(i1);
      {
      ConfigItem *n1 = new ConfigItem("Pilot name");
      ConfigItem *n2 = new ConfigItem("Time step cruise");
      ConfigItem *n3 = new ConfigItem("Time step circling");
      ConfigItem *n4 = new ConfigItem("Auto logger");
      ConfigItem *n5 = new ConfigItem("NMEA logger");
      ConfigItem *n6 = new ConfigItem("Log book");
      ConfigItem *n7 = new ConfigItem("Logger ID");
      i1->appendRow(n1);
      i1->appendRow(n2);
      i1->appendRow(n3);
      i1->appendRow(n4);
      i1->appendRow(n5);
      i1->appendRow(n6);
      i1->appendRow(n7);
      }
    ConfigItem *i2 = new ConfigItem("Units");
    r7->appendRow(i2);
      {
      ConfigItem *n1  = new ConfigItem("Preset");
      ConfigItem *n2  = new ConfigItem("Aircraft/Wind speed");
      ConfigItem *n3  = new ConfigItem("Distance");
      ConfigItem *n4  = new ConfigItem("Lift");
      ConfigItem *n5  = new ConfigItem("Altitude");
      ConfigItem *n6  = new ConfigItem("Temperature");
      ConfigItem *n7  = new ConfigItem("Task speed");
      ConfigItem *n8  = new ConfigItem("Pressure");
      ConfigItem *n9  = new ConfigItem("Mass");
      ConfigItem *n10 = new ConfigItem("Wing loading");
      ConfigItem *n11 = new ConfigItem("Lat/Lon");
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
    ConfigItem *i3 = new ConfigItem("Time");
    r7->appendRow(i3);
      {
      ConfigItem *n1 = new ConfigItem("UTC offset");
      ConfigItem *n2 = new ConfigItem("Use GPS time");
      i3->appendRow(n1);
      i3->appendRow(n2);
      }
    ConfigItem *i4 = new ConfigItem("Tracking");
    r7->appendRow(i4);
      {
      ConfigItem *n1 = new ConfigItem("Skylines");
      ConfigItem *n2 = new ConfigItem("Roaming");
      ConfigItem *n3 = new ConfigItem("Tracking interval");
      ConfigItem *n4 = new ConfigItem("Track friends");
      ConfigItem *n5 = new ConfigItem("Show nearby traffic"); // 6.8.2?
      ConfigItem *n6 = new ConfigItem("Key");
      ConfigItem *n7 = new ConfigItem("XCSoar Cloud");  // 6.8.2?
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
ConfigItem::ConfigItem(QString text)
  : QStandardItem(text)
  {
  this->setEditable(false);
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
