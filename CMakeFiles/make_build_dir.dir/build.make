# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/danny/Documents/school/cpe400/gpu_simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/danny/Documents/school/cpe400/gpu_simulator

# Utility rule file for make_build_dir.

# Include any custom commands dependencies for this target.
include CMakeFiles/make_build_dir.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/make_build_dir.dir/progress.make

CMakeFiles/make_build_dir:
	/usr/bin/cmake -E make_directory build

make_build_dir: CMakeFiles/make_build_dir
make_build_dir: CMakeFiles/make_build_dir.dir/build.make
.PHONY : make_build_dir

# Rule to build all files generated by this target.
CMakeFiles/make_build_dir.dir/build: make_build_dir
.PHONY : CMakeFiles/make_build_dir.dir/build

CMakeFiles/make_build_dir.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/make_build_dir.dir/cmake_clean.cmake
.PHONY : CMakeFiles/make_build_dir.dir/clean

CMakeFiles/make_build_dir.dir/depend:
	cd /home/danny/Documents/school/cpe400/gpu_simulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/danny/Documents/school/cpe400/gpu_simulator /home/danny/Documents/school/cpe400/gpu_simulator /home/danny/Documents/school/cpe400/gpu_simulator /home/danny/Documents/school/cpe400/gpu_simulator /home/danny/Documents/school/cpe400/gpu_simulator/CMakeFiles/make_build_dir.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/make_build_dir.dir/depend

