add_executable(preflight-${T} ${PREFLIGHT}/main.cpp
                              ${PREFLIGHT}/MainWindow.cpp
                              ${PREFLIGHT}/TaskWizard.cpp
                              ${PREFLIGHT}/PreFlight.qrc)
target_link_libraries(preflight-${T} Qt5::Widgets Qt5::Qml)
