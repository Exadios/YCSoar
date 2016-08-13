add_executable(preflight ${PREFLIGHT}/main.cpp
                         ${PREFLIGHT}/MainWindow.cpp
                         ${PREFLIGHT}/PreFlight.qrc)
target_link_libraries(preflight Qt5::Widgets Qt5::Qml)
