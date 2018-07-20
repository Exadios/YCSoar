set(GUI ${YCSoar_SOURCE_DIR}/src/Gui)
set(XCSOARTHUNK_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarThunk)
set(XCSOARSUBST_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarSubst)
set(XCSOAR_SRC_DIR ${YCSoar_SOURCE_DIR}/submodule/xcsoar-exp/src)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)               # apt install qtbase5-dev
find_package(Qt5Qml REQUIRED)                   # apt install qtdeclarative5-dev
find_package(Qt5 COMPONENTS Quick Core Network)

add_subdirectory(XCSoarSubst)
add_subdirectory(XCSoarThunk)
add_subdirectory(Gui)
add_subdirectory(Experiment)

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
add_custom_command(OUTPUT ${OUTPUT_DIR}
                   COMMAND mkdir -p ${OUTPUT_DIR})
add_custom_target(ycsoar_doc
                  COMMAND rm -fr ${OUTPUT_DIR}/html
                  COMMAND rm -fr ${OUTPUT_DIR}/doxygen_sqlite3.db
                  COMMAND doxygen
                  DEPENDS ${OUTPUT_DIR}
                  WORKING_DIRECTORY ${SRC})
