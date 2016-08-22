add_subdirectory(Gui)

set(SRC ${YCSoar_SOURCE_DIR}/src)
set(OUTPUT_DIR ${YCSoar_SOURCE_DIR}/out/doc/ycsoar/)
add_custom_target(ycsoar_doc
                  COMMAND rm -fr ${OUTPUT_DIR}/html
                  COMMAND rm -fr ${OUTPUT_DIR}/doxygen_sqlite3.db
                  COMMAND doxygen
                  WORKING_DIRECTORY ${SRC})
