set(TOOLS_BIN ${YCSoar_BINARY_DIR}/tools)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)

add_custom_command(OUTPUT ${OUTPUT_INCLUDE}/MathTables.h
                   COMMAND [ -d ${OUTPUT_INCLUDE} ] || mkdir ${OUTPUT_INCLUDE} 
                   COMMAND ${TOOLS_BIN}/generatesinetables > ${OUTPUT_INCLUDE}/MathTables.h
                   MAIN_DEPENDENCY generatesinetables
                   VERBATIM)
add_custom_target(generate ALL
                  DEPENDS ${OUTPUT_INCLUDE}/MathTables.h
                 )
