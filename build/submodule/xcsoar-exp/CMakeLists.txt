set(XCSOAR ${CMAKE_HOME_DIRECTORY}/submodule/xcsoar-exp)
set(XCSOAR_SRC ${XCSOAR}/src)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)
add_subdirectory(linux-native-debug)
add_subdirectory(linux-native-release)
add_subdirectory(linux-native-sanitize)

# Patch panel
add_custom_target(xcsoar-linux-native
                  DEPENDS xcsoar-linux-native-debug
                          xcsoar-linux-native-release
                          xcsoar-linux-native-sanitize)
add_custom_target(xcsoar-linux DEPENDS xcsoar-linux-native)
add_custom_target(xcsoar DEPENDS xcsoar-linux)
add_custom_target(xcsoar-debug DEPENDS xcsoar-linux-native-debug)
add_custom_target(xcsoar-release DEPENDS xcsoar-linux-native-release)
add_custom_target(xcsoar-sanitize DEPENDS xcsoar-linux-native-sanitize)
