# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/software/CMake/3.11.1-GCCcore-6.4.0/bin/cmake

# The command to remove a file.
RM = /opt/software/CMake/3.11.1-GCCcore-6.4.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/home/ganjaisa/c_workspace/uart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/home/ganjaisa/c_workspace/uart

# Include any dependencies generated for this target.
include CMakeFiles/test_uart.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_uart.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_uart.dir/flags.make

CMakeFiles/test_uart.dir/src/test_uart.c.o: CMakeFiles/test_uart.dir/flags.make
CMakeFiles/test_uart.dir/src/test_uart.c.o: src/test_uart.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/home/ganjaisa/c_workspace/uart/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_uart.dir/src/test_uart.c.o"
	/opt/software/GCCcore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_uart.dir/src/test_uart.c.o   -c /mnt/home/ganjaisa/c_workspace/uart/src/test_uart.c

CMakeFiles/test_uart.dir/src/test_uart.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_uart.dir/src/test_uart.c.i"
	/opt/software/GCCcore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/home/ganjaisa/c_workspace/uart/src/test_uart.c > CMakeFiles/test_uart.dir/src/test_uart.c.i

CMakeFiles/test_uart.dir/src/test_uart.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_uart.dir/src/test_uart.c.s"
	/opt/software/GCCcore/6.4.0/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/home/ganjaisa/c_workspace/uart/src/test_uart.c -o CMakeFiles/test_uart.dir/src/test_uart.c.s

# Object files for target test_uart
test_uart_OBJECTS = \
"CMakeFiles/test_uart.dir/src/test_uart.c.o"

# External object files for target test_uart
test_uart_EXTERNAL_OBJECTS =

test_uart: CMakeFiles/test_uart.dir/src/test_uart.c.o
test_uart: CMakeFiles/test_uart.dir/build.make
test_uart: lib_uart.a
test_uart: CMakeFiles/test_uart.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/home/ganjaisa/c_workspace/uart/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_uart"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_uart.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_uart.dir/build: test_uart

.PHONY : CMakeFiles/test_uart.dir/build

CMakeFiles/test_uart.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_uart.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_uart.dir/clean

CMakeFiles/test_uart.dir/depend:
	cd /mnt/home/ganjaisa/c_workspace/uart && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/home/ganjaisa/c_workspace/uart /mnt/home/ganjaisa/c_workspace/uart /mnt/home/ganjaisa/c_workspace/uart /mnt/home/ganjaisa/c_workspace/uart /mnt/home/ganjaisa/c_workspace/uart/CMakeFiles/test_uart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_uart.dir/depend
