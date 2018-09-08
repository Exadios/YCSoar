add_subdirectory(linux-native-debug)
add_subdirectory(linux-native-release)
add_subdirectory(linux-native-sanitize)

# Patch panel.
add_custom_target(flight-linux-native
                  DEPENDS flight-linux-native-debug
                          flight-linux-native-release
                          flight-linux-native-sanitize)
add_custom_target(flight-linux
                  DEPENDS flight-linux-native)
add_custom_target(flight DEPENDS flight-linux)
add_custom_target(flight-debug DEPENDS flight-linux-native-debug)
add_custom_target(flight-release DEPENDS flight-linux-native-release)
add_custom_target(flight-sanitize DEPENDS flight-linux-native-sanitize)
