set(CMAKE_BUILD_TYPE Debug)
add_definitions("-fsanitize=address,leak")
set(B "debug")
set(T "linux-native-sanitize")
add_definitions(-DHAVE_POSIX
                -DHAVE_STDINT_H
                -DHAVE_UNISTD_H
                -DHAVE_VASPRINTF
                -DUSE_MEMORY_CANVAS
                -DUSE_POLL_EVENT
                -DUSE_FREETYPE
                -DHAVE_VASPRINTF)
include(../Include.cmake)
