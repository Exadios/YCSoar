add_subdirectory(linux-32-debug)
add_subdirectory(linux-32-release)
add_custom_target(preflight-linux-32
                  DEPENDS preflight-linux-32-debug
                          preflight-linux-32-release)
add_custom_target(preflight-linux
                  DEPENDS preflight-linux-32)
add_custom_target(preflight DEPENDS preflight-linux)
add_custom_target(preflight-debug DEPENDS preflight-linux-32-debug)
add_custom_target(preflight-release DEPENDS preflight-linux-32-release)
