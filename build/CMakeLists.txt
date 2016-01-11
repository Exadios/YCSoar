set(XCSOAR ../submodule/xcsoar-exp)
set(XCSOAR_SRC ${XCSOAR}/src)


include_directories(${XCSOAR_SRC})

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

