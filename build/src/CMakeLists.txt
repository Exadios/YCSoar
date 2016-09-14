set(GUI ${YCSoar_SOURCE_DIR}/src/Gui)
set(XCSOARTHUNK ${YCSoar_SOURCE_DIR}/src/XCSoarThunk)
set(XCSOARSUBST ${YCSoar_SOURCE_DIR}/src/XCSoarSubst)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5 COMPONENTS Quick Core Network)

add_subdirectory(XCSoarSubst)
add_subdirectory(XCSoarThunk)
add_subdirectory(Gui)

add_custom_target(ycsoar-debug
                  DEPENDS gui-debug
                          xcsoarthunk-debug
                          xcsoarsubst-debug)
add_custom_target(ycsoar-release
                  DEPENDS gui-release
                          xcsoarthunk-release
                          xcsoarsubst-release)

set(SRC ${YCSoar_SOURCE_DIR}/src)
set(OUTPUT_DIR ${YCSoar_SOURCE_DIR}/out/doc/ycsoar/)
add_custom_target(ycsoar_doc
                  COMMAND rm -fr ${OUTPUT_DIR}/html
                  COMMAND rm -fr ${OUTPUT_DIR}/doxygen_sqlite3.db
                  COMMAND doxygen
                  WORKING_DIRECTORY ${SRC})
