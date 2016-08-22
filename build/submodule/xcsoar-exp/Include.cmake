set(XCSOAR ${CMAKE_HOME_DIRECTORY}/submodule/xcsoar-exp)
set(XCSOAR_SRC ${XCSOAR}/src)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)


include_directories(${XCSOAR_SRC})
add_definitions(-DHAVE_POSIX) # For POSIX only
add_definitions(-DZLIB_CONST) # Make some of zlib const.

set(UTIL_DIR ${XCSOAR_SRC}/Util)
set(UTIL_SRCS ${UTIL_DIR}/CRC.cpp
             ${UTIL_DIR}/EscapeBackslash.cpp
             ${UTIL_DIR}/StringUtil.cpp
             ${UTIL_DIR}/ConvertString.cpp
             ${UTIL_DIR}/ExtractParameters.cpp
             ${UTIL_DIR}/UTF8.cpp
             ${UTIL_DIR}/tstring.cpp)
include_directories(${XCSOAR_SRC} ${XCSOAR_SRC}/unix ${UTIL_DIR})
add_library(Util-${T} ${UTIL_SRCS})

set(GEO_DIR ${XCSOAR_SRC}/Geo)
set(GEO_SRCS ${GEO_DIR}/ConvexHull/GrahamScan.cpp
	           ${GEO_DIR}/ConvexHull/PolygonInterior.cpp
	           ${GEO_DIR}/Memento/DistanceMemento.cpp
	           ${GEO_DIR}/Memento/GeoVectorMemento.cpp
	           ${GEO_DIR}/Flat/FlatProjection.cpp
	           ${GEO_DIR}/Flat/TaskProjection.cpp
	           ${GEO_DIR}/Flat/FlatBoundingBox.cpp
	           ${GEO_DIR}/Flat/FlatGeoPoint.cpp
	           ${GEO_DIR}/Flat/FlatRay.cpp
	           ${GEO_DIR}/Flat/FlatPoint.cpp
	           ${GEO_DIR}/Flat/FlatEllipse.cpp
	           ${GEO_DIR}/Flat/FlatLine.cpp
	           ${GEO_DIR}/Math.cpp
	           ${GEO_DIR}/SimplifiedMath.cpp
	           ${GEO_DIR}/GeoPoint.cpp
	           ${GEO_DIR}/GeoVector.cpp
	           ${GEO_DIR}/GeoBounds.cpp
	           ${GEO_DIR}/GeoClip.cpp
	           ${GEO_DIR}/SearchPoint.cpp
	           ${GEO_DIR}/SearchPointVector.cpp
	           ${GEO_DIR}/GeoEllipse.cpp
	           ${GEO_DIR}/UTM.cpp)
include_directories(${XCSOAR_SRC} ${GEO_DIR})
add_library(Geo-${T} ${GEO_SRCS})

set(MATH_DIR ${XCSOAR_SRC}/Math)
set(MATH_SRCS ${MATH_DIR}/Angle.cpp
              ${MATH_DIR}/ARange.cpp
              ${MATH_DIR}/FastMath.cpp
              ${MATH_DIR}/FastTrig.cpp
              ${MATH_DIR}/FastRotation.cpp
              ${MATH_DIR}/fixed.cpp
              ${MATH_DIR}/LeastSquares.cpp
              ${MATH_DIR}/DiffFilter.cpp
              ${MATH_DIR}/Filter.cpp
              ${MATH_DIR}/ZeroFinder.cpp
              ${MATH_DIR}/KalmanFilter1d.cpp
              ${MATH_DIR}/SelfTimingKalmanFilter1d.cpp)
include_directories(${XCSOAR_SRC} ${MATH_DIR} ${OUTPUT_INCLUDE})
add_library(Math-${T} ${MATH_SRCS})

set(IO_DIR ${XCSOAR_SRC}/IO)
set(IO_SRCS ${IO_DIR}/FileTransaction.cpp
            ${IO_DIR}/FileCache.cpp
            ${IO_DIR}/FileSource.cpp
            ${IO_DIR}/ZipSource.cpp
            ${IO_DIR}/InflateSource.cpp
            ${IO_DIR}/LineSplitter.cpp
            ${IO_DIR}/ConvertLineReader.cpp
            ${IO_DIR}/FileLineReader.cpp
            ${IO_DIR}/KeyValueFileReader.cpp
            ${IO_DIR}/KeyValueFileWriter.cpp
            ${IO_DIR}/ZipLineReader.cpp
            ${IO_DIR}/InflateLineReader.cpp
            ${IO_DIR}/TextFile.cpp
            ${IO_DIR}/CSVLine.cpp
            ${IO_DIR}/BatchTextWriter.cpp
            ${IO_DIR}/BinaryWriter.cpp
            ${IO_DIR}/TextWriter.cpp)
include_directories(${XCSOAR_SRC} ${IO_DIR})
add_library(Io-${T} ${IO_SRCS})

set(WAYPOINT_DIR ${XCSOAR_SRC}/Engine/Waypoint)
set(WAYPOINT_SRCS ${WAYPOINT_DIR}/WaypointVisitor.cpp
                  ${WAYPOINT_DIR}/Waypoints.cpp
                  ${WAYPOINT_DIR}/Waypoint.cpp)
include_directories(${XCSOAR_SRC} ${WAYPOINT_DIR})
add_library(Waypoint-${T} ${WAYPOINT_SRCS})

set(ROUTE_DIR ${XCSOAR_SRC}/Engine/Route)
set(ROUTE_SRCS ${ROUTE_DIR}/Config.cpp
               ${ROUTE_DIR}/RoutePlanner.cpp
               ${ROUTE_DIR}/AirspaceRoute.cpp
               ${ROUTE_DIR}/TerrainRoute.cpp
               ${ROUTE_DIR}/RouteLink.cpp
               ${ROUTE_DIR}/RoutePolar.cpp
               ${ROUTE_DIR}/RoutePolars.cpp
               ${ROUTE_DIR}/FlatTriangleFan.cpp
               ${ROUTE_DIR}/FlatTriangleFanTree.cpp
               ${ROUTE_DIR}/ReachFan.cpp)
include_directories(${XCSOAR_SRC} ${ROUTE_DIR} ${XCSOAR_SRC}/Engine)
add_library(Route-${T} ${ROUTE_SRCS})

set(GLIDE_DIR ${XCSOAR_SRC}/Engine/GlideSolvers)
set(GLIDE_SRCS ${GLIDE_DIR}/GlideSettings.cpp
               ${GLIDE_DIR}/GlideState.cpp
               ${GLIDE_DIR}/GlueGlideState.cpp
               ${GLIDE_DIR}/GlidePolar.cpp
               ${GLIDE_DIR}/PolarCoefficients.cpp
               ${GLIDE_DIR}/GlideResult.cpp
               ${GLIDE_DIR}/MacCready.cpp)
include_directories(${XCSOAR_SRC} ${GLIDE_DIR})
add_library(Glide-${T} ${GLIDE_SRCS})

set(CONTEST_DIR ${XCSOAR_SRC}/Engine/Contest)
set(CONTEST_SRCS ${CONTEST_DIR}/Settings.cpp
                 ${CONTEST_DIR}/ContestManager.cpp
                 ${CONTEST_DIR}/Solvers/Contests.cpp
                 ${CONTEST_DIR}/Solvers/AbstractContest.cpp
                 ${CONTEST_DIR}/Solvers/TraceManager.cpp
                 ${CONTEST_DIR}/Solvers/ContestDijkstra.cpp
                 ${CONTEST_DIR}/Solvers/DMStQuad.cpp
                 ${CONTEST_DIR}/Solvers/OLCLeague.cpp
                 ${CONTEST_DIR}/Solvers/OLCSprint.cpp
                 ${CONTEST_DIR}/Solvers/OLCClassic.cpp
                 ${CONTEST_DIR}/Solvers/OLCTriangle.cpp
                 ${CONTEST_DIR}/Solvers/OLCFAI.cpp
                 ${CONTEST_DIR}/Solvers/OLCPlus.cpp
                 ${CONTEST_DIR}/Solvers/DMStQuad.cpp
                 ${CONTEST_DIR}/Solvers/XContestFree.cpp
                 ${CONTEST_DIR}/Solvers/XContestTriangle.cpp
                 ${CONTEST_DIR}/Solvers/OLCSISAT.cpp
                 ${CONTEST_DIR}/Solvers/NetCoupe.cpp
                 ${CONTEST_DIR}/Solvers/Retrospective.cpp)
include_directories(${XCSOAR_SRC} ${CONTEST_DIR})
add_library(Contest-${T} ${CONTEST_SRCS})

set(TASK_DIR ${XCSOAR_SRC}/Engine/Task)
set(TASK_SRCS ${TASK_DIR}/Shapes/FAITriangleSettings.cpp 
              ${TASK_DIR}/Shapes/FAITriangleRules.cpp 
              ${TASK_DIR}/Shapes/FAITriangleArea.cpp 
              ${TASK_DIR}/Shapes/FAITriangleTask.cpp 
              ${TASK_DIR}/Shapes/FAITrianglePointValidator.cpp 
              ${TASK_DIR}/TaskBehaviour.cpp 
              ${TASK_DIR}/TaskManager.cpp 
              ${TASK_DIR}/AbstractTask.cpp 
              ${TASK_DIR}/Ordered/StartConstraints.cpp 
              ${TASK_DIR}/Ordered/FinishConstraints.cpp 
              ${TASK_DIR}/Ordered/Settings.cpp 
              ${TASK_DIR}/Ordered/OrderedTask.cpp 
              ${TASK_DIR}/Ordered/TaskAdvance.cpp 
              ${TASK_DIR}/Ordered/SmartTaskAdvance.cpp 
              ${TASK_DIR}/Ordered/Points/IntermediatePoint.cpp 
              ${TASK_DIR}/Ordered/Points/OrderedTaskPoint.cpp 
              ${TASK_DIR}/Ordered/Points/StartPoint.cpp 
              ${TASK_DIR}/Ordered/Points/FinishPoint.cpp 
              ${TASK_DIR}/Ordered/Points/ASTPoint.cpp 
              ${TASK_DIR}/Ordered/Points/AATPoint.cpp 
              ${TASK_DIR}/Ordered/AATIsoline.cpp 
              ${TASK_DIR}/Ordered/AATIsolineSegment.cpp 
              ${TASK_DIR}/Unordered/UnorderedTask.cpp 
              ${TASK_DIR}/Unordered/UnorderedTaskPoint.cpp 
              ${TASK_DIR}/Unordered/GotoTask.cpp 
              ${TASK_DIR}/Unordered/AbortTask.cpp 
              ${TASK_DIR}/Unordered/AlternateTask.cpp 
              ${TASK_DIR}/Factory/AbstractTaskFactory.cpp 
              ${TASK_DIR}/Factory/RTTaskFactory.cpp 
              ${TASK_DIR}/Factory/FAITaskFactory.cpp 
              ${TASK_DIR}/Factory/FAITriangleTaskFactory.cpp 
              ${TASK_DIR}/Factory/FAIORTaskFactory.cpp 
              ${TASK_DIR}/Factory/FAIGoalTaskFactory.cpp 
              ${TASK_DIR}/Factory/AATTaskFactory.cpp 
              ${TASK_DIR}/Factory/MatTaskFactory.cpp 
              ${TASK_DIR}/Factory/MixedTaskFactory.cpp 
              ${TASK_DIR}/Factory/TouringTaskFactory.cpp 
              ${TASK_DIR}/Factory/Create.cpp 
              ${TASK_DIR}/Points/TaskPoint.cpp 
              ${TASK_DIR}/Points/SampledTaskPoint.cpp 
              ${TASK_DIR}/Points/ScoredTaskPoint.cpp 
              ${TASK_DIR}/Points/TaskLeg.cpp 
              ${TASK_DIR}/ObservationZones/Boundary.cpp 
              ${TASK_DIR}/ObservationZones/ObservationZoneClient.cpp 
              ${TASK_DIR}/ObservationZones/ObservationZonePoint.cpp 
              ${TASK_DIR}/ObservationZones/CylinderZone.cpp 
              ${TASK_DIR}/ObservationZones/SectorZone.cpp 
              ${TASK_DIR}/ObservationZones/LineSectorZone.cpp 
              ${TASK_DIR}/ObservationZones/SymmetricSectorZone.cpp 
              ${TASK_DIR}/ObservationZones/KeyholeZone.cpp 
              ${TASK_DIR}/ObservationZones/AnnularSectorZone.cpp 
              ${TASK_DIR}/PathSolvers/TaskDijkstra.cpp 
              ${TASK_DIR}/PathSolvers/TaskDijkstraMin.cpp 
              ${TASK_DIR}/PathSolvers/TaskDijkstraMax.cpp 
              ${TASK_DIR}/PathSolvers/IsolineCrossingFinder.cpp 
              ${TASK_DIR}/Solvers/TaskMacCready.cpp 
              ${TASK_DIR}/Solvers/TaskMacCreadyTravelled.cpp 
              ${TASK_DIR}/Solvers/TaskMacCreadyRemaining.cpp 
              ${TASK_DIR}/Solvers/TaskMacCreadyTotal.cpp 
              ${TASK_DIR}/Solvers/TaskBestMc.cpp 
              ${TASK_DIR}/Solvers/TaskSolveTravelled.cpp 
              ${TASK_DIR}/Solvers/TaskCruiseEfficiency.cpp 
              ${TASK_DIR}/Solvers/TaskEffectiveMacCready.cpp 
              ${TASK_DIR}/Solvers/TaskMinTarget.cpp 
              ${TASK_DIR}/Solvers/TaskOptTarget.cpp 
              ${TASK_DIR}/Solvers/TaskGlideRequired.cpp 
              ${TASK_DIR}/Solvers/TaskSolution.cpp 
              ${TASK_DIR}/Computer/ElementStatComputer.cpp 
              ${TASK_DIR}/Computer/DistanceStatComputer.cpp 
              ${TASK_DIR}/Computer/IncrementalSpeedComputer.cpp 
              ${TASK_DIR}/Computer/TaskVarioComputer.cpp 
              ${TASK_DIR}/Computer/TaskStatsComputer.cpp 
              ${TASK_DIR}/Computer/WindowStatsComputer.cpp 
              ${TASK_DIR}/Stats/CommonStats.cpp 
              ${TASK_DIR}/Stats/ElementStat.cpp 
              ${TASK_DIR}/Stats/TaskStats.cpp
              ${TASK_DIR}/Stats/StartStats.cpp)
include_directories(${XCSOAR_SRC} ${TASK_DIR})
add_library(Task-${T} ${TASK_SRCS})

set(AIRSPACE_DIR ${XCSOAR_SRC}/Engine/Airspace)
set(ENGINE_DIR   ${XCSOAR_SRC}/Engine)
set(AIRSPACE_SRCS ${ENGINE_DIR}/Util/AircraftStateFilter.cpp
                  ${AIRSPACE_DIR}/AirspacesTerrain.cpp
                  ${AIRSPACE_DIR}/Airspace.cpp
                  ${AIRSPACE_DIR}/AirspaceAltitude.cpp
                  ${AIRSPACE_DIR}/AirspaceAircraftPerformance.cpp
                  ${AIRSPACE_DIR}/AbstractAirspace.cpp
                  ${AIRSPACE_DIR}/AirspaceCircle.cpp
                  ${AIRSPACE_DIR}/AirspacePolygon.cpp
                  ${AIRSPACE_DIR}/Airspaces.cpp
                  ${AIRSPACE_DIR}/AirspaceIntersectSort.cpp
                  ${AIRSPACE_DIR}/SoonestAirspace.cpp
                  ${AIRSPACE_DIR}/Predicate/AirspacePredicate.cpp
                  ${AIRSPACE_DIR}/Predicate/AirspacePredicateAircraftInside.cpp
                  ${AIRSPACE_DIR}/Predicate/AirspacePredicateHeightRange.cpp
                  ${AIRSPACE_DIR}/Predicate/OutsideAirspacePredicate.cpp
                  ${AIRSPACE_DIR}/AirspaceVisitor.cpp
                  ${AIRSPACE_DIR}/AirspaceIntersectionVisitor.cpp
                  ${AIRSPACE_DIR}/AirspaceWarningConfig.cpp
                  ${AIRSPACE_DIR}/AirspaceWarningManager.cpp
                  ${AIRSPACE_DIR}/AirspaceWarning.cpp
                  ${AIRSPACE_DIR}/AirspaceSorter.cpp)
include_directories(${XCSOAR_SRC} ${AIRSPACE_DIR})
add_library(Airspace-${T} ${AIRSPACE_SRCS})

# Device drivers
set(DRIVER_DIR ${XCSOAR_SRC}/Device/Driver)
set(VOLKSLOGGER_SRCS ${DRIVER_DIR}/Volkslogger/Register.cpp
                     ${DRIVER_DIR}/Volkslogger/Parser.cpp
                     ${DRIVER_DIR}/Volkslogger/Protocol.cpp
                     ${DRIVER_DIR}/Volkslogger/Declare.cpp
                     ${DRIVER_DIR}/Volkslogger/Database.cpp
                     ${DRIVER_DIR}/Volkslogger/Util.cpp
                     ${DRIVER_DIR}/Volkslogger/dbbconv.cpp
                     ${DRIVER_DIR}/Volkslogger/grecord.cpp
                     ${DRIVER_DIR}/Volkslogger/vlapi2.cpp
                     ${DRIVER_DIR}/Volkslogger/vlapihlp.cpp
                     ${DRIVER_DIR}/Volkslogger/vlutils.cpp
                     ${DRIVER_DIR}/Volkslogger/vlconv.cpp
                     ${DRIVER_DIR}/Volkslogger/Logger.cpp)
set(CAI302_SRCS ${DRIVER_DIR}/CAI302/Protocol.cpp
                ${DRIVER_DIR}/CAI302/PocketNav.cpp
                ${DRIVER_DIR}/CAI302/Mode.cpp
                ${DRIVER_DIR}/CAI302/Parser.cpp
                ${DRIVER_DIR}/CAI302/Settings.cpp
                ${DRIVER_DIR}/CAI302/Declare.cpp
                ${DRIVER_DIR}/CAI302/Logger.cpp
                ${DRIVER_DIR}/CAI302/Manage.cpp
                ${DRIVER_DIR}/CAI302/Register.cpp)
set(IMI_SRCS ${DRIVER_DIR}/IMI/Protocol/MessageParser.cpp
             ${DRIVER_DIR}/IMI/Protocol/Communication.cpp
             ${DRIVER_DIR}/IMI/Protocol/Checksum.cpp
             ${DRIVER_DIR}/IMI/Protocol/Conversion.cpp
             ${DRIVER_DIR}/IMI/Protocol/IGC.cpp
             ${DRIVER_DIR}/IMI/Protocol/Protocol.cpp
             ${DRIVER_DIR}/IMI/Declare.cpp
             ${DRIVER_DIR}/IMI/Internal.cpp
             ${DRIVER_DIR}/IMI/Logger.cpp
             ${DRIVER_DIR}/IMI/Register.cpp)
set(LX_SRCS ${DRIVER_DIR}/LX/NanoLogger.cpp
            ${DRIVER_DIR}/LX/NanoDeclare.cpp
            ${DRIVER_DIR}/LX/Protocol.cpp
            ${DRIVER_DIR}/LX/Mode.cpp
            ${DRIVER_DIR}/LX/Parser.cpp
            ${DRIVER_DIR}/LX/Settings.cpp
            ${DRIVER_DIR}/LX/Declare.cpp
            ${DRIVER_DIR}/LX/Logger.cpp
            ${DRIVER_DIR}/LX/Convert.cpp
            ${DRIVER_DIR}/LX/LXN.cpp
            ${DRIVER_DIR}/LX/Register.cpp)
set(FLARM_SRCS ${DRIVER_DIR}/FLARM/Device.cpp
               ${DRIVER_DIR}/FLARM/Register.cpp
               ${DRIVER_DIR}/FLARM/Mode.cpp
               ${DRIVER_DIR}/FLARM/Parser.cpp
               ${DRIVER_DIR}/FLARM/StaticParser.cpp
               ${DRIVER_DIR}/FLARM/Settings.cpp
               ${DRIVER_DIR}/FLARM/Declare.cpp
               ${DRIVER_DIR}/FLARM/Logger.cpp
               ${DRIVER_DIR}/FLARM/CRC16.cpp
               ${DRIVER_DIR}/FLARM/BinaryProtocol.cpp
               ${DRIVER_DIR}/FLARM/TextProtocol.cpp)
set(FLYTEC_SRCS ${DRIVER_DIR}/Flytec/Register.cpp
                ${DRIVER_DIR}/Flytec/Parser.cpp
                ${DRIVER_DIR}/Flytec/Logger.cpp)
set(VEGA_SRCS ${DRIVER_DIR}/Vega/Misc.cpp
              ${DRIVER_DIR}/Vega/Parser.cpp
              ${DRIVER_DIR}/Vega/Settings.cpp
              ${DRIVER_DIR}/Vega/Volatile.cpp
              ${DRIVER_DIR}/Vega/Register.cpp)
set(BLUEFLY_SRCS ${DRIVER_DIR}/BlueFly/Misc.cpp
                 ${DRIVER_DIR}/BlueFly/Parser.cpp
                 ${DRIVER_DIR}/BlueFly/Settings.cpp
                 ${DRIVER_DIR}/BlueFly/Register.cpp)
set(OTHER_SRCS ${DRIVER_DIR}/AltairPro.cpp
               ${DRIVER_DIR}/BorgeltB50.cpp
               ${DRIVER_DIR}/CaiGpsNav.cpp
               ${DRIVER_DIR}/CaiLNav.cpp
               ${DRIVER_DIR}/Condor.cpp
               ${DRIVER_DIR}/CProbe.cpp
               ${DRIVER_DIR}/EW.cpp
               ${DRIVER_DIR}/EWMicroRecorder.cpp
               ${DRIVER_DIR}/Eye.cpp
               ${DRIVER_DIR}/FlymasterF1.cpp
               ${DRIVER_DIR}/FlyNet.cpp
               ${DRIVER_DIR}/Generic.cpp
               ${DRIVER_DIR}/LevilAHRS_G.cpp
               ${DRIVER_DIR}/Leonardo.cpp
               ${DRIVER_DIR}/GTAltimeter.cpp
               ${DRIVER_DIR}/NmeaOut.cpp
               ${DRIVER_DIR}/OpenVario.cpp
               ${DRIVER_DIR}/PosiGraph.cpp
               ${DRIVER_DIR}/XCOM760.cpp
               ${DRIVER_DIR}/ILEC.cpp
               ${DRIVER_DIR}/Westerboer.cpp
               ${DRIVER_DIR}/Zander.cpp
               ${DRIVER_DIR}/Vaulter.cpp
               ${DRIVER_DIR}/ATR833.cpp)
set(DRIVER_SRCS ${VOLKSLOGGER_SRCS}
                ${CAI302_SRCS}
                ${IMI_SRCS}
                ${LX_SRCS}
                ${FLARM_SRCS}
                ${FLYTEC_SRCS}
                ${VEGA_SRCS}
                ${BLUEFLY_SRCS}
                ${OTHER_SRCS})
include_directories(${XCSOAR_SRC} ${DRIVER_DIR})
add_library(Driver-${T} ${DRIVER_SRCS})

set(SHAPE_DIR ${XCSOAR_SRC}/Topography/shapelib)
set(SHAPE_SRCS ${SHAPE_DIR}/mapstring.c
               ${SHAPE_DIR}/mapbits.c
               ${SHAPE_DIR}/mapfile.c
               ${SHAPE_DIR}/mapprimitive.c
               ${SHAPE_DIR}/mapsearch.c
               ${SHAPE_DIR}/mapshape.c
               ${SHAPE_DIR}/maptree.c
               ${SHAPE_DIR}/mapxbase.c)
include_directories(${XCSOAR_SRC} ${SHAPE_DIR})
add_library(Shape-${T} ${SHAPE_SRCS})

set(MAIN_SRCS ${XCSOAR_SRC}/LocalPath.cpp)
include_directories(${XCSOAR_SRC})
add_library(XCSoarMain-${T} ${MATH_SRCS})
add_custom_target(xcsoar-${T}
                  DEPENDS Airspace-${T}
                          Contest-${T}
                          Driver-${T}
                          Geo-${T}
                          Glide-${T}
                          Io-${T}
                          Math-${T}
                          Route-${T}
                          Shape-${T}
                          Task-${T}
                          Util-${T}
                          Waypoint-${T})


