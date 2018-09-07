add_subdirectory(linux-native-debug)
add_subdirectory(linux-native-release)
#add_subdirectory(linux-native-sanitize)

# Patch panel.
add_custom_target(preflight-linux-native
                  DEPENDS preflight-linux-native-debug
                          preflight-linux-native-release
                          preflight-linux-native-sanitize)
add_custom_target(preflight-linux
                  DEPENDS preflight-linux-native)
add_custom_target(preflight DEPENDS preflight-linux)
add_custom_target(preflight-debug DEPENDS preflight-linux-native-debug)
add_custom_target(preflight-release DEPENDS preflight-linux-native-release)
add_custom_target(preflight-sanitize DEPENDS preflight-linux-native-sanitize)
