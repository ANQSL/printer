# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\project\Qt\printer\printerv1.1\clinet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\project\Qt\printer\printerv1.1\clinet\build

# Include any dependencies generated for this target.
include CMakeFiles/printclinet.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/printclinet.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/printclinet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/printclinet.dir/flags.make

CMakeFiles/printclinet.dir/main.cpp.obj: CMakeFiles/printclinet.dir/flags.make
CMakeFiles/printclinet.dir/main.cpp.obj: CMakeFiles/printclinet.dir/includes_CXX.rsp
CMakeFiles/printclinet.dir/main.cpp.obj: D:/project/Qt/printer/printerv1.1/clinet/main.cpp
CMakeFiles/printclinet.dir/main.cpp.obj: CMakeFiles/printclinet.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project\Qt\printer\printerv1.1\clinet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/printclinet.dir/main.cpp.obj"
	D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/printclinet.dir/main.cpp.obj -MF CMakeFiles\printclinet.dir\main.cpp.obj.d -o CMakeFiles\printclinet.dir\main.cpp.obj -c D:\project\Qt\printer\printerv1.1\clinet\main.cpp

CMakeFiles/printclinet.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/printclinet.dir/main.cpp.i"
	D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\project\Qt\printer\printerv1.1\clinet\main.cpp > CMakeFiles\printclinet.dir\main.cpp.i

CMakeFiles/printclinet.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/printclinet.dir/main.cpp.s"
	D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\project\Qt\printer\printerv1.1\clinet\main.cpp -o CMakeFiles\printclinet.dir\main.cpp.s

# Object files for target printclinet
printclinet_OBJECTS = \
"CMakeFiles/printclinet.dir/main.cpp.obj"

# External object files for target printclinet
printclinet_EXTERNAL_OBJECTS =

bin/printclinet.exe: CMakeFiles/printclinet.dir/main.cpp.obj
bin/printclinet.exe: CMakeFiles/printclinet.dir/build.make
bin/printclinet.exe: ui/libui.a
bin/printclinet.exe: clinet/libclinet.a
bin/printclinet.exe: data/libencodedecode.a
bin/printclinet.exe: D:/Qt5.14.2/5.14.2/mingw73_64/lib/libQt5Widgets.a
bin/printclinet.exe: D:/Qt5.14.2/5.14.2/mingw73_64/lib/libQt5Gui.a
bin/printclinet.exe: D:/Qt5.14.2/5.14.2/mingw73_64/lib/libQt5Network.a
bin/printclinet.exe: D:/Qt5.14.2/5.14.2/mingw73_64/lib/libQt5Core.a
bin/printclinet.exe: CMakeFiles/printclinet.dir/linkLibs.rsp
bin/printclinet.exe: CMakeFiles/printclinet.dir/objects1
bin/printclinet.exe: CMakeFiles/printclinet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\project\Qt\printer\printerv1.1\clinet\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\printclinet.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\printclinet.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/printclinet.dir/build: bin/printclinet.exe
.PHONY : CMakeFiles/printclinet.dir/build

CMakeFiles/printclinet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\printclinet.dir\cmake_clean.cmake
.PHONY : CMakeFiles/printclinet.dir/clean

CMakeFiles/printclinet.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\project\Qt\printer\printerv1.1\clinet D:\project\Qt\printer\printerv1.1\clinet D:\project\Qt\printer\printerv1.1\clinet\build D:\project\Qt\printer\printerv1.1\clinet\build D:\project\Qt\printer\printerv1.1\clinet\build\CMakeFiles\printclinet.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/printclinet.dir/depend
