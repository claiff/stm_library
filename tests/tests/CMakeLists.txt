include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(DEVICES_DIR devices)
set(PERIPHERY_DIR periphery)

add_executable( run_tests
                ${DEVICES_DIR}/debug/uart.cpp
                ${PERIPHERY_DIR}/parser/debug.cpp
                ${DEVICES_DIR}/light/bh_1721.cpp)

target_link_libraries( run_tests gtest gtest_main )
target_link_libraries( run_tests gmock gmock_main )
target_link_libraries( run_tests devices_library periphery_library )