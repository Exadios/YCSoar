add_subdirectory(src)

add_custom_target(debug DEPENDS ycsoar-debug)
add_custom_target(release DEPENDS ycsoar-release)
add_custom_target(sanitize DEPENDS ycsoar-sanitize)
add_custom_target(linux-native DEPENDS gui-linux-native)

add_custom_target(doc DEPENDS ycsoar_doc)
