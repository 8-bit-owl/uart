cmake_minimum_required (VERSION 3.5)   

project(uart)

set (CMAKE_BINARY_DIR "../")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "./build")
  
include_directories(inc)
file(GLOB LIB_FILES src/uart.c)

# Create a library for UART to make it portable
add_library(_uart STATIC ${LIB_FILES})
add_executable(test_uart src/test_uart.c)

#Link it to our test application
target_link_libraries(test_uart _uart)



