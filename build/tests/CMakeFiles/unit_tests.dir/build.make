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
CMAKE_SOURCE_DIR = /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/unit_tests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/unit_tests.dir/flags.make

tests/CMakeFiles/unit_tests.dir/main.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/main.cpp.o: ../tests/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/unit_tests.dir/main.cpp.o"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/main.cpp.o -c /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/main.cpp

tests/CMakeFiles/unit_tests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/main.cpp.i"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/main.cpp > CMakeFiles/unit_tests.dir/main.cpp.i

tests/CMakeFiles/unit_tests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/main.cpp.s"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/main.cpp -o CMakeFiles/unit_tests.dir/main.cpp.s

tests/CMakeFiles/unit_tests.dir/dummy.cpp.o: tests/CMakeFiles/unit_tests.dir/flags.make
tests/CMakeFiles/unit_tests.dir/dummy.cpp.o: ../tests/dummy.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/unit_tests.dir/dummy.cpp.o"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit_tests.dir/dummy.cpp.o -c /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/dummy.cpp

tests/CMakeFiles/unit_tests.dir/dummy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit_tests.dir/dummy.cpp.i"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/dummy.cpp > CMakeFiles/unit_tests.dir/dummy.cpp.i

tests/CMakeFiles/unit_tests.dir/dummy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit_tests.dir/dummy.cpp.s"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests/dummy.cpp -o CMakeFiles/unit_tests.dir/dummy.cpp.s

# Object files for target unit_tests
unit_tests_OBJECTS = \
"CMakeFiles/unit_tests.dir/main.cpp.o" \
"CMakeFiles/unit_tests.dir/dummy.cpp.o"

# External object files for target unit_tests
unit_tests_EXTERNAL_OBJECTS = \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/example.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Cuboid.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/GeometricSolid.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Matrix3x3.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Vector3D.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Prism6.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Drone.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Scene.cpp.o" \
"/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles/program.dir/src/Peak.cpp.o"

unit_tests: tests/CMakeFiles/unit_tests.dir/main.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/dummy.cpp.o
unit_tests: CMakeFiles/program.dir/src/example.cpp.o
unit_tests: CMakeFiles/program.dir/src/lacze_do_gnuplota.cpp.o
unit_tests: CMakeFiles/program.dir/src/Cuboid.cpp.o
unit_tests: CMakeFiles/program.dir/src/GeometricSolid.cpp.o
unit_tests: CMakeFiles/program.dir/src/Matrix3x3.cpp.o
unit_tests: CMakeFiles/program.dir/src/Vector3D.cpp.o
unit_tests: CMakeFiles/program.dir/src/Prism6.cpp.o
unit_tests: CMakeFiles/program.dir/src/Drone.cpp.o
unit_tests: CMakeFiles/program.dir/src/Scene.cpp.o
unit_tests: CMakeFiles/program.dir/src/Peak.cpp.o
unit_tests: tests/CMakeFiles/unit_tests.dir/build.make
unit_tests: tests/CMakeFiles/unit_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../unit_tests"
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/unit_tests.dir/build: unit_tests

.PHONY : tests/CMakeFiles/unit_tests.dir/build

tests/CMakeFiles/unit_tests.dir/clean:
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/unit_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/unit_tests.dir/clean

tests/CMakeFiles/unit_tests.dir/depend:
	cd /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/tests /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests /home/kamil/Pulpit/po/rep1/zad5_2-Orlowski-K/build/tests/CMakeFiles/unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/unit_tests.dir/depend

