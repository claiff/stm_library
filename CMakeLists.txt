cmake_minimum_required(VERSION 3.22)
project(library C CXX ASM)
set(CMAKE_CXX_STANDARD 17)

set( CMAKE_C_COMPILER arm-none-eabi-gcc )
set( CMAKE_CXX_COMPILER arm-none-eabi-g++ )
set( CMAKE_ASM_COMPILER arm-none-eabi-gcc )
set( CMAKE_AR arm-none-eabi-ar )
set( CMAKE_OBJCOPY arm-none-eabi-objcopy )
set( CMAKE_OBJDUMP arm-none-eabi-objdump )
set( SIZE arm-none-eabi-size )

add_compile_options( -mcpu=cortex-m4 -mthumb -mthumb-interwork )
add_compile_options( -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 )
add_compile_options( -O0 )

set( MISC_DIR misc )
set( LINKER_SCRIPT ${MISC_DIR}/STM32F407VGTx_FLASH.ld )

include_directories(.)

set(UART_DIR uart)
set(RCC_DIR rcc)
set(GPIO_DIR gpio)
set(TYPES_DIR types)


set(SRC
        ${MISC_DIR}/startup_stm32f407xx.s
        ${MISC_DIR}/stm32f407xx.h

        ${RCC_DIR}/simple_rcc.cpp
        ${RCC_DIR}/simple_rcc.hpp

        ${GPIO_DIR}/gpio_init.cpp
        ${GPIO_DIR}/gpio_init.hpp
        ${GPIO_DIR}/alternative_function/alternative_function.cpp
        ${GPIO_DIR}/alternative_function/alternative_function.hpp
        ${GPIO_DIR}/modes/alternative_mode.cpp
        ${GPIO_DIR}/modes/alternative_mode.hpp
        ${GPIO_DIR}/modes/analog_mode.cpp
        ${GPIO_DIR}/modes/analog_mode.hpp
        ${GPIO_DIR}/modes/input_mode.cpp
        ${GPIO_DIR}/modes/input_mode.hpp
        ${GPIO_DIR}/modes/output_mode.cpp
        ${GPIO_DIR}/modes/output_mode.hpp
        ${GPIO_DIR}/output_type/open_drain.cpp
        ${GPIO_DIR}/output_type/open_drain.hpp
        ${GPIO_DIR}/output_type/push_pull.cpp
        ${GPIO_DIR}/output_type/push_pull.hpp
        ${GPIO_DIR}/pull/no_pull.cpp
        ${GPIO_DIR}/pull/no_pull.hpp
        ${GPIO_DIR}/pull/pull_down.cpp
        ${GPIO_DIR}/pull/pull_down.hpp
        ${GPIO_DIR}/pull/pull_up.cpp
        ${GPIO_DIR}/pull/pull_up.hpp
        ${GPIO_DIR}/speed/high_speed.cpp
        ${GPIO_DIR}/speed/high_speed.hpp
        ${GPIO_DIR}/speed/low_speed.cpp
        ${GPIO_DIR}/speed/low_speed.hpp
        ${GPIO_DIR}/speed/medium_speed.cpp
        ${GPIO_DIR}/speed/medium_speed.hpp
        ${GPIO_DIR}/speed/very_high_speed.cpp
        ${GPIO_DIR}/speed/very_high_speed.hpp
        ${GPIO_DIR}/types/gpio_afr.hpp
        ${GPIO_DIR}/types/gpio_general.cpp
        ${GPIO_DIR}/types/gpio_general.hpp
        ${GPIO_DIR}/types/gpio_mode.cpp
        ${GPIO_DIR}/types/gpio_mode.hpp
        ${GPIO_DIR}/types/gpio_output_type.cpp
        ${GPIO_DIR}/types/gpio_output_type.hpp
        ${GPIO_DIR}/types/gpio_pull.hpp
        ${GPIO_DIR}/types/gpio_speed.cpp
        ${GPIO_DIR}/types/gpio_speed.hpp
        ${GPIO_DIR}/types/periphery_init.hpp

        ${UART_DIR}/subject.cpp
        ${UART_DIR}/subject.hpp
        ${UART_DIR}/pins.cpp
        ${UART_DIR}/pins.hpp

        ${TYPES_DIR}/ircc.cpp
        ${TYPES_DIR}/ircc.hpp

        )

add_link_options( -Wl,-gc-sections,--print-memory-usage,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map )
add_link_options( -mcpu=cortex-m4 -mthumb -mthumb-interwork )
add_link_options( -T ${LINKER_SCRIPT} )
add_link_options( -specs=nosys.specs -specs=nano.specs -T ${LINKER_SCRIPT} )

add_library(library SHARED ${SRC})
