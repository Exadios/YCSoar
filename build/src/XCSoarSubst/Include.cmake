set(XCSOAR_LIB_DIR ${YCSoar_BINARY_DIR}/build/submodule/xcsoar-exp/${T})
set(INCLUDE_PATH ${YCSoar_SOURCE_DIR}/submodule/xcsoar-exp/src)
set(XCSOAR_SRC ${INCLUDE_PATH})
add_library(xcsoarmain-subst-${T} ${XCSOARSUBST}/LogFile.cpp
                                  ${XCSOARSUBST}/Operation/VerboseOperationEnvironment.cpp
                                  ${XCSOARSUBST}/Screen/Canvas.cpp
                                  ${XCSOARSUBST}/Screen/Pen.cpp
                                  ${XCSOARSUBST}/Screen/Font.cpp
                                  ${XCSOARSUBST}/Screen/Brush.cpp
                                  ${XCSOARSUBST}/Screen/RenderObject.cpp
           )
target_link_libraries(xcsoarmain-subst-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOAR_LIB_DIR} XCSoarMain-${T}
                      -L${XCSOAR_LIB_DIR} Screen-${T})
include_directories(./
                    ${INCLUDE_PATH}
                    ${INCLUDE_PATH}/unix
                    ${INCLUDE_PATH}/Profile
                    ${INCLUDE_PATH}/Screen/Memory)

# Test harness
set(TestRunner "${CMAKE_CURRENT_BINARY_DIR}/run-test.cpp")
add_custom_command(OUTPUT ${TestRunner}
                   COMMAND cxxtestgen -o ${TestRunner} --error-printer Suite.test.hpp
                   MAIN_DEPENDENCY ${XCSOARSUBST}/Screen/Suite.test.hpp
                   WORKING_DIRECTORY "${XCSOARSUBST}/Screen"
                  )
add_executable(run-test-${T} ${TestRunner})
target_link_libraries(run-test-${T} xcsoarmain-subst-${T})
add_test(NAME xcsoarsubst-test COMMAND run-test-${T})

add_custom_target(xcsoarsubst-${B}
                  DEPENDS xcsoarmain-subst-${T}
                          run-test-${T})
