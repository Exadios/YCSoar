add_subdirectory(xcsoar-exp)

set(SUBMODULE ${YCSoar_SOURCE_DIR}/submodule)
set(OUTPUT_DIR ${YCSoar_SOURCE_DIR}/out/doc/xcsoar/)
add_custom_target(xcsoar_doc
                  COMMAND doxygen Doxyfile.xcsoar
                  WORKING_DIRECTORY ${SUBMODULE})
