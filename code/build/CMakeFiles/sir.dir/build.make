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
CMAKE_SOURCE_DIR = /mnt/g/Dropbox/pesquisa/SIR-SM/code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/Dropbox/pesquisa/SIR-SM/code/build

# Include any dependencies generated for this target.
include CMakeFiles/sir.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sir.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sir.dir/flags.make

CMakeFiles/sir.dir/sir.c.o: CMakeFiles/sir.dir/flags.make
CMakeFiles/sir.dir/sir.c.o: ../sir.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/Dropbox/pesquisa/SIR-SM/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sir.dir/sir.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sir.dir/sir.c.o   -c /mnt/g/Dropbox/pesquisa/SIR-SM/code/sir.c

CMakeFiles/sir.dir/sir.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sir.dir/sir.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g/Dropbox/pesquisa/SIR-SM/code/sir.c > CMakeFiles/sir.dir/sir.c.i

CMakeFiles/sir.dir/sir.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sir.dir/sir.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g/Dropbox/pesquisa/SIR-SM/code/sir.c -o CMakeFiles/sir.dir/sir.c.s

CMakeFiles/sir.dir/random.c.o: CMakeFiles/sir.dir/flags.make
CMakeFiles/sir.dir/random.c.o: ../random.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/Dropbox/pesquisa/SIR-SM/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sir.dir/random.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sir.dir/random.c.o   -c /mnt/g/Dropbox/pesquisa/SIR-SM/code/random.c

CMakeFiles/sir.dir/random.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sir.dir/random.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g/Dropbox/pesquisa/SIR-SM/code/random.c > CMakeFiles/sir.dir/random.c.i

CMakeFiles/sir.dir/random.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sir.dir/random.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g/Dropbox/pesquisa/SIR-SM/code/random.c -o CMakeFiles/sir.dir/random.c.s

CMakeFiles/sir.dir/rede.c.o: CMakeFiles/sir.dir/flags.make
CMakeFiles/sir.dir/rede.c.o: ../rede.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/Dropbox/pesquisa/SIR-SM/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sir.dir/rede.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sir.dir/rede.c.o   -c /mnt/g/Dropbox/pesquisa/SIR-SM/code/rede.c

CMakeFiles/sir.dir/rede.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sir.dir/rede.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/g/Dropbox/pesquisa/SIR-SM/code/rede.c > CMakeFiles/sir.dir/rede.c.i

CMakeFiles/sir.dir/rede.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sir.dir/rede.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/g/Dropbox/pesquisa/SIR-SM/code/rede.c -o CMakeFiles/sir.dir/rede.c.s

# Object files for target sir
sir_OBJECTS = \
"CMakeFiles/sir.dir/sir.c.o" \
"CMakeFiles/sir.dir/random.c.o" \
"CMakeFiles/sir.dir/rede.c.o"

# External object files for target sir
sir_EXTERNAL_OBJECTS =

sir: CMakeFiles/sir.dir/sir.c.o
sir: CMakeFiles/sir.dir/random.c.o
sir: CMakeFiles/sir.dir/rede.c.o
sir: CMakeFiles/sir.dir/build.make
sir: CMakeFiles/sir.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/Dropbox/pesquisa/SIR-SM/code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable sir"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sir.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sir.dir/build: sir

.PHONY : CMakeFiles/sir.dir/build

CMakeFiles/sir.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sir.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sir.dir/clean

CMakeFiles/sir.dir/depend:
	cd /mnt/g/Dropbox/pesquisa/SIR-SM/code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/Dropbox/pesquisa/SIR-SM/code /mnt/g/Dropbox/pesquisa/SIR-SM/code /mnt/g/Dropbox/pesquisa/SIR-SM/code/build /mnt/g/Dropbox/pesquisa/SIR-SM/code/build /mnt/g/Dropbox/pesquisa/SIR-SM/code/build/CMakeFiles/sir.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sir.dir/depend

