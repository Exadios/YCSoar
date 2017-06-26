cmake_minimum_required(VERSION 3.0)

set(XCSOARTHUNK_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarThunk/${T})
set(XCSOARSUBST_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarSubst/${T})
set(XCSOAR_BIN_DIR ${YCSoar_BINARY_DIR}/build/submodule/xcsoar-exp/${T})
set(XCSOAR_SRC_DIR ${YCSoar_SOURCE_DIR}/submodule/xcsoar-exp/src)
set(XCSOARTHUNK_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarThunk)
set(XCSOARSUBST_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarSubst)
add_executable(experimentmodelview-${T} EXCLUDE_FROM_ALL
               ${EXPERIMENT_SRC}/ModelView/ConfigModel.cpp)
target_link_libraries(experimentmodelview-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOARSUBST_BIN_DIR} xcsoarmain-subst-${T}
                      -L${XCSOARTHUNK_BIN_DIR} xcsoarthunk-${T}
                      -L${XCSOAR_BIN_DIR} XCSoarMain-${T}
                      -L${XCSOAR_BIN_DIR} Io-${T}
                      -L${XCSOAR_BIN_DIR} Terrain-${T}
                      -L${XCSOAR_BIN_DIR} Thread-${T}
                      -L${XCSOAR_BIN_DIR} WaypointEngine-${T}
                      -L${XCSOAR_BIN_DIR} TaskEngine-${T}
                      -L${XCSOAR_BIN_DIR} Time-${T})
target_include_directories(experimentmodelview-${T} PRIVATE
                           ${XCSOARSUBST_SRC_DIR}
                           ${XCSOARTHUNK_SRC_DIR}
                           ${XCSOAR_SRC_DIR}
                           ${XCSOAR_SRC_DIR}/Screen
                           ${XCSOAR_SRC_DIR}/Screen/Memory)
include_directories(BEFORE ${XCSOARTHUNK_SRC_DIR}
                           ${XCSOARSUBST_SRC_DIR})
include_directories(${XCSOAR_SRC_DIR})

add_executable(testmodel-${T} EXCLUDE_FROM_ALL
               ${EXPERIMENT_SRC}/ModelView/TestModel.cpp)
target_link_libraries(testmodel-${T} Qt5::Widgets Qt5::Qml)
