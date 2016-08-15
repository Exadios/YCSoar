add_subdirectory(submodule)
add_subdirectory(src)

add_custom_target(debug DEPENDS xcsoar-debug gui-debug)
add_custom_target(release DEPENDS xcsoar-release gui-release)
