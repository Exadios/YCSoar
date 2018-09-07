set(XCSOAR_LIB_DIR ${YCSoar_BINARY_DIR}/build/submodule/xcsoar-exp/${T})
set(INCLUDE_PATH ${YCSoar_SOURCE_DIR}/submodule/xcsoar-exp/src)
set(XCSOAR_SRC ${INCLUDE_PATH})
add_library(xcsoarthunk-${T} ${XCSOARTHUNK_SRC_DIR}/LocalPathThunk.cpp
                             ${XCSOARTHUNK_SRC_DIR}/ProfileThunk.cpp
                             ${XCSOARTHUNK_SRC_DIR}/TaskModel.cpp
                             ${XCSOARTHUNK_SRC_DIR}/ConfigModel.cpp)
target_link_libraries(xcsoarthunk-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOAR_LIB_DIR} XCSoarMain-${T})
include_directories(${INCLUDE_PATH}
                    ${INCLUDE_PATH}/unix
                    ${INCLUDE_PATH}/Profile
                    ${INCLUDE_PATH}/Engine)

# Patch panel.
add_custom_target(xcsoarthunk-${B} DEPENDS xcsoarthunk-${T})
