cmake_minimum_required (VERSION 2.8)
set (CMAKE_BINARY_DIR ${./build})

#export (CC gcc)  
project (pseudo_uart C)
include_directories(inc)


file(GLOB LIB_FILES src/uart.c)
add_library(_uart STATIC ${LIB_FILES})

add_executable(test_uart src/test_uart.c)
exec_program(make [./])
target_link_libraries(test_uart _uart)



