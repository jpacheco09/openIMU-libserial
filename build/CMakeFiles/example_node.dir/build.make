# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jpacheco/workspaces/cpp_dev/openIMU-libserial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build

# Include any dependencies generated for this target.
include CMakeFiles/example_node.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_node.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_node.dir/flags.make

CMakeFiles/example_node.dir/src/main.cpp.o: CMakeFiles/example_node.dir/flags.make
CMakeFiles/example_node.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_node.dir/src/main.cpp.o"
	/usr/lib/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_node.dir/src/main.cpp.o -c /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/src/main.cpp

CMakeFiles/example_node.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_node.dir/src/main.cpp.i"
	/usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/src/main.cpp > CMakeFiles/example_node.dir/src/main.cpp.i

CMakeFiles/example_node.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_node.dir/src/main.cpp.s"
	/usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/src/main.cpp -o CMakeFiles/example_node.dir/src/main.cpp.s

# Object files for target example_node
example_node_OBJECTS = \
"CMakeFiles/example_node.dir/src/main.cpp.o"

# External object files for target example_node
example_node_EXTERNAL_OBJECTS =

example_node: CMakeFiles/example_node.dir/src/main.cpp.o
example_node: CMakeFiles/example_node.dir/build.make
example_node: CMakeFiles/example_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_node"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_node.dir/build: example_node

.PHONY : CMakeFiles/example_node.dir/build

CMakeFiles/example_node.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_node.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_node.dir/clean

CMakeFiles/example_node.dir/depend:
	cd /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jpacheco/workspaces/cpp_dev/openIMU-libserial /home/jpacheco/workspaces/cpp_dev/openIMU-libserial /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build /home/jpacheco/workspaces/cpp_dev/openIMU-libserial/build/CMakeFiles/example_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_node.dir/depend

