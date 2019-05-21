set(XCSOAR ${CMAKE_HOME_DIRECTORY}/submodule/XCSoar-the-library)
set(TOOLS_DIR ${XCSOAR}/tools)
set(XCSOAR_SRC ${XCSOAR}/src)
set(TOOLS_BIN ${YCSoar_BINARY_DIR}/tools)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)

include_directories(${XCSOAR_SRC})

#add_executable(generatesinetables ${TOOLS_DIR}/GenerateSineTables.cpp)

