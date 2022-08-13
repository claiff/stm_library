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
        light/bh/bh1721.cpp
        light/bh/bh1721.hpp
        pressure/bmp/bmp_280.hpp
        pressure/bmp/compensation/compensator.hpp
        pressure/bmp/settings/weather.cpp
        pressure/bmp/settings/weather.hpp
        pressure/bmp/types/isettings.hpp
        pressure/bmp/settings/humidity_only.cpp
        pressure/bmp/settings/humidity_only.hpp
        pressure/bmp/settings/indoor_navigation.cpp
        pressure/bmp/settings/indoor_navigation.hpp
        pressure/bmp/settings/gaming.cpp
        pressure/bmp/settings/gaming.hpp
        pressure/bmp/compensation/dig_holder.cpp
        pressure/bmp/compensation/dig_holder.hpp
        pressure/bmp/compensation/compensator.cpp pressure/bmp/bmp_280.cpp light/bh/mode/auto.cpp light/bh/mode/auto.hpp light/bh/types/imode.hpp light/bh/mode/low.cpp light/bh/mode/low.hpp light/bh/mode/high.cpp light/bh/mode/high.hpp)
include_directories(.)
add_library( ${PROJECT_NAME} ${SOURCES} )

if( NOT RUN_TEST )
    target_link_libraries( ${PROJECT_NAME} CMSIS::STM32::F407VG STM32::NoSys )
endif()