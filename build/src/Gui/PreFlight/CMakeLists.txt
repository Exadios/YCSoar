add_executable(preflight ${PREFLIGHT}/main.cpp qrc_qml.cpp)
target_link_libraries(preflight Qt5::Widgets Qt5::Qml)
add_custom_command(OUTPUT qrc_qml.cpp
                   COMMAND rcc -name qml ${PREFLIGHT}/qml.qrc -o qrc_qml.cpp
                  )
