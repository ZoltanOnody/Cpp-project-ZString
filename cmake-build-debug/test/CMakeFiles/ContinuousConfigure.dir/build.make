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

# Utility rule file for ContinuousConfigure.

# Include the progress variables for this target.
include test/CMakeFiles/ContinuousConfigure.dir/progress.make

test/CMakeFiles/ContinuousConfigure:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test && /home/zoli/clion-2016.3/bin/cmake/bin/ctest -D ContinuousConfigure

ContinuousConfigure: test/CMakeFiles/ContinuousConfigure
ContinuousConfigure: test/CMakeFiles/ContinuousConfigure.dir/build.make

.PHONY : ContinuousConfigure

# Rule to build all files generated by this target.
test/CMakeFiles/ContinuousConfigure.dir/build: ContinuousConfigure

.PHONY : test/CMakeFiles/ContinuousConfigure.dir/build

test/CMakeFiles/ContinuousConfigure.dir/clean:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/ContinuousConfigure.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/ContinuousConfigure.dir/clean

test/CMakeFiles/ContinuousConfigure.dir/depend:
	cd /home/zoli/AIN/programming3/semestral_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zoli/AIN/programming3/semestral_project /home/zoli/AIN/programming3/semestral_project/test /home/zoli/AIN/programming3/semestral_project/cmake-build-debug /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test /home/zoli/AIN/programming3/semestral_project/cmake-build-debug/test/CMakeFiles/ContinuousConfigure.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/ContinuousConfigure.dir/depend

