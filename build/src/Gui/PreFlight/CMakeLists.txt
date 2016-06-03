add_executable(preflight ${PREFLIGHT}/main.cpp qrc_qml.cpp)
target_link_libraries(preflight Qt5::Widgets Qt5::Qml)
#add_custom_command(OUTPUT preflight
#                   COMMAND qmake
#                   DEPENDS ${YCSoar_SOURCE_DIR}/src/Gui/PreFlight/PreFlight.pro
#                   WORKING_DIRECTORY ${YCSoar_SOURCE_DIR}/src/Gui/PreFlight)
#add_custom_target(preflight ALL 
#                  COMMAND  qmake -makefile ${YCSoar_SOURCE_DIR}/src/Gui/PreFlight/
#                  COMMAND make)
