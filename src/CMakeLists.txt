add_library(openIMU_serial_port LibSerialPort.cpp)

target_include_directories(openIMU_serial_port PRIVATE ${SERIAL_INCLUDE_DIRS})
target_link_libraries(openIMU_serial_port PRIVATE ${SERIAL_LDFLAGS} ${CMAKE_THREAD_LIBS_INIT})


