add_library(xcsoarthunk-${T} ${XCSOARTHUNK_SRC_DIR}/LocalPathThunk.cpp
                             ${XCSOARTHUNK_SRC_DIR}/ProfileThunk.cpp
                             ${XCSOARTHUNK_SRC_DIR}/TaskModel.cpp
                             ${XCSOARTHUNK_SRC_DIR}/ConfigModel.cpp)
target_link_libraries(xcsoarthunk-${T} Qt5::Widgets Qt5::Qml
                      -L${XCSOAR_BIN} XCSoar-static-${T}
                      pthread z
                     )
include_directories(${XCSOAR_SRC}
                    ${XCSOAR_SRC}/unix
                    ${XCSOAR_SRC}/Profile
                    ${XCSOAR_SRC}/Engine)

# Patch panel.
add_custom_target(xcsoarthunk-${B} DEPENDS xcsoarthunk-${T})

