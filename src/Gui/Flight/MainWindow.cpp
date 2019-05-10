/*
Copyright_License {

  YCSoar Glide Computer.
  Copyright (C) 2013-2019 Peter F Bradshaw
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

#include "MainWindow.hpp"

#include <QAction>
#include <QtWidgets>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QStackedWidget>
#include <QFrame>
#include <QString>

#include "Map.hpp"
#include "MessageWidget.hpp"
#include "Blackboard/DeviceBlackboard.hpp"

//------------------------------------------------------------------------------
MainWindow::MainWindow()
  : firstStartup(false)
  {
  QAction *exitAct = new QAction(tr("E&xit"));
  connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
  this->baseLayout      = new QVBoxLayout;
  this->activeLayout    = new QStackedLayout;
  this->activeWidget    = new QStackedWidget;
  this->cruiseFrame     = new QFrame;
  this->circlingFrame   = new QFrame;
  this->finalGlideFrame = new QFrame;
  this->ppiFrame        = new QFrame;
  this->infoFrame       = new QFrame;
  this->map             = new Map(this);
  int frameStyle = QFrame::Shape::Box | QFrame::Shadow::Raised;
  this->cruiseFrame->setFrameStyle(frameStyle);
  this->circlingFrame->setFrameStyle(frameStyle);
  this->finalGlideFrame->setFrameStyle(frameStyle);
  this->ppiFrame->setFrameStyle(frameStyle);
  this->infoFrame->setFrameStyle(frameStyle);
  this->cruiseFrame->grabGesture(Qt::SwipeGesture);
  this->circlingFrame->grabGesture(Qt::SwipeGesture);
  this->finalGlideFrame->grabGesture(Qt::SwipeGesture);
  this->ppiFrame->grabGesture(Qt::SwipeGesture);
  this->infoFrame->grabGesture(Qt::SwipeGesture);
//  delete this->layout();  // Get rid of any existing layout. This causes
                            // a SEGV.
  this->setLayout(this->baseLayout);
  this->activeWidget->addWidget(this->cruiseFrame);
  this->activeWidget->addWidget(this->circlingFrame);
  this->activeWidget->addWidget(this->finalGlideFrame);
  this->activeWidget->addWidget(this->ppiFrame);
  this->activeWidget->addWidget(this->infoFrame);

  QSize dSize = QApplication::desktop()->availableGeometry().size();
  this->setMaximumSize(dSize);
  this->resize(dSize);

  char *pwd = getenv( "PWD" );
  char *user = getenv( "USER" );
  char *home = getenv( "HOME" );
  char *lang = getenv( "LANG" );
  char *ldpath = getenv( "LD_LIBRARY_PATH" );
  char *display = getenv( "DISPLAY" );
  char *proxy = getenv( "http_proxy" );
  char *Proxy = getenv( "HTTP_PROXY" );

  qDebug( "PWD=%s", pwd ? pwd : "NULL" );
  qDebug( "USER=%s", user ? user : "NULL" );
  qDebug( "HOME=%s", home ? home : "NULL" );
  qDebug( "LANG=%s", lang ? lang : "NULL" );
  qDebug( "LD_LIBRARY_PATH=%s", ldpath ? ldpath : "NULL" );
  qDebug( "QDir::homePath()=%s", QDir::homePath().toLatin1().data() );
  qDebug( "DISPLAY=%s", display ? display : "NULL" );
  qDebug( "http_proxy=%s", proxy ? proxy : "NULL" );
  qDebug( "HTTP_PROXY=%s", Proxy ? Proxy : "NULL" );

  // As next setup a timer and return. That will start the QtMainLoop.
  // If that is not done in this way, some functionality of the GUI seems
  // not to be stable resp. not usable.
//  QTimer::singleShot(100, this, SLOT(slotCreateDisclaimer()));
  QTimer::singleShot(100, this, SLOT(slotCreateSplash()));
  }

//------------------------------------------------------------------------------
/**
 * Creates the disclaimer query widget.
 */
void MainWindow::slotCreateDisclaimer()
  {
  this->firstStartup = true;

  this->setWindowTitle( tr("Disclaimer") );

  QString disclaimer =
      QObject::tr(
        "<html>"
        "This program comes with"
        "<div align=\"center\">"
        "<p><b>ABSOLUTELY NO WARRANTY!</b></p>"
        "</div>"
        "Do not rely on this software program as your "
        "primary source of navigation. As pilot in command you are "
        "responsible for using official aeronautical "
        "charts and proper methods for safe navigation. "
        "The information presented in this software "
        "program may be outdated or incorrect.<br><br>"
        "<div align=\"center\">"
        "<b>Do You accept these terms?</b>"
        "</div>"
        "</html>");

  MessageWidget *mw = new MessageWidget(disclaimer, this);
  this->connect(mw, SIGNAL(yesClicked()), SLOT(slotCreateSplash()));

  this->setCentralWidget(mw);
  this->setVisible(true);
  }

//------------------------------------------------------------------------------
void MainWindow::slotDisclaimerQuit()
  {
  qApp->quit();
  }

//------------------------------------------------------------------------------
/**
 * Creates the splash screen.
 */
void MainWindow::slotCreateSplash()
  {
  this->setWindowTitle("YCSoar");

  this->splash = new Splash(this);
//  this->setCentralWidget(this->splash);
  this->splash->setVisible(true);
  this->setVisible(true);

  this->ws = new WaitScreen(this);

  this->ws->slot_SetText1(tr("Starting YCSoar..."));

  QCoreApplication::flush();

  // Here we finish the base initialization and start a timer
  // to continue startup in another method. This is done, to return
  // to the window's manager event loop. Otherwise the behavior
  // of some widgets is undefined.

  // when the timer expires the YCSoar startup is continued
  QTimer::singleShot(500, this, SLOT(slotCreateApplicationWidgets()));
  }

//------------------------------------------------------------------------------
/**
 * Creates the application widgets after the base initialization
 * of the core application window.
 */
void MainWindow::slotCreateApplicationWidgets()
  {
  qDebug() << "MainWindow::slotCreateApplicationWidgets()";

  this->ws->slot_SetText1( tr("Creating map elements..."));

#if 0
  _globalMapMatrix = new MapMatrix( this );

  _globalMapContents = new MapContents( this, ws );

  _globalMapConfig = new MapConfig( this );

  BaseMapElement::initMapElement( _globalMapMatrix, _globalMapConfig );

  Airfield::createStaticIcons();

  calculator = new Calculator( this );

  connect( _globalMapMatrix, SIGNAL( displayMatrixValues( int, bool ) ),
           _globalMapConfig, SLOT( slotSetMatrixValues( int, bool ) ) );

  connect( _globalMapMatrix, SIGNAL( homePositionChanged() ),
           _globalMapContents, SLOT( slotReloadWelt2000Data() ) );

  connect( _globalMapMatrix, SIGNAL( homePositionChanged() ),
           _globalMapContents, SLOT( slotReloadOpenAipPoi() ) );

  connect( _globalMapMatrix, SIGNAL( homePositionChanged() ),
           calculator, SLOT( slot_CheckHomeSiteSelection() ) );

  connect( _globalMapMatrix, SIGNAL( projectionChanged() ),
           calculator, SLOT( slot_CheckHomeSiteSelection() ) );

  connect( _globalMapMatrix, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  ws->slot_SetText1( tr( "Creating views..." ) );

  // This is the main widget of Cumulus
  viewMap = new MapView( this );
  viewMap->setVisible( false );

  connect( viewMap, SIGNAL(openingSubWidget()), SLOT(slotSubWidgetOpened()) );
  connect( viewMap, SIGNAL(closingSubWidget()), SLOT(slotSubWidgetClosed()) );

  _globalMapView = viewMap;
  view = mapView;

  m_listViewTabs = new ListViewTabs( this );

  viewAF = m_listViewTabs->viewAF;
  viewHS = m_listViewTabs->viewHS;
  viewOL = m_listViewTabs->viewOL;
  viewNA = m_listViewTabs->viewNA;
  viewRP = m_listViewTabs->viewRP;
  viewWP = m_listViewTabs->viewWP;
  viewTP = m_listViewTabs->viewTP;

  connect( m_listViewTabs, SIGNAL(hidingWidget()), SLOT(slotSubWidgetClosed()) );

  // create GPS instance
  GpsNmea::gps = new GpsNmea( this );
  GpsNmea::gps->blockSignals( true );
  m_logger = IgcLogger::instance();

#ifdef INTERNET
  // create a live tracking instance
  m_liveTrackLogger = new LiveTrack24Logger( this );
#endif

  createActions();
  createContextMenu();

  ws->slot_SetText1( tr( "Setting up connections..." ) );

  // create connections between the components
  connect( _globalMapMatrix, SIGNAL( projectionChanged() ),
           _globalMapContents, SLOT( slotReloadMapData() ) );

  connect( _globalMapContents, SIGNAL( mapDataReloaded(Map::mapLayer) ),
           Map::instance, SLOT( slotRedraw(Map::mapLayer) ) );

  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewAF, SLOT( slot_reloadList() ) );
  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewHS, SLOT( slot_reloadList() ) );
  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewOL, SLOT( slot_reloadList() ) );
  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewNA, SLOT( slot_reloadList() ) );
  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewWP, SLOT( slot_reloadList() ) );
  connect( _globalMapContents, SIGNAL( mapDataReloaded() ),
           viewTP, SLOT( slot_updateTask() ) );

  connect( GpsNmea::gps, SIGNAL( newVario(const Speed&) ),
           calculator, SLOT( slot_GpsVariometer(const Speed&) ) );
  connect( GpsNmea::gps, SIGNAL( newMc(const Speed&) ),
           calculator, SLOT( slot_Mc(const Speed&) ) );
  connect( GpsNmea::gps, SIGNAL( newWind(const Speed&, const short) ),
           calculator, SLOT( slot_GpsWind(const Speed&, const short) ) );
  connect( GpsNmea::gps, SIGNAL( statusChange( GpsNmea::GpsStatus ) ),
           viewMap, SLOT( slot_GPSStatus( GpsNmea::GpsStatus ) ) );
  connect( GpsNmea::gps, SIGNAL( newSatCount(SatInfo&) ),
           viewMap, SLOT( slot_SatCount(SatInfo&) ) );
  connect( GpsNmea::gps, SIGNAL( newSatCount(SatInfo&) ),
           calculator->getWindAnalyser(), SLOT( slot_newConstellation(SatInfo&) ) );
  connect( GpsNmea::gps, SIGNAL( statusChange( GpsNmea::GpsStatus ) ),
           this, SLOT( slotGpsStatus( GpsNmea::GpsStatus ) ) );
  connect( GpsNmea::gps, SIGNAL( newSatConstellation(SatInfo&) ),
           m_logger, SLOT( slotConstellation(SatInfo&) ) );
  connect( GpsNmea::gps, SIGNAL( newSatConstellation(SatInfo&) ),
           calculator->getWindAnalyser(), SLOT( slot_newConstellation(SatInfo&) ) );
  connect( GpsNmea::gps, SIGNAL( statusChange( GpsNmea::GpsStatus ) ),
           calculator->getWindAnalyser(), SLOT( slot_gpsStatusChange( GpsNmea::GpsStatus ) ) );
  connect( GpsNmea::gps, SIGNAL( newSpeed(Speed&) ),
           calculator, SLOT( slot_Speed(Speed&) ) );
  connect( GpsNmea::gps, SIGNAL( newTas(const Speed&) ),
           calculator, SLOT( slot_GpsTas(const Speed&) ) );
  connect( GpsNmea::gps, SIGNAL( newPosition(QPoint&) ),
           calculator, SLOT( slot_Position(QPoint&) ) );
  connect( GpsNmea::gps, SIGNAL( newAltitude(Altitude&, Altitude&, Altitude&) ),
           calculator, SLOT( slot_Altitude(Altitude&, Altitude&, Altitude&) ) );
  connect( GpsNmea::gps, SIGNAL( newAndroidAltitude(const Altitude&) ),
           calculator, SLOT( slot_AndroidAltitude(const Altitude&) ) );
  connect( GpsNmea::gps, SIGNAL( newHeading(const double&) ),
           calculator, SLOT( slot_Heading(const double&) ) );
  connect( GpsNmea::gps, SIGNAL( newFix(const QDateTime&) ),
           calculator, SLOT( slot_newFix(const QDateTime&) ) );
  connect( GpsNmea::gps, SIGNAL( statusChange( GpsNmea::GpsStatus ) ),
           calculator, SLOT( slot_GpsStatus( GpsNmea::GpsStatus ) ) );

#ifdef FLARM
  connect( GpsNmea::gps, SIGNAL( newFlarmCount(int) ),
           viewMap, SLOT( slot_FlarmCount(int) ) );
#endif

  connect( viewWP, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewWP, SIGNAL( deleteWaypoint( Waypoint* ) ),
           calculator, SLOT( slot_WaypointDelete( Waypoint* ) ) );
  connect( viewWP, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewWP, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewWP, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewAF, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewAF, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewAF, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewAF, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewHS, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewHS, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewHS, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewHS, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewOL, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewOL, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewOL, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewOL, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewNA, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewNA, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewNA, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewNA, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewRP, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewRP, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( viewRP, SIGNAL( newHomePosition( const QPoint& ) ),
           _globalMapMatrix, SLOT( slotSetNewHome( const QPoint& ) ) );
  connect( viewRP, SIGNAL( gotoHomePosition() ),
           calculator, SLOT( slot_changePositionHome() ) );

  connect( viewTP, SIGNAL( newWaypoint( Waypoint*, bool ) ),
           calculator, SLOT( slot_WaypointChange( Waypoint*, bool ) ) );
  connect( viewTP, SIGNAL( info( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );

  connect( Map::instance, SIGNAL( isRedrawing( bool ) ),
           this, SLOT( slotMapDrawEvent( bool ) ) );
  connect( Map::instance, SIGNAL( firstDrawingFinished() ),
           this, SLOT( slotFinishStartUp() ) );
  connect( Map::instance, SIGNAL( showPoi( Waypoint* ) ),
           this, SLOT( slotSwitchToInfoView( Waypoint* ) ) );
  connect( Map::instance, SIGNAL( alarm( const QString&, const bool ) ),
           this, SLOT( slotAlarm( const QString&, const bool ) ) );
  connect( Map::instance, SIGNAL( notification( const QString&, const bool ) ),
           this, SLOT( slotNotification( const QString&, const bool ) ) );
  connect( Map::instance, SIGNAL( newPosition( QPoint& ) ),
           calculator, SLOT( slot_changePosition( QPoint& ) ) );
  connect( Map::instance, SIGNAL( userZoom() ),
           calculator, SLOT( slot_userMapZoom() ) );
  connect( Map::instance, SIGNAL( showInfoBoxes(bool) ),
           actionToggleMapSidebar, SLOT( setChecked(bool) ) );

#ifdef FLARM

  connect( Flarm::instance(), SIGNAL( flarmTrafficInfo( QString& ) ),
           Map::instance, SLOT( slotShowFlarmTrafficInfo( QString& )) );

  connect( Flarm::instance(), SIGNAL( flarmAlertZoneInfo( FlarmBase::FlarmAlertZone& ) ),
           _globalMapContents, SLOT( slotNewFlarmAlertZoneData( FlarmBase::FlarmAlertZone& )) );

#endif

  connect( viewMap, SIGNAL( toggleLDCalculation( const bool ) ),
           calculator, SLOT( slot_toggleLDCalculation(const bool) ) );
  connect( viewMap, SIGNAL( toggleMenu() ), SLOT( slotShowContextMenu() ) );
  connect( viewMap, SIGNAL( toggleVarioCalculation( const bool ) ),
           calculator, SLOT( slot_toggleVarioCalculation(const bool) ) );
  connect( viewMap, SIGNAL( toggleETACalculation( const bool ) ),
           calculator, SLOT( slot_toggleETACalculation(const bool) ) );

  connect( calculator, SIGNAL( newWaypoint( const Waypoint* ) ),
           viewMap, SLOT( slot_Waypoint( const Waypoint* ) ) );
  connect( calculator, SIGNAL( newBearing( int ) ),
           viewMap, SLOT( slot_Bearing( int ) ) );
  connect( calculator, SIGNAL( newRelBearing( int ) ),
           viewMap, SLOT( slot_RelBearing( int ) ) );
  connect( calculator, SIGNAL( newDistance( const Distance& ) ),
           viewMap, SLOT( slot_Distance( const Distance& ) ) );
  connect( calculator, SIGNAL( newETA( const QTime& ) ),
           viewMap, SLOT( slot_ETA( const QTime& ) ) );
  connect( calculator, SIGNAL( newHeading( int ) ),
           viewMap, SLOT( slot_Heading( int ) ) );
  connect( calculator, SIGNAL( newSpeed( const Speed& ) ),
           viewMap, SLOT( slot_Speed( const Speed& ) ) );
  connect( calculator, SIGNAL( newTas( const Speed& ) ),
           viewMap, SLOT( slot_Tas( const Speed& ) ) );
  connect( calculator, SIGNAL( newUserAltitude( const Altitude& ) ),
           viewMap, SLOT( slot_Altitude( const Altitude& ) ) );
  connect( calculator, SIGNAL( newPosition( const QPoint&, const int ) ),
           viewMap, SLOT( slot_Position( const QPoint&, const int ) ) );
  connect( calculator, SIGNAL( newPosition( const QPoint&, const int ) ),
           Map::getInstance(), SLOT( slotPosition( const QPoint&, const int ) ) );
  connect( calculator, SIGNAL( switchManualInFlight() ),
           Map::getInstance(), SLOT( slotSwitchManualInFlight() ) );
  connect( calculator, SIGNAL( switchMapScale(const double&) ),
           Map::getInstance(), SLOT( slotSetScale(const double&) ) );
  connect( calculator, SIGNAL( glidePath( const Altitude& ) ),
           viewMap, SLOT( slot_GlidePath( const Altitude& ) ) );
  connect( calculator, SIGNAL( bestSpeed( const Speed& ) ),
           viewMap, SLOT( slot_bestSpeed( const Speed& ) ) );
  connect( calculator, SIGNAL( newMc( const Speed& ) ),
           viewMap, SLOT( slot_Mc( const Speed& ) ) );
  connect( calculator, SIGNAL( newVario( const Speed& ) ),
           viewMap, SLOT( slot_Vario( const Speed& ) ) );
  connect( calculator, SIGNAL( newWind( Vector& ) ),
           viewMap, SLOT( slot_Wind( Vector& ) ) );
  connect( calculator, SIGNAL( newLD( const double&, const double&) ),
           viewMap, SLOT( slot_LD( const double&, const double&) ) );
  connect( calculator, SIGNAL( newGlider( const QString&) ),
           viewMap, SLOT( slot_glider( const QString&) ) );
  connect( calculator, SIGNAL( flightModeChanged(Calculator::FlightMode) ),
           viewMap, SLOT( slot_setFlightStatus(Calculator::FlightMode) ) );
  connect( calculator, SIGNAL( taskpointSectorTouched() ),
           m_logger, SLOT( slotTaskSectorTouched() ) );
  connect( calculator, SIGNAL( taskInfo( const QString&, const bool ) ),
           this, SLOT( slotNotification( const QString&, const bool ) ) );
  connect( calculator, SIGNAL( newSample() ),
           m_logger, SLOT( slotMakeFixEntry() ) );
  connect( calculator, SIGNAL( flightModeChanged(Calculator::FlightMode) ),
           m_logger, SLOT( slotFlightModeChanged(Calculator::FlightMode) ) );

  connect( ( QObject* ) calculator->getReachList(), SIGNAL( newReachList() ),
           this, SLOT( slotNewReachList() ) );

#ifdef INTERNET
  connect( calculator, SIGNAL( newSample() ),
           m_liveTrackLogger, SLOT( slotNewFixEntry() ) );
#endif

  connect( m_logger, SIGNAL( logging( bool ) ),
           viewMap, SLOT( slot_setLoggerStatus() ) );
  connect( m_logger, SIGNAL( logging( bool ) ),
            SLOT( slotLogging( bool ) ) );
  connect( m_logger, SIGNAL( madeEntry() ),
           viewMap, SLOT( slot_LogEntry() ) );
  connect( m_logger, SIGNAL( takeoffTime(QDateTime&) ),
            SLOT( slotTakeoff(QDateTime&) ) );
  connect( m_logger, SIGNAL( landingTime(QDateTime&) ),
            SLOT( slotLanded(QDateTime&) ) );

  calculator->setPosition( _globalMapMatrix->getMapCenter( false ) );

  slotReadconfig();

  // set the default glider to be the last one selected.
  calculator->setGlider( GliderListWidget::getUserSelectedGlider() );
  QString gt = calculator->gliderType();

  if ( !gt.isEmpty() )
    {
      setWindowTitle ( "Cumulus - " + gt );
    }

  calculator->newSites();  // New sites have been loaded in map draw
  // this call is responsible for setting correct AGL/STD for manual mode,
  // must be called after Map::instance->draw(), there the AGL info is loaded
  // I do not connect since it is never emitted, only called once here
  calculator->slot_changePosition(MapMatrix::NotSet);

  if( ! GeneralConfig::instance()->getAirspaceWarningEnabled() )
    {
      QMessageBox mb(this);

      mb.setWindowTitle( tr("Airspace Warnings") );
      mb.setIcon( QMessageBox::Warning );
      mb.setText( tr("<html><b>Airspace warnings are disabled!<br>"
                     "Enable now?</b></html>") );
      mb.setStandardButtons( QMessageBox::Yes | QMessageBox::No );
      mb.setDefaultButton( QMessageBox::Yes );

#ifdef ANDROID

      mb.show();
      QPoint pos = mapToGlobal(QPoint( width()/2 - mb.width()/2, height()/2 - mb.height()/2 ));
      mb.move( pos );

#endif

      if( mb.exec() == QMessageBox::Yes )
        {
          GeneralConfig::instance()->setAirspaceWarningEnabled(true);
        }

      QCoreApplication::flush();
      sleep(1);
    }

  splash->setVisible( true );
  ws->setVisible( true );

  QCoreApplication::flush();
  QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents|QEventLoop::ExcludeSocketNotifiers);

  Map::instance->setDrawing( true );
  viewMap->setVisible( true );
  viewMap->resize( size() );

  // set viewMap as central widget
  setCentralWidget( viewMap );

  // set the map view as the default widget
  setView( mapView );

  // Make the status bar visible. Maemo hides it per default.
  slotViewStatusBar( true );
#endif
  }

