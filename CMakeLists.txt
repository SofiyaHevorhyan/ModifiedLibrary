cmake_minimum_required(VERSION 3.12)
project(create_library C)

set(CMAKE_C_STANDARD 99)
set(LIB_SRC library/lib_for_str.c)

add_library(mylib SHARED ${LIB_SRC})
add_executable(create_library main.c file_read.c file_read.h)
target_link_libraries(${PROJECT_NAME} mylib)