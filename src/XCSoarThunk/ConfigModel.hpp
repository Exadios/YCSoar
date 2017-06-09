/*
 * YCSoar Glide Computer.
 * Copyright (C) 2013-2016 Peter F Bradshaw
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// Copyright for TreeItem class.
/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

/**
 * \addtogroup XCSoarThunk
 * @{
 */
#ifndef __CONFIGMODEL_HPP
#define __CONFIGMODEL_HPP

#include <QStandardItemModel>
#include "Computer/Settings.hpp"

struct ComputerSettings;

/**
 * Provides an adequate view of the XCSoar configuration for YCSoar.
 *
 * Handles:
 *  Site Files
 *             - Map Database
 *             - Waypoints
 *             - Additional Waypoints
 *             - Watched Waypoints
 *             - Airspaces
 *             - Additional Airspaces
 *             - Waypoint Details
 *
 *  Map Display 
 *              - Orientation
 *                            - Cruise Orientation
 *                            - Circling Orientation
 *                            - Circling Zoom
 *                            - Map Shift Reference
 *                            - Glider Position Offset
 *                            - Max Auto Zoom Distance
 *                            - Distinct Page Zoom
 *              - Elements
 *                         - Ground Track
 *                         - FLARM Traffic
 *                         - Trail Length
 *                         - Trail Drift
 *                         - Trail Type
 *                         - Trail Scale
 *                         - Detour Cost Markers
 *                         - Aircraft Symbol
 *                         - Wind Arrow
 *              - Waypoints
 *                          - Label Format
 *                          - Arrival Height
 *                          - Label Style
 *                          - Label Visibility
 *                          - Landable Symbols
 *                          - Detailed Landables
 *                          - Landable Size
 *                          - Scale Runway
 *              - Terrain
 *                        - Terrain Display
 *                        - Topography Display
 *              - Airspace
 *                         - Airspace Display
 *                         - Label Display
 *                         - Warnings
 *                         - Warnings Dialog
 *                         - Warning Time
 *                         - Repetitive Sound
 *                         - Acknowledge Time
 *                         - Use Black Outline
 *                         - Airspace Fill Mode
 *                         - Filter
 *                                  - Unknown
 *                                  - Restricted
 *                                  - Prohibited Area
 *                                  - Danger Area
 *                                  - Class A
 *                                  - Class B
 *                                  - Class C
 *                                  - Class D
 *                                  - Class E
 *                                  - Class F
 *                                  - Class G
 *                                  - No Gliders
 *                                  - CTR
 *                                  - Wave
 *                                  - Task Area
 *                                  - Transponder Mandatory Zone
 *                                  - Military Base Traffic Zone
 *                                  - Radio Mandatory Zone
 *                         - Colors
 *                                  - Unknown
 *                                  - Restricted
 *                                  - Prohibited Area
 *                                  - Danger Area
 *                                  - Class A
 *                                  - Class B
 *                                  - Class C
 *                                  - Class D
 *                                  - Class E
 *                                  - Class F
 *                                  - Class G
 *                                  - No Gliders
 *                                  - CTR
 *                                  - Wave
 *                                  - Task Area
 *                                  - Transponder Mandatory Zone
 *                                  - Military Base Traffic Zone
 *                                  - Radio Mandatory Zone
 *
 * Glide Computer 
 *                - Safety Factors
 *                                 - Arrival Height
 *                                 - Terrain Height
 *                                 - Alternates Mode
 *                                 - Polar Degradation
 *                                 - Auto Bugs
 *                                 - Saftey MC
 *                                 - STF Risk Factor
 *                - Glide Computer
 *                                 - Auto MC Mode
 *                                 - Block Speed to Fly
 *                                 - Nav. by Baro Altitude
 *                                 - Flap Forces Cruise
 *                                 - GR Average Period
 *                                 - Predict Wind Drift
 *                                 - Wave Assistant
 *                - Wind
 *                       - Auto Wind
 *                - Route
 *                        - Route Mode
 *                        - Route Climb
 *                        - Route Ceiling
 *                - Reach
 *                        - Reach Mode
 *                        - Reach Polar
 *                        - Reach Display
 *                - Scoring
 *                          - On Line Contest
 *                          - Predict Contest
 *                          - FAI Triangle Areas
 *
 * Gauges 
 *        - FLARM and Other
 *                          - FLARM Radar
 *                          - Auto Close FLARM
 *                          - Thermal Assistant
 *                          - Thermal Band
 *                          - Final Glide Bar
 *                          - Final Glide Bar MC0
 *                          - Vario Bar
 *        - Vario
 *                - Speed Arrows
 *                - Show Average
 *                - Show MacReady
 *                - Show Bugs
 *                - Show Ballast
 *                - Show Gross
 *                - Averager Needle
 *        - Audio Vario
 *
 *
 * Task Defaults 
 *               - Rules
 *                       - Start Max Speed
 *                       - Start Max Speed Margin
 *                       - Start Max Height
 *                       - Start Max Height Margin
 *                       - Start Height Ref
 *                       - Finish Min Height
 *                       - Finish Min Height Ref
 *               - Turnpoint Types
 *                                 - Start Point
 *                                 - Gate Width
 *                                 - Finish Point
 *                                 - Gate Width
 *                                 - Turn Point
 *                                 - Radius
 *                                 - Task
 *                                 - AAT Min Time
 *                                 - Optimization Margin
 *
 * Look 
 *      - Language and Input
 *                           - Text Size
 *                           - Events
 *                           - Language
 *                           - Menu Timeout
 *                           - Text Input Style
 *      - Screen Layout
 *                      - Display Orientation
 *                      - InfoBox Geometry
 *                      - FLARM Display
 *                      - Tab Dialog Style
 *                      - Message Display
 *                      - Inverse InfoBoxes
 *                      - InfoBox Border
 *      - Pages
 *              - Page 1 InfoBoxes Auto
 *              - Page 2 InfoBoxes Circling
 *              - Page 3 InfoBoxes Cruise
 *              - Page 4 InfoBoxes Final Glide
 *              - Page 5 InfoBoxes
 *              - Page 6 InfoBoxes
 *              - Page 7 InfoBoxes
 *              - Page 8 InfoBoxes
 *              - FLARM Radar InfoBoxes
 *              - Page 1 Main Area
 *              - Page 2 Main Area
 *              - Page 3 Main Area
 *              - Page 4 Main Area
 *              - Page 5 Main Area
 *              - Page 6 Main Area
 *              - Page 7 Main Area
 *              - Page 8 Main Area
 *              - Page 1 Bottom Area
 *              - Page 2 Bottom Area
 *              - Page 3 Bottom Area
 *              - Page 4 Bottom Area
 *              - Page 5 Bottom Area
 *              - Page 6 Bottom Area
 *              - Page 7 Bottom Area
 *              - Page 8 Bottom Area
 *      - Infobox Sets
 *                     - Set 1 Name
 *                     - Set 2 Name
 *                     - Set 3 Name
 *                     - Set 4 Name
 *                     - Set 5 Name
 *                     - Set 6 Name
 *                     - Set 7 Name
 *                     - Set 8 Name
 *                     - Set 1
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 2
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 3
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 4
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 5
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 6
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 7
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *                     - Set 8
 *                             - Box 1
 *                             - Box 2
 *                             - Box 3
 *                             - Box 4
 *                             - Box 5
 *                             - Box 6
 *                             - Box 7
 *                             - Box 8
 *
 * General
 *         - Logger
 *                  - Pilot Name
 *                  - Sample Interval Cruise
 *                  - Sample Interval Circling
 *                  - Auto Logger
 *                  - NMEA Logger
 *                  - Log Book
 *                  - Logger ID
 *         - Units
 *                 - Aircraft / Wind Speed
 *                 - Distance
 *                 - Vertical Speed
 *                 - Altitude
 *                 - Temperature
 *                 - Task Speed
 *                 - Pressure
 *                 - Mass
 *                 - Wing Loading
 *                 - Lat / Lon
 *         - Time
 *                - UTC Offset
 *                - Local Time
 *                - Use GPS Time
 *         - Tracking
 *                    - SkyLines
 *                    - Tracking Interval
 *                    - Key
 *
 * \todo Finish this class.
 */

class ConfigModel : public QStandardItemModel
  {
  Q_OBJECT

public:
  /**
   * Ctor.
   */
  ConfigModel();
  
  /**
   * Dtor.
   */
  ~ConfigModel();

  /**
   * Implements QAbstractItemModel::data().
   * @param index The index of the item being requested.
   * @param role The context of the data - Qt::DisplayRole by default.
   * @return The data item corresponding to the index. If index is invalid
   *         then the QVariant returned will be QVariant::Invalid.
   */
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) 
                 const Q_DECL_OVERRIDE;

protected:
  /**
   * Wind settings.
   * @return The wind settings.
   */
  WindSettings &Wind();

  /**
   * Airspace settings.
   * @return The airspace settings.
   */
  AirspaceComputerSettings &Airspace();

  /**
   * Task behaviour.
   * @return The task behaviour settings.
   */
  TaskBehaviour &Task();

  /**
   * Logger behaviour.
   * @return The logger behaviour settings.
   */
  LoggerSettings &Logger();

private:
  struct ComputerSettings computer;
  };

#include <QList>
#include <QVariant>

/**
 *
 * A container for items of data supplied by the simple tree model.
 */
class TreeItem
{
public:
    explicit TreeItem(const QList<QVariant> &data, TreeItem *parentItem = 0);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parentItem();

private:
    QList<TreeItem*> child_items;
    QList<QVariant> item_data;
    TreeItem *parent_item;
};

#endif  // __CONFIGMODEL_HPP
/**
 * @}
 */
