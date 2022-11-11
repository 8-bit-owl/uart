cmake_minimum_required (VERSION 3.5)   

project(uart)
set (CMAKE_BINARY_DIR "../build")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")
#export (CC gcc)  

include_directories(inc)


file(GLOB LIB_FILES src/uart.c)
add_library(_uart STATIC ${LIB_FILES})

add_executable(test_uart src/test_uart.c)
target_link_libraries(test_uart _uart)



