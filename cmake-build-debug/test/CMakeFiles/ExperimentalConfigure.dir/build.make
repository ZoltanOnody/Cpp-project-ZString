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
CMAKE_COMMAND = /home/zoli/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/zoli/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zoli/AIN/programming3/semestral_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zoli/AIN/programming3/semestral_project/cmake-build-debug

# Utility rule file for ExperimentalConfigure.

# Include the progress variables for this target.
include test/CMakeFiles/ExperimentalConfigure.dir/progress.make

test/CMakeFiles/ExperimentalConfigure:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test && /home/zoli/clion-2016.3/bin/cmake/bin/ctest -D ExperimentalConfigure

ExperimentalConfigure: test/CMakeFiles/ExperimentalConfigure
ExperimentalConfigure: test/CMakeFiles/ExperimentalConfigure.dir/build.make

.PHONY : ExperimentalConfigure

# Rule to build all files generated by this target.
test/CMakeFiles/ExperimentalConfigure.dir/build: ExperimentalConfigure

.PHONY : test/CMakeFiles/ExperimentalConfigure.dir/build

test/CMakeFiles/ExperimentalConfigure.dir/clean:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/ExperimentalConfigure.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/ExperimentalConfigure.dir/clean

test/CMakeFiles/ExperimentalConfigure.dir/depend:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zoli/AIN/programming3/semestral_project /home/zoli/AIN/programming3/semestral_project/test /home/zoli/AIN/programming3/semestral_project/cmake-build-debug /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test/CMakeFiles/ExperimentalConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/ExperimentalConfigure.dir/depend
