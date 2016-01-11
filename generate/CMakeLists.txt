set(TOOLS_BIN ${YCSoar_BINARY_DIR}/tools)
set(OUTPUT_INCLUDE ${YCSoar_BINARY_DIR}/include)

add_custom_target(generate ALL
                  COMMAND [ -d ${OUTPUT_INCLUDE} ] || mkdir ${OUTPUT_INCLUDE} 
                  COMMAND ${TOOLS_BIN}/generatesinetables > ${OUTPUT_INCLUDE}/MathTables.h
                  VERBATIM)
