set(XCSOARTHUNK_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarThunk/${T})
set(XCSOARSUBST_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarSubst/${T})
set(XCSOAR_BIN_DIR ${XCSOAR_BIN}/${T})
add_executable(flight-${T} ${FLIGHT}/main.cpp
                           ${FLIGHT}/Main.cpp
                           ${FLIGHT}/XCSoarThread.cpp
                           ${FLIGHT}/XCSoar.cpp
                           ${FLIGHT}/Process/ProcessFactory.cpp
                           ${FLIGHT}/Process/Process.cpp
                           ${FLIGHT}/Process/OneSecTick.cpp
                           ${FLIGHT}/Map.cpp
                           ${FLIGHT}/MainWindow.cpp
                           ${FLIGHT}/MessageWidget.cpp
                           ${FLIGHT}/Splash.cpp
                           ${FLIGHT}/WaitScreen.cpp)
set(LINK_LIBS Qt5::Widgets Qt5::Qml
                      -L${XCSOARSUBST_BIN_DIR} xcsoarmain-subst-${T}
                      -L${XCSOARTHUNK_BIN_DIR} xcsoarthunk-${T}
                      pthread z boost_system boost_thread
   )
if(T STREQUAL "linux-native-sanitize")
set(LINK_LIBS ${LINK_LIBS} asan tsan lsan)
endif(T STREQUAL "linux-native-sanitize")
target_link_libraries(flight-${T} ${LINK_LIBS})
target_include_directories(flight-${T} PRIVATE ${XCSOARSUBST_SRC_DIR}
                                               ${XCSOARTHUNK_SRC_DIR}
                                               ${XCSOAR_SRC})
include_directories(BEFORE ${XCSOARTHUNK_SRC_DIR}
                           ${XCSOARSUBST_SRC_DIR})
include_directories(${XCSOAR_SRC})
