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

//------------------------------------------------------------------------------
ConfigModel::ConfigModel()
  {
  QStandardItemModel *standardModel = new QStandardItemModel;
  QStandardItem *rootNode = standardModel->invisibleRootItem(); 

  QStandardItem *filesNode      = new QStandardItem("Files Node");
  rootNode->appendRow(filesNode);
    {
    QStandardItem *dbNode         = new QStandardItem("Map Database");
    QStandardItem *waypointsNode  = new QStandardItem("Waypoints");
    QStandardItem *moreNode       = new QStandardItem("Additional Waypoints");
    QStandardItem *watchedNode    = new QStandardItem("Watched Waypoints");
    QStandardItem *airspacesNode  = new QStandardItem("Airspaces");
    QStandardItem *additionalNode = new QStandardItem("Additional Airspaces");
    QStandardItem *detailsNode    = new QStandardItem("Waypoint Details");
    filesNode->appendRow(dbNode);
    filesNode->appendRow(waypointsNode);
    filesNode->appendRow(moreNode);
    filesNode->appendRow(watchedNode);
    filesNode->appendRow(airspacesNode);
    filesNode->appendRow(additionalNode);
    filesNode->appendRow(detailsNode);
    }
  QStandardItem *mapNode         = new QStandardItem("Map Display");
  rootNode->appendRow(mapNode);
    {
    QStandardItem *orientationNode = new QStandardItem("Orientation");
    mapNode->appendRow(orientationNode);
      {
      QStandardItem *cruiseNode       = new QStandardItem("Cruise");
      QStandardItem *circlingNode     = new QStandardItem("Circling");
      QStandardItem *circlingzoomNode = new QStandardItem("Circling Zoom");
      QStandardItem *mapshiftNode     = new QStandardItem("Map Shift Reference");
      QStandardItem *offsetNode       = new QStandardItem("Glider Position Offset");
      QStandardItem *maxzoomNode      = new QStandardItem("Max Auto Zoom");
      QStandardItem *distinctscaleNode = new QStandardItem("Distinct Page Zoom");
      orientationNode->appendRow(cruiseNode);
      orientationNode->appendRow(circlingNode);
      orientationNode->appendRow(circlingzoomNode);
      orientationNode->appendRow(mapshiftNode);
      orientationNode->appendRow(offsetNode);
      orientationNode->appendRow(maxzoomNode);
      orientationNode->appendRow(distinctscaleNode);
      }
    QStandardItem *elementsNode    = new QStandardItem("Elements");
    mapNode->appendRow(elementsNode);
      {
      QStandardItem *trackNode       = new QStandardItem("Ground track");
      QStandardItem *flarmNode       = new QStandardItem("FLARM traffic");
      QStandardItem *trailLengthNode = new QStandardItem("Trail length");
      QStandardItem *trailDriftNode  = new QStandardItem("Trail drift");
      QStandardItem *trailTypeNode   = new QStandardItem("Trail type");
      QStandardItem *trailScaledNode = new QStandardItem("Trail scaled");
      QStandardItem *detourNode      = new QStandardItem("Detour cost markers");
      QStandardItem *aircraftNode    = new QStandardItem("Aircraft symbol");
      QStandardItem *windNode        = new QStandardItem("Wind arrow");
      elementsNode->appendRow(trackNode);
      elementsNode->appendRow(flarmNode);
      elementsNode->appendRow(trailLengthNode);
      elementsNode->appendRow(trailDriftNode);
      elementsNode->appendRow(trailScaledNode);
      elementsNode->appendRow(trailTypeNode);
      elementsNode->appendRow(detourNode);
      elementsNode->appendRow(aircraftNode);
      elementsNode->appendRow(windNode);
      }
    QStandardItem *waypointsNode   = new QStandardItem("Waypoints");
    mapNode->appendRow(waypointsNode);
      {
      QStandardItem *formatNode    = new QStandardItem("Label format");
      QStandardItem *styleNode     = new QStandardItem("Label style");
      QStandardItem *visibiltyNode = new QStandardItem("Label visibilty");
      QStandardItem *arrivalNode   = new QStandardItem("Arrival height");
      QStandardItem *symbolsNode   = new QStandardItem("Landable symbols");
      QStandardItem *landablesNode = new QStandardItem("Detailed landables");
      QStandardItem *sizeNode      = new QStandardItem("Landable size");
      QStandardItem *scaleNode     = new QStandardItem("Scale runway length");
      waypointsNode->appendRow(formatNode);
      waypointsNode->appendRow(styleNode);
      waypointsNode->appendRow(visibiltyNode);
      waypointsNode->appendRow(arrivalNode);
      waypointsNode->appendRow(symbolsNode);
      waypointsNode->appendRow(landablesNode);
      waypointsNode->appendRow(sizeNode);
      waypointsNode->appendRow(scaleNode);
      }
    QStandardItem *terrainNode     = new QStandardItem("Terrain");
    mapNode->appendRow(terrainNode);
      {
      QStandardItem *displayNode = new QStandardItem("Terrain display");
      QStandardItem *topographyNode = new QStandardItem("Topography display");
      terrainNode->appendRow(displayNode);
      terrainNode->appendRow(topographyNode);
      }
    QStandardItem *airspaceNode    = new QStandardItem("Airspace");
    mapNode->appendRow(airspaceNode);
      {
      QStandardItem *displayNode     = new QStandardItem("Airspace display");
      QStandardItem *labelNode       = new QStandardItem("Label visibility");
      QStandardItem *warningsNode    = new QStandardItem("Warnings");
      QStandardItem *dialogNode      = new QStandardItem("Warnings dialog");
      QStandardItem *timeNode        = new QStandardItem("Warning time");
      QStandardItem *repetitiveNode  = new QStandardItem("Repetitive sound");
      QStandardItem *acknowledgeNode = new QStandardItem("Acknowledge time");
      QStandardItem *outlineNode     = new QStandardItem("Use black outline");
      QStandardItem *modeNode        = new QStandardItem("Airspace fill node");
      airspaceNode->appendRow(displayNode);
      airspaceNode->appendRow(labelNode);
      airspaceNode->appendRow(warningsNode);
      airspaceNode->appendRow(dialogNode);
      airspaceNode->appendRow(timeNode);
      airspaceNode->appendRow(repetitiveNode);
      airspaceNode->appendRow(acknowledgeNode);
      airspaceNode->appendRow(outlineNode);
      airspaceNode->appendRow(modeNode);
      }
    }
  QStandardItem *computerNode = new QStandardItem("Glide Computer");
  rootNode->appendRow(computerNode);
    {
    QStandardItem *safetyNode   = new QStandardItem("Safety Factors");
    computerNode->appendRow(safetyNode);
      {
      QStandardItem *arrivalNode     = new QStandardItem("Arrival height");
      QStandardItem *terrainNode     = new QStandardItem("Terrain height");
      QStandardItem *alternatesNode  = new QStandardItem("Alternates mode");
      QStandardItem *degradationNode = new QStandardItem("Polar degradation");
      QStandardItem *bugsNode        = new QStandardItem("Auto bugs");
      QStandardItem *mcNode          = new QStandardItem("Safety MC");
      QStandardItem *riskNode        = new QStandardItem("STF risk factor");
      safetyNode->appendRow(arrivalNode);
      safetyNode->appendRow(terrainNode);
      safetyNode->appendRow(alternatesNode);
      safetyNode->appendRow(degradationNode);
      safetyNode->appendRow(bugsNode);
      safetyNode->appendRow(mcNode);
      safetyNode->appendRow(riskNode);
      }
    QStandardItem *glideNode    = new QStandardItem("Glide Computer");
    computerNode->appendRow(glideNode);
      {
      QStandardItem *autoNode    = new QStandardItem("Auto MC mode");
      QStandardItem *speedNode   = new QStandardItem("Block soeed to fly");
      QStandardItem *baroNode    = new QStandardItem("Nav. by baro altitude");
      QStandardItem *flapsNode   = new QStandardItem("Flaps forces cruise");
      QStandardItem *averageNode = new QStandardItem("GR average period");
      QStandardItem *windNode    = new QStandardItem("Predict wind drift");
      QStandardItem *waveNode    = new QStandardItem("Wave assistant");
      glideNode->appendRow(autoNode);
      glideNode->appendRow(speedNode);
      glideNode->appendRow(baroNode);
      glideNode->appendRow(flapsNode);
      glideNode->appendRow(averageNode);
      glideNode->appendRow(windNode);
      glideNode->appendRow(waveNode);
      }
    QStandardItem *windNode     = new QStandardItem("Wind");
    computerNode->appendRow(windNode);
      {
      QStandardItem *autoNode     = new QStandardItem("Auto wind");
      QStandardItem *externalNode = new QStandardItem("External wind");
      windNode->appendRow(autoNode);
      windNode->appendRow(externalNode);
      }
    QStandardItem *routeNode    = new QStandardItem("Route");
    computerNode->appendRow(routeNode);
      {
      QStandardItem *modeNode    = new QStandardItem("Route mode");
      QStandardItem *climbNode   = new QStandardItem("Route climb");
      QStandardItem *ceilingNode = new QStandardItem("Route ceiling");
      routeNode->appendRow(modeNode);
      routeNode->appendRow(climbNode);
      routeNode->appendRow(ceilingNode);
      }
    QStandardItem *reachNode    = new QStandardItem("Reach");
    computerNode->appendRow(reachNode);
      {
      QStandardItem *modeNode    = new QStandardItem("Reach mode");
      QStandardItem *polarNode   = new QStandardItem("Reach polar");
      QStandardItem *displayNode = new QStandardItem("Reach display");
      reachNode->appendRow(modeNode);
      reachNode->appendRow(polarNode);
      reachNode->appendRow(displayNode);
      }
    QStandardItem *scoringNode  = new QStandardItem("Scoring");
    computerNode->appendRow(scoringNode);
      {
      QStandardItem *olcNode      = new QStandardItem("On-Line Contest");
      QStandardItem *predictNode  = new QStandardItem("Predict contest");
      QStandardItem *triangleNode = new QStandardItem("FAI triangle areas");
      scoringNode->appendRow(olcNode);
      scoringNode->appendRow(predictNode);
      scoringNode->appendRow(triangleNode);
      }
    }
  QStandardItem *gaugesNode   = new QStandardItem("Gauges");
  rootNode->appendRow(gaugesNode);
    {
    QStandardItem *flarmNode    = new QStandardItem("FLARM and Other");
    gaugesNode->appendRow(flarmNode);
      {
      QStandardItem *radarNode     = new QStandardItem("FLARM radar");
      QStandardItem *autoNode      = new QStandardItem("Auto close FLARM");
      QStandardItem *assistantNode = new QStandardItem("Thermal assitant");
      QStandardItem *bandNode      = new QStandardItem("Thermal band");
      QStandardItem *finalNode     = new QStandardItem("Final glide bar");
      QStandardItem *mc0Node       = new QStandardItem("Final glide bar MC0");
      QStandardItem *varioNode     = new QStandardItem("Vario bar");
      flarmNode->appendRow(radarNode);
      flarmNode->appendRow(autoNode);
      flarmNode->appendRow(assistantNode);
      flarmNode->appendRow(bandNode);
      flarmNode->appendRow(finalNode);
      flarmNode->appendRow(mc0Node);
      flarmNode->appendRow(varioNode);
      }
    QStandardItem *varioNode    = new QStandardItem("Vario");
    gaugesNode->appendRow(varioNode);
      {
      QStandardItem *speedNode    = new QStandardItem("Speed arrows");
      QStandardItem *averageNode  = new QStandardItem("Show average");
      QStandardItem *mcNode       = new QStandardItem("Show MacReady");
      QStandardItem *bugsNode     = new QStandardItem("Show bugs");
      QStandardItem *ballastNode  = new QStandardItem("Show ballast");
      QStandardItem *grossNode    = new QStandardItem("Show gross");
      QStandardItem *averagerNode = new QStandardItem("Averager needle");
      varioNode->appendRow(speedNode);
      varioNode->appendRow(averageNode);
      varioNode->appendRow(mcNode);
      varioNode->appendRow(bugsNode);
      varioNode->appendRow(ballastNode);
      varioNode->appendRow(grossNode);
      varioNode->appendRow(averagerNode);
      }
    QStandardItem *audioNode    = new QStandardItem("Audio");
    gaugesNode->appendRow(audioNode);
      {
      QStandardItem *varioNode    = new QStandardItem("Audio vario");
      QStandardItem *volumeNode   = new QStandardItem("Volume");
      QStandardItem *deadbandNode = new QStandardItem("Enable deadband");
      QStandardItem *minNode      = new QStandardItem("Min. frequency");
      QStandardItem *zeroNode     = new QStandardItem("Zero frequency");
      QStandardItem *maxNode      = new QStandardItem("Max. frequency");
      QStandardItem *minliftNode  = new QStandardItem("Deadband min. lift");
      QStandardItem *maxliftNode  = new QStandardItem("Deadband max. lift");
      audioNode->appendRow(varioNode);
      audioNode->appendRow(volumeNode);
      audioNode->appendRow(deadbandNode);
      audioNode->appendRow(minNode);
      audioNode->appendRow(zeroNode);
      audioNode->appendRow(maxNode);
      audioNode->appendRow(minliftNode);
      audioNode->appendRow(maxliftNode);
      }
    }
  QStandardItem *taskNode       = new QStandardItem("Task Defaults");
  rootNode->appendRow(taskNode);
    {
    QStandardItem *rulesNode      = new QStandardItem("Rules");
    taskNode->appendRow(rulesNode);
      {
      QStandardItem *maxspeedNode     = new QStandardItem("Start max. speed");
      QStandardItem *speedmarginNode  = new QStandardItem("Start max. speed margin");
      QStandardItem *maxheightNode    = new QStandardItem("Start max. height");
      QStandardItem *heightmarginNode = new QStandardItem("Start max. height margin");
      QStandardItem *heightrefNode    = new QStandardItem("Start height ref.");
      QStandardItem *minheightNode    = new QStandardItem("Finish min. height");
      taskNode->appendRow(maxspeedNode);
      taskNode->appendRow(speedmarginNode);
      taskNode->appendRow(maxheightNode);
      taskNode->appendRow(heightmarginNode);
      taskNode->appendRow(heightrefNode);
      taskNode->appendRow(minheightNode);
      }
    QStandardItem *turnpointsNode = new QStandardItem("Turnpoint Types");
    taskNode->appendRow(turnpointsNode);
      {
      QStandardItem *startNode        = new QStandardItem("Start line");
      QStandardItem *gateNode         = new QStandardItem("Gate width");
      QStandardItem *finishNode       = new QStandardItem("Finish point");
      QStandardItem *finishradiusNode = new QStandardItem("Radius");
      QStandardItem *turnNode         = new QStandardItem("Turn point");
      QStandardItem *turnradiusNode   = new QStandardItem("Radius");
      QStandardItem *taskNode         = new QStandardItem("Task");
      QStandardItem *timeNode         = new QStandardItem("AAT min. time");
      QStandardItem *optimizationNode = new QStandardItem("Optimization margin");
      turnpointsNode->appendRow(startNode);
      turnpointsNode->appendRow(gateNode);
      turnpointsNode->appendRow(finishNode);
      turnpointsNode->appendRow(finishradiusNode);
      turnpointsNode->appendRow(turnNode);
      turnpointsNode->appendRow(turnradiusNode);
      turnpointsNode->appendRow(taskNode);
      turnpointsNode->appendRow(timeNode);
      turnpointsNode->appendRow(optimizationNode);
      }
    }
  QStandardItem *lookNode     = new QStandardItem("Look");
  rootNode->appendRow(lookNode);
    {
    QStandardItem *languageNode = new QStandardItem("Language and Input");
    lookNode->appendRow(languageNode);
      {
      QStandardItem *sizeNode           = new QStandardItem("Text size");
      QStandardItem *eventsNode         = new QStandardItem("Events");
      QStandardItem *languageSelectNode = new QStandardItem("Language");
      QStandardItem *menuNode           = new QStandardItem("Menu timeout");
      QStandardItem *styleNode          = new QStandardItem("Text input style");
      QStandardItem *feedbackNode       = new QStandardItem("Haptic feedback");
      languageNode->appendRow(sizeNode);
      languageNode->appendRow(eventsNode);
      languageNode->appendRow(languageSelectNode);
      languageNode->appendRow(menuNode);
      languageNode->appendRow(styleNode);
      languageNode->appendRow(feedbackNode);
      }
    QStandardItem *screenNode   = new QStandardItem("Screen");
    lookNode->appendRow(screenNode);
      {
      QStandardItem *orientationNode = new QStandardItem("Display orientation");
      QStandardItem *geometryNode    = new QStandardItem("Infobox geometry");
      QStandardItem *flarmNode       = new QStandardItem("FLARM display");
      QStandardItem *tabNode         = new QStandardItem("Tab dialog style");
      QStandardItem *messageNode     = new QStandardItem("Message display");
      QStandardItem *inverseNode     = new QStandardItem("Inverse infoboxes");
      QStandardItem *coloredNode     = new QStandardItem("Colored infoboxes");
      QStandardItem *borderNode      = new QStandardItem("Infobox border");
      screenNode->appendRow(orientationNode);
      screenNode->appendRow(geometryNode);
      screenNode->appendRow(flarmNode);
      screenNode->appendRow(tabNode);
      screenNode->appendRow(messageNode);
      screenNode->appendRow(inverseNode);
      screenNode->appendRow(coloredNode);
      screenNode->appendRow(borderNode);
      }
    QStandardItem *pagesNode    = new QStandardItem("Pages");
    lookNode->appendRow(pagesNode);
      {
      // \todo Implement 8 infobox selections.
      }
    QStandardItem *infoboxNodes = new QStandardItem("Infobox Sets");
    lookNode->appendRow(infoboxNodes);
      {
      // \todo Implement 8 page selections.
      }
    }
  QStandardItem *generalNode  = new QStandardItem("General");
  rootNode->appendRow(generalNode);
    {
    QStandardItem *loggerNode   = new QStandardItem("Logger");
    generalNode->appendRow(loggerNode);
      {
      QStandardItem *n1 = new QStandardItem("Pilot name");
      QStandardItem *n2 = new QStandardItem("Time step cruise");
      QStandardItem *n3 = new QStandardItem("Time step circling");
      QStandardItem *n4 = new QStandardItem("Auto logger");
      QStandardItem *n5 = new QStandardItem("NMEA logger");
      QStandardItem *n6 = new QStandardItem("Log book");
      QStandardItem *n7 = new QStandardItem("Logger ID");
      loggerNode->appendRow(n1);
      loggerNode->appendRow(n2);
      loggerNode->appendRow(n3);
      loggerNode->appendRow(n4);
      loggerNode->appendRow(n5);
      loggerNode->appendRow(n6);
      loggerNode->appendRow(n7);
      }
    QStandardItem *unitsNode    = new QStandardItem("Units");
    generalNode->appendRow(unitsNode);
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
      unitsNode->appendRow(n1);
      unitsNode->appendRow(n2);
      unitsNode->appendRow(n3);
      unitsNode->appendRow(n4);
      unitsNode->appendRow(n5);
      unitsNode->appendRow(n6);
      unitsNode->appendRow(n7);
      unitsNode->appendRow(n8);
      unitsNode->appendRow(n9);
      unitsNode->appendRow(n10);
      unitsNode->appendRow(n11);
      }
    QStandardItem *timeNode     = new QStandardItem("Time");
    generalNode->appendRow(timeNode);
      {
      QStandardItem *n1 = new QStandardItem("UTC offset");
      QStandardItem *n2 = new QStandardItem("Use GPS time");
      timeNode->appendRow(n1);
      timeNode->appendRow(n2);
      }
    QStandardItem *trackingNode = new QStandardItem("Tracking");
    generalNode->appendRow(trackingNode);
      {
      QStandardItem *n1 = new QStandardItem("Skylines");
      QStandardItem *n2 = new QStandardItem("Roaming");
      QStandardItem *n3 = new QStandardItem("Tracking interval");
      QStandardItem *n4 = new QStandardItem("Track friends");
      QStandardItem *n5 = new QStandardItem("Show nearby traffic"); // 6.8.2?
      QStandardItem *n6 = new QStandardItem("Key");
      QStandardItem *n7 = new QStandardItem("XCSoar Cloud");  // 6.8.2?
      trackingNode->appendRow(n1);
      trackingNode->appendRow(n2);
      trackingNode->appendRow(n3);
      trackingNode->appendRow(n4);
      trackingNode->appendRow(n5);
      trackingNode->appendRow(n6);
      trackingNode->appendRow(n7);
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
QModelIndex
ConfigModel::index(int row, int column, const QModelIndex &parent) const
  {
  return QModelIndex(); // Invalid index.
  }

//------------------------------------------------------------------------------
QModelIndex
ConfigModel::parent(const QModelIndex &index) const
  {
  return QModelIndex(); // Invalid index.
  }

//------------------------------------------------------------------------------
int
ConfigModel::rowCount(const QModelIndex &parent) const
  {
  return 0;
  }

//------------------------------------------------------------------------------
int
ConfigModel::columnCount(const QModelIndex &parent) const
  {
  return 0; // Always for this class.
  }

//------------------------------------------------------------------------------
QVariant
ConfigModel::data(const QModelIndex &index, int role) const
  {
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
