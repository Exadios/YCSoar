set(CMAKE_BUILD_TYPE Debug)
set(XCSOARTHUNK_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarThunk/linux-native-debug)
set(XCSOARSUBST_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarSubst/linux-native-debug)
set(XCSOAR_BIN_DIR ${XCSOAR_HOME}/out/build/src/linux-native-debug)
add_executable(flight-unit-test ${FLIGHT}/main.cpp
                                ${FLIGHT}/Main.cpp
                                ${FLIGHT}/XCSoarThread.cpp
                                ${FLIGHT}/XCSoar.cpp
                                ${FLIGHT}/Process/ProcessFactory.cpp
                                ${FLIGHT}/Process/Process.cpp
                                ${FLIGHT}/Process/OneSecTick.cpp
                                ${FLIGHT}/Map.cpp
                                ${FLIGHT}/MainWindow.cpp)
target_link_libraries(flight-unit-test Qt5::Widgets Qt5::Qml
                      -L${XCSOARSUBST_BIN_DIR} xcsoarmain-subst-linux-native-debug
                      -L${XCSOARTHUNK_BIN_DIR} xcsoarthunk-linux-native-debug
                      -L${XCSOAR_BIN_DIR} XCSoarMain-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} Io-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} Terrain-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} Thread-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} WaypointEngine-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} TaskEngine-static-linux-native-debug
                      -L${XCSOAR_BIN_DIR} Time-static-linux-native-debug
                      boost_system
                      boost_thread)
include_directories(BEFORE ${XCSOARTHUNK_SRC_DIR}
                           ${XCSOARSUBST_SRC_DIR})
include_directories(${XCSOAR_SRC_DIR})
