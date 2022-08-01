cmake_minimum_required( VERSION 3.19 )
project( devices_library C CXX ASM )

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_C_STANDARD 11 )

set(DEBUG_DIR
        debug)

set(SOURCES
        ${DEBUG_DIR}/sender.cpp
        ${DEBUG_DIR}/sender.hpp
        ${DEBUG_DIR}/uart.cpp
        ${DEBUG_DIR}/uart.hpp
        light/bh1721.cpp light/bh1721.hpp)
include_directories(.)
add_library( ${PROJECT_NAME} ${SOURCES} )

if( NOT RUN_TEST )
    target_link_libraries( ${PROJECT_NAME} CMSIS::STM32::F407VG STM32::NoSys )
endif()