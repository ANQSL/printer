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
CMAKE_SOURCE_DIR = D:\project\Qt\printer\printerv1.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\project\Qt\printer\printerv1.1\build

# Include any dependencies generated for this target.
include server/CMakeFiles/server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include server/CMakeFiles/server.dir/compiler_depend.make

# Include the progress variables for this target.
include server/CMakeFiles/server.dir/progress.make

# Include the compile flags for this target's objects.
include server/CMakeFiles/server.dir/flags.make

server/moc_server.cpp: D:/project/Qt/printer/printerv1.1/server/server.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=D:\project\Qt\printer\printerv1.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating moc_server.cpp"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\5.14.2\mingw73_64\bin\moc.exe @D:/project/Qt/printer/printerv1.1/build/server/moc_server.cpp_parameters

server/CMakeFiles/server.dir/config.cpp.obj: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/config.cpp.obj: server/CMakeFiles/server.dir/includes_CXX.rsp
server/CMakeFiles/server.dir/config.cpp.obj: D:/project/Qt/printer/printerv1.1/server/config.cpp
server/CMakeFiles/server.dir/config.cpp.obj: server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project\Qt\printer\printerv1.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object server/CMakeFiles/server.dir/config.cpp.obj"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT server/CMakeFiles/server.dir/config.cpp.obj -MF CMakeFiles\server.dir\config.cpp.obj.d -o CMakeFiles\server.dir\config.cpp.obj -c D:\project\Qt\printer\printerv1.1\server\config.cpp

server/CMakeFiles/server.dir/config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/config.cpp.i"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\project\Qt\printer\printerv1.1\server\config.cpp > CMakeFiles\server.dir\config.cpp.i

server/CMakeFiles/server.dir/config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/config.cpp.s"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\project\Qt\printer\printerv1.1\server\config.cpp -o CMakeFiles\server.dir\config.cpp.s

server/CMakeFiles/server.dir/server.cpp.obj: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/server.cpp.obj: server/CMakeFiles/server.dir/includes_CXX.rsp
server/CMakeFiles/server.dir/server.cpp.obj: D:/project/Qt/printer/printerv1.1/server/server.cpp
server/CMakeFiles/server.dir/server.cpp.obj: server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project\Qt\printer\printerv1.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object server/CMakeFiles/server.dir/server.cpp.obj"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT server/CMakeFiles/server.dir/server.cpp.obj -MF CMakeFiles\server.dir\server.cpp.obj.d -o CMakeFiles\server.dir\server.cpp.obj -c D:\project\Qt\printer\printerv1.1\server\server.cpp

server/CMakeFiles/server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/server.cpp.i"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\project\Qt\printer\printerv1.1\server\server.cpp > CMakeFiles\server.dir\server.cpp.i

server/CMakeFiles/server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/server.cpp.s"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\project\Qt\printer\printerv1.1\server\server.cpp -o CMakeFiles\server.dir\server.cpp.s

server/CMakeFiles/server.dir/moc_server.cpp.obj: server/CMakeFiles/server.dir/flags.make
server/CMakeFiles/server.dir/moc_server.cpp.obj: server/CMakeFiles/server.dir/includes_CXX.rsp
server/CMakeFiles/server.dir/moc_server.cpp.obj: server/moc_server.cpp
server/CMakeFiles/server.dir/moc_server.cpp.obj: server/CMakeFiles/server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\project\Qt\printer\printerv1.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object server/CMakeFiles/server.dir/moc_server.cpp.obj"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT server/CMakeFiles/server.dir/moc_server.cpp.obj -MF CMakeFiles\server.dir\moc_server.cpp.obj.d -o CMakeFiles\server.dir\moc_server.cpp.obj -c D:\project\Qt\printer\printerv1.1\build\server\moc_server.cpp

server/CMakeFiles/server.dir/moc_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server.dir/moc_server.cpp.i"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\project\Qt\printer\printerv1.1\build\server\moc_server.cpp > CMakeFiles\server.dir\moc_server.cpp.i

server/CMakeFiles/server.dir/moc_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server.dir/moc_server.cpp.s"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && D:\Qt5.14.2\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\project\Qt\printer\printerv1.1\build\server\moc_server.cpp -o CMakeFiles\server.dir\moc_server.cpp.s

# Object files for target server
server_OBJECTS = \
"CMakeFiles/server.dir/config.cpp.obj" \
"CMakeFiles/server.dir/server.cpp.obj" \
"CMakeFiles/server.dir/moc_server.cpp.obj"

# External object files for target server
server_EXTERNAL_OBJECTS =

server/libserver.a: server/CMakeFiles/server.dir/config.cpp.obj
server/libserver.a: server/CMakeFiles/server.dir/server.cpp.obj
server/libserver.a: server/CMakeFiles/server.dir/moc_server.cpp.obj
server/libserver.a: server/CMakeFiles/server.dir/build.make
server/libserver.a: server/CMakeFiles/server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\project\Qt\printer\printerv1.1\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libserver.a"
	cd /d D:\project\Qt\printer\printerv1.1\build\server && $(CMAKE_COMMAND) -P CMakeFiles\server.dir\cmake_clean_target.cmake
	cd /d D:\project\Qt\printer\printerv1.1\build\server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\server.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
server/CMakeFiles/server.dir/build: server/libserver.a
.PHONY : server/CMakeFiles/server.dir/build

server/CMakeFiles/server.dir/clean:
	cd /d D:\project\Qt\printer\printerv1.1\build\server && $(CMAKE_COMMAND) -P CMakeFiles\server.dir\cmake_clean.cmake
.PHONY : server/CMakeFiles/server.dir/clean

server/CMakeFiles/server.dir/depend: server/moc_server.cpp
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\project\Qt\printer\printerv1.1 D:\project\Qt\printer\printerv1.1\server D:\project\Qt\printer\printerv1.1\build D:\project\Qt\printer\printerv1.1\build\server D:\project\Qt\printer\printerv1.1\build\server\CMakeFiles\server.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : server/CMakeFiles/server.dir/depend

