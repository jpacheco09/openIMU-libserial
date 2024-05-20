find_package(Catch2 3 REQUIRED)

set(TEST_BINARY ${PROJECT_NAME}_test)

add_executable(${TEST_BINARY} 
                test_libserial_port.cpp
                test_main.cpp
                )

target_link_libraries(${TEST_BINARY} PRIVATE Catch2::Catch2WithMain openIMU_serial_port)

include(CTest)
include(Catch)

catch_discover_tests(${TEST_BINARY})