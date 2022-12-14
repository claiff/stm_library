cmake_minimum_required( VERSION 3.19 )
set( RUN_TEST OFF )

if(NOT RUN_TEST)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/stm32-cmake/cmake/stm32_gcc.cmake)
    set(STM32_TOOLCHAIN_PATH /usr/arm-none-eabi)
endif()

project( library C CXX ASM )

set( CMAKE_CXX_STANDARD 17 )

if(NOT RUN_TEST)
    set(STM32_CUBE_F4_PATH /home/claiff/STM32Cube/Repository/STM32Cube_FW_F4_V1.25.2)
    find_package(CMSIS COMPONENTS STM32F407VG REQUIRED)
endif()

set(SOURCES
    main.cpp
    )

add_executable( ${PROJECT_NAME}  ${SOURCES} )

include_directories( periphery )
include_directories( devices )

add_subdirectory( devices )
add_subdirectory( periphery )

if( RUN_TEST )
    add_subdirectory( tests )
endif()

target_link_libraries( ${PROJECT_NAME} periphery_library devices_library )

if(NOT RUN_TEST)
    stm32_print_size_of_target(${PROJECT_NAME})
endif()
