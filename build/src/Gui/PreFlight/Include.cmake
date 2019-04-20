set(XCSOARTHUNK_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarThunk/${T})
set(XCSOARSUBST_BIN_DIR ${YCSoar_BINARY_DIR}/build/src/XCSoarSubst/${T})
set(XCSOAR_BIN_DIR ${YCSoar_BINARY_DIR}/build/submodule/XCSoar-the-library/${T})
set(XCSOARTHUNK_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarThunk)
set(XCSOARSUBST_SRC_DIR ${YCSoar_SOURCE_DIR}/src/XCSoarSubst)
add_executable(preflight-${T} ${PREFLIGHT}/main.cpp
                              ${PREFLIGHT}/MainWindow.cpp
                              ${PREFLIGHT}/TaskWizard.cpp
                              ${PREFLIGHT}/ConfigWindow.cpp
                              ${PREFLIGHT}/PreFlight.qrc)
set(LINK_LIBS Qt5::Widgets Qt5::Qml
              -L${XCSOARSUBST_BIN_DIR} xcsoarmain-subst-${T}
              -L${XCSOARTHUNK_BIN_DIR} xcsoarthunk-${T}
              -L${XCSOAR_BIN_DIR} XCSoar-static-${T}
              pthread z
   )     
if(T STREQUAL "linux-native-sanitize")
set(LINK_LIBS ${LINK_LIBS} asan tsan lsan)
endif(T STREQUAL "linux-native-sanitize") 
target_link_libraries(preflight-${T} ${LINK_LIBS} -lpthread -lm)
target_include_directories(preflight-${T} PRIVATE ${XCSOARSUBST_SRC_DIR}
                                                  ${XCSOARTHUNK_SRC_DIR}
                                                  ${XCSOAR_SRC})
include_directories(BEFORE ${XCSOARTHUNK_SRC_DIR}
                           ${XCSOARSUBST_SRC_DIR})
include_directories(${XCSOAR_SRC})
