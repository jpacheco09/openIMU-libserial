add_library(openIMU_serial_port LibSerialPort.cpp)

target_include_directories(openIMU_serial_port PRIVATE ${SERIAL_INCLUDE_DIRS})
target_link_libraries(openIMU_serial_port PRIVATE ${SERIAL_LDFLAGS} ${CMAKE_THREAD_LIBS_INIT})

add_executable(example_node main.cpp)
target_include_directories(example_node PRIVATE ${SERIAL_INCLUDE_DIRS})
target_link_libraries(example_node PRIVATE ${SERIAL_LDFLAGS} ${CMAKE_THREAD_LIBS_INIT})