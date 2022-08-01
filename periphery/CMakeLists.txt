cmake_minimum_required( VERSION 3.19 )
project( periphery_library C CXX ASM )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_STANDARD 11 )

set( UART_DIR uart )
set( I2C_DIR i2c )
set( RCC_DIR rcc )
set( GPIO_DIR gpio )
set( UTILS_DIR utils )
set( TYPES_DIR types )

file( GLOB_RECURSE SOURCES
    "${UART_DIR}/*.*"
    "${UTILS_DIR}/*.*"
    "${TYPES_DIR}/*.*"
    "${GPIO_DIR}/*.*"
    "${RCC_DIR}/*.*"
    "${I2C_DIR}/*.*"
    )

include_directories( ${UART_DIR} )

add_library( ${PROJECT_NAME} ${SOURCES}  )

if( NOT RUN_TEST )
    target_link_libraries( ${PROJECT_NAME} CMSIS::STM32::F407VG STM32::NoSys )
endif()