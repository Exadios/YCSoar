set(XCSOARTHUNK_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarThunk/${T})
set(XCSOAR_BIN_DIR ${YCSoar_BINARY_DIR}/build/submodule/xcsoar-exp/${T})
add_executable(preflight-${T} ${PREFLIGHT}/main.cpp
                              ${PREFLIGHT}/MainWindow.cpp
                              ${PREFLIGHT}/TaskWizard.cpp
                              ${PREFLIGHT}/PreFlight.qrc)
target_link_libraries(preflight-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOARTHUNK_BIN_DIR} xcsoarthunk-${T}
                      -L${XCSOAR_BIN_DIR} XCSoarMain-${T})
