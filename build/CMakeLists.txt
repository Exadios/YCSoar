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
add_library(Util ${UTIL_SRCS})

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
add_library(Geo ${GEO_SRCS})

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
add_library(Math ${MATH_SRCS})

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
add_library(Io ${IO_SRCS})

set(WAYPOINT_DIR ${XCSOAR_SRC}/Engine/Waypoint)
set(WAYPOINT_SRCS ${WAYPOINT_DIR}/WaypointVisitor.cpp
                  ${WAYPOINT_DIR}/Waypoints.cpp
                  ${WAYPOINT_DIR}/Waypoint.cpp)
include_directories(${XCSOAR_SRC} ${WAYPOINT_DIR})
add_library(Waypoint ${WAYPOINT_SRCS})
