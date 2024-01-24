cmake_minimum_required(VERSION 3.10)

project(OpenIMU-Serial LANGUAGES C CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH $(PROJECT_SOURCE_DIR)/cmake)

set(THREADS_HAVE_PTHREAD_ARG 1)
find_package(Threads REQUIRED)

find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)

add_executable(example_node src/main.cpp)
target_include_directories(example_node PRIVATE ${SERIAL_INCLUDE_DIRS})
target_link_libraries(example_node PRIVATE ${SERIAL_LDFLAGS} ${CMAKE_THREAD_LIBS_INIT})


