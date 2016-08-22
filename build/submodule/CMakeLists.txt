add_subdirectory(xcsoar-exp)

set(SUBMODULE ${YCSoar_SOURCE_DIR}/submodule)
set(OUTPUT_DIR ${YCSoar_SOURCE_DIR}/out/doc/xcsoar/)
add_custom_target(xcsoar_doc
                  COMMAND rm -fr ${OUTPUT_DIR}/html
                  COMMAND rm -fr ${OUTPUT_DIR}/doxygen_sqlite3.db
                  COMMAND doxygen Doxyfile.xcsoar
                  WORKING_DIRECTORY ${SUBMODULE})
