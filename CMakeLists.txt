project(YCSoar)
cmake_minimum_required(VERSION 3.0)

enable_testing()

set(warnings "-Wall -Wextra -Werror")

if (NOT CONFIGURED_ONCE)
    set(CMAKE_CXX_FLAGS "${warnings} -fno-exceptions -fno-rtti -std=gnu++0x -fno-threadsafe-statics -fmerge-all-constants"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
    set(CMAKE_C_FLAGS   "${warnings}"
        CACHE STRING "Flags used by the compiler during all build types." FORCE)
endif()

#include_directories(./submoldule/xcsoar-exp/src)

add_subdirectory(./build)
#add_subdirectory(./src)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL
    "A flag showing that CMake has configured at least once.")


