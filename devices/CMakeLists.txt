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
        light/bh/mode/auto.cpp
        light/bh/mode/auto.hpp
        light/bh/types/imode.hpp
        light/bh/mode/low.cpp
        light/bh/mode/low.hpp
        light/bh/mode/high.cpp
        light/bh/mode/high.hpp

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
        pressure/bmp/compensation/compensator.cpp
        pressure/bmp/bmp_280.cpp

        compass/gy/gy_271.cpp
        compass/gy/gy_271.hpp
        compass/gy/types/imode.hpp
        compass/gy/configurator.cpp
        compass/gy/configurator.hpp
        compass/gy/types/iodr.hpp
        compass/gy/types/irng.hpp
        compass/gy/types/iosr.hpp
        compass/gy/mode/stand_by.cpp
        compass/gy/mode/stand_by.hpp
        compass/gy/mode/continuous.cpp
        compass/gy/mode/continuous.hpp
        compass/gy/odr/odr_10.cpp
        compass/gy/odr/odr_10.hpp
        compass/gy/odr/odr_50.cpp
        compass/gy/odr/odr_50.hpp
        compass/gy/odr/odr_100.cpp
        compass/gy/odr/odr_100.hpp
        compass/gy/odr/odr_200.cpp
        compass/gy/odr/odr_200.hpp
        compass/gy/rng/rng_2.cpp
        compass/gy/rng/rng_2.hpp
        compass/gy/rng/rng_8.cpp
        compass/gy/rng/rng_8.hpp
        compass/gy/osr/osr_512.cpp
        compass/gy/osr/osr_512.hpp
        compass/gy/osr/osr_256.cpp
        compass/gy/osr/osr_256.hpp
        compass/gy/osr/osr_128.cpp
        compass/gy/osr/osr_128.hpp
        compass/gy/osr/osr_64.cpp
        compass/gy/osr/osr_64.hpp

        accel/mpu/mpu_6050.cpp
        accel/mpu/mpu_6050.hpp
        accel/mpu/configurator.cpp
        accel/mpu/configurator.hpp

        accel/mpu/types/iconfig.hpp
        accel/mpu/config/fifo/enable/first.cpp
        accel/mpu/config/fifo/enable/first.hpp
        accel/mpu/config/fifo/control/first.cpp
        accel/mpu/config/fifo/control/first.hpp
        accel/mpu/config/fifo/configurator.cpp
        accel/mpu/config/fifo/configurator.hpp
        accel/mpu/config/devices/configurator.cpp
        accel/mpu/config/devices/configurator.hpp
        accel/mpu/config/devices/general/first.cpp
        accel/mpu/config/devices/general/first.hpp
        accel/mpu/config/devices/gyro/first.cpp
        accel/mpu/config/devices/gyro/first.hpp
        accel/mpu/config/power/general_reset/first.cpp
        accel/mpu/config/power/general_reset/first.hpp
        accel/mpu/config/power/device_reset/first.cpp
        accel/mpu/config/power/device_reset/first.hpp accel/mpu/config/power/configurator.cpp accel/mpu/config/power/configurator.hpp accel/mpu/config/devices/accel/first.cpp accel/mpu/config/devices/accel/first.hpp accel/mpu/builder/first.cpp accel/mpu/builder/first.hpp)
include_directories(.)
add_library( ${PROJECT_NAME} ${SOURCES} )

if( NOT RUN_TEST )
    target_link_libraries( ${PROJECT_NAME} CMSIS::STM32::F407VG STM32::NoSys )
endif()