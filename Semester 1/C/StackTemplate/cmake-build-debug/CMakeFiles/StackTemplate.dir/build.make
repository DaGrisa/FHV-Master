# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/StackTemplate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/StackTemplate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/StackTemplate.dir/flags.make

CMakeFiles/StackTemplate.dir/main.cpp.o: CMakeFiles/StackTemplate.dir/flags.make
CMakeFiles/StackTemplate.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/StackTemplate.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/StackTemplate.dir/main.cpp.o -c "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/main.cpp"

CMakeFiles/StackTemplate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/StackTemplate.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/main.cpp" > CMakeFiles/StackTemplate.dir/main.cpp.i

CMakeFiles/StackTemplate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/StackTemplate.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/main.cpp" -o CMakeFiles/StackTemplate.dir/main.cpp.s

CMakeFiles/StackTemplate.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/StackTemplate.dir/main.cpp.o.requires

CMakeFiles/StackTemplate.dir/main.cpp.o.provides: CMakeFiles/StackTemplate.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/StackTemplate.dir/build.make CMakeFiles/StackTemplate.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/StackTemplate.dir/main.cpp.o.provides

CMakeFiles/StackTemplate.dir/main.cpp.o.provides.build: CMakeFiles/StackTemplate.dir/main.cpp.o


# Object files for target StackTemplate
StackTemplate_OBJECTS = \
"CMakeFiles/StackTemplate.dir/main.cpp.o"

# External object files for target StackTemplate
StackTemplate_EXTERNAL_OBJECTS =

StackTemplate: CMakeFiles/StackTemplate.dir/main.cpp.o
StackTemplate: CMakeFiles/StackTemplate.dir/build.make
StackTemplate: CMakeFiles/StackTemplate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable StackTemplate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/StackTemplate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/StackTemplate.dir/build: StackTemplate

.PHONY : CMakeFiles/StackTemplate.dir/build

CMakeFiles/StackTemplate.dir/requires: CMakeFiles/StackTemplate.dir/main.cpp.o.requires

.PHONY : CMakeFiles/StackTemplate.dir/requires

CMakeFiles/StackTemplate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/StackTemplate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/StackTemplate.dir/clean

CMakeFiles/StackTemplate.dir/depend:
	cd "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate" "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate" "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug" "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug" "/Users/daniel/FHV-Master/Semester 1/C/StackTemplate/cmake-build-debug/CMakeFiles/StackTemplate.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/StackTemplate.dir/depend

