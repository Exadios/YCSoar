add_subdirectory(submodule)
add_subdirectory(src)

add_custom_target(debug DEPENDS xcsoar-debug gui-debug)
add_custom_target(release DEPENDS xcsoar-release gui-release)
add_custom_target(linux-32 DEPENDS xcsoar-linux-32 gui-linux-32)

add_custom_target(doc DEPENDS ycsoar_doc xcsoar_doc)
