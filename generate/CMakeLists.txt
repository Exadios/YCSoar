set(TOOLS_BIN ${YCSoar_BINARY_DIR}/tools)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)

add_custom_command(OUTPUT ${OUTPUT_INCLUDE}/MathTables.h
                   COMMAND [ -d ${OUTPUT_INCLUDE} ] || mkdir ${OUTPUT_INCLUDE} 
                   COMMAND ${TOOLS_BIN}/generatesinetables > ${OUTPUT_INCLUDE}/MathTables.h
                   VERBATIM)
set_source_files_properties(${TOOLS_BIN}/generatesinetables
                            PROPERTIES GENERATE TRUE)
add_custom_target(generate ALL
                  DEPENDS ${OUTPUT_INCLUDE}/MathTables.h
                 )
add_dependencies(generate generatesinetables)
