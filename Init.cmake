# Force CMake to use gcc 4.9.
set(CMAKE_AR /usr/bin/gcc-ar CACHE FILEPATH "Path to a program." FORCE)
set(CMAKE_CXX_COMPILER /usr/bin/g++ CACHE FILEPATH "CXX compiler" FORCE)
set(CMAKE_C_COMPILER /usr/bin/gcc CACHE FILEPATH "C compiler" FORCE)
set(CMAKE_NM usr/bin/gcc-nm CACHE FILEPATH "Path to a program." FORCE)
set(CMAKE_RANLIB /usr/bin/gcc-ranlib CACHE FILEPATH "Path to a program." FORCE)
set(CMAKE_CXX_FLAGS "-Wno-error=unused-parameter -Wall -Wextra -Wwrite-strings -Wcast-qual -Wpointer-arith -Wsign-compare -Wundef -Wmissing-declarations -Wredundant-decls -Wmissing-noreturn -Wno-unused-parameter -Wno-missing-field-initializers  -Wcast-align -Werror -fno-exceptions -fno-rtti -std=gnu++14 -fno-threadsafe-statics -fmerge-all-constants -fvisibility=hidden -fpic -funwind-tables -finput-charset=utf-8" CACHE STRING "Flags used by the compiler during all build types" FORCE)
