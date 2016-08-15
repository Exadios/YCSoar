set(XCSOAR ${CMAKE_HOME_DIRECTORY}/submodule/xcsoar-exp)
set(XCSOAR_SRC ${XCSOAR}/src)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)
add_subdirectory(linux-32-debug)
add_subdirectory(linux-32-release)
add_subdirectory(src)

add_custom_target(xcsoar-linux-32
                  DEPENDS xcsoar-linux-32-debug
                          xcsoar-linux-32-release)
add_custom_target(xcsoar-linux DEPENDS xcsoar-linux-32)
add_custom_target(xcsoar DEPENDS xcsoar-linux)
add_custom_target(xcsoar-debug DEPENDS xcsoar-linux-32-debug)
add_custom_target(xcsoar-release DEPENDS xcsoar-linux-32-release)
add_custom_target(debug DEPENDS xcsoar-debug gui-debug)
add_custom_target(release DEPENDS xcsoar-release gui-release)
