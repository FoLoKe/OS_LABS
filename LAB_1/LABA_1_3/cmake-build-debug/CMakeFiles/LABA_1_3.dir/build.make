# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/home/FoLoKe/Рабочий стол/clion-2020.3/bin/cmake/linux/bin/cmake"

# The command to remove a file.
RM = "/home/FoLoKe/Рабочий стол/clion-2020.3/bin/cmake/linux/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LABA_1_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LABA_1_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LABA_1_3.dir/flags.make

CMakeFiles/LABA_1_3.dir/main.c.o: CMakeFiles/LABA_1_3.dir/flags.make
CMakeFiles/LABA_1_3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LABA_1_3.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LABA_1_3.dir/main.c.o   -c /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/main.c

CMakeFiles/LABA_1_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LABA_1_3.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/main.c > CMakeFiles/LABA_1_3.dir/main.c.i

CMakeFiles/LABA_1_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LABA_1_3.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/main.c -o CMakeFiles/LABA_1_3.dir/main.c.s

# Object files for target LABA_1_3
LABA_1_3_OBJECTS = \
"CMakeFiles/LABA_1_3.dir/main.c.o"

# External object files for target LABA_1_3
LABA_1_3_EXTERNAL_OBJECTS =

LABA_1_3: CMakeFiles/LABA_1_3.dir/main.c.o
LABA_1_3: CMakeFiles/LABA_1_3.dir/build.make
LABA_1_3: CMakeFiles/LABA_1_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LABA_1_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LABA_1_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LABA_1_3.dir/build: LABA_1_3

.PHONY : CMakeFiles/LABA_1_3.dir/build

CMakeFiles/LABA_1_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LABA_1_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LABA_1_3.dir/clean

CMakeFiles/LABA_1_3.dir/depend:
	cd /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3 /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3 /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug /home/FoLoKe/CLionProjects/OS_LABS/LAB_1/LABA_1_3/cmake-build-debug/CMakeFiles/LABA_1_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LABA_1_3.dir/depend

