# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\programming\cpp projects\books_library"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\programming\cpp projects\books_library\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/books_library.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/books_library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/books_library.dir/flags.make

CMakeFiles/books_library.dir/main.cpp.obj: CMakeFiles/books_library.dir/flags.make
CMakeFiles/books_library.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/books_library.dir/main.cpp.obj"
	D:\MinGW-v8\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\books_library.dir\main.cpp.obj -c "D:\programming\cpp projects\books_library\main.cpp"

CMakeFiles/books_library.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/books_library.dir/main.cpp.i"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\programming\cpp projects\books_library\main.cpp" > CMakeFiles\books_library.dir\main.cpp.i

CMakeFiles/books_library.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/books_library.dir/main.cpp.s"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\programming\cpp projects\books_library\main.cpp" -o CMakeFiles\books_library.dir\main.cpp.s

CMakeFiles/books_library.dir/adaptors.cpp.obj: CMakeFiles/books_library.dir/flags.make
CMakeFiles/books_library.dir/adaptors.cpp.obj: ../adaptors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/books_library.dir/adaptors.cpp.obj"
	D:\MinGW-v8\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\books_library.dir\adaptors.cpp.obj -c "D:\programming\cpp projects\books_library\adaptors.cpp"

CMakeFiles/books_library.dir/adaptors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/books_library.dir/adaptors.cpp.i"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\programming\cpp projects\books_library\adaptors.cpp" > CMakeFiles\books_library.dir\adaptors.cpp.i

CMakeFiles/books_library.dir/adaptors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/books_library.dir/adaptors.cpp.s"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\programming\cpp projects\books_library\adaptors.cpp" -o CMakeFiles\books_library.dir\adaptors.cpp.s

CMakeFiles/books_library.dir/entities.cpp.obj: CMakeFiles/books_library.dir/flags.make
CMakeFiles/books_library.dir/entities.cpp.obj: ../entities.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/books_library.dir/entities.cpp.obj"
	D:\MinGW-v8\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\books_library.dir\entities.cpp.obj -c "D:\programming\cpp projects\books_library\entities.cpp"

CMakeFiles/books_library.dir/entities.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/books_library.dir/entities.cpp.i"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\programming\cpp projects\books_library\entities.cpp" > CMakeFiles\books_library.dir\entities.cpp.i

CMakeFiles/books_library.dir/entities.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/books_library.dir/entities.cpp.s"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\programming\cpp projects\books_library\entities.cpp" -o CMakeFiles\books_library.dir\entities.cpp.s

CMakeFiles/books_library.dir/ui.cpp.obj: CMakeFiles/books_library.dir/flags.make
CMakeFiles/books_library.dir/ui.cpp.obj: ../ui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/books_library.dir/ui.cpp.obj"
	D:\MinGW-v8\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\books_library.dir\ui.cpp.obj -c "D:\programming\cpp projects\books_library\ui.cpp"

CMakeFiles/books_library.dir/ui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/books_library.dir/ui.cpp.i"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\programming\cpp projects\books_library\ui.cpp" > CMakeFiles\books_library.dir\ui.cpp.i

CMakeFiles/books_library.dir/ui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/books_library.dir/ui.cpp.s"
	D:\MinGW-v8\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\programming\cpp projects\books_library\ui.cpp" -o CMakeFiles\books_library.dir\ui.cpp.s

# Object files for target books_library
books_library_OBJECTS = \
"CMakeFiles/books_library.dir/main.cpp.obj" \
"CMakeFiles/books_library.dir/adaptors.cpp.obj" \
"CMakeFiles/books_library.dir/entities.cpp.obj" \
"CMakeFiles/books_library.dir/ui.cpp.obj"

# External object files for target books_library
books_library_EXTERNAL_OBJECTS =

books_library.exe: CMakeFiles/books_library.dir/main.cpp.obj
books_library.exe: CMakeFiles/books_library.dir/adaptors.cpp.obj
books_library.exe: CMakeFiles/books_library.dir/entities.cpp.obj
books_library.exe: CMakeFiles/books_library.dir/ui.cpp.obj
books_library.exe: CMakeFiles/books_library.dir/build.make
books_library.exe: CMakeFiles/books_library.dir/linklibs.rsp
books_library.exe: CMakeFiles/books_library.dir/objects1.rsp
books_library.exe: CMakeFiles/books_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable books_library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\books_library.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/books_library.dir/build: books_library.exe

.PHONY : CMakeFiles/books_library.dir/build

CMakeFiles/books_library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\books_library.dir\cmake_clean.cmake
.PHONY : CMakeFiles/books_library.dir/clean

CMakeFiles/books_library.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\programming\cpp projects\books_library" "D:\programming\cpp projects\books_library" "D:\programming\cpp projects\books_library\cmake-build-debug" "D:\programming\cpp projects\books_library\cmake-build-debug" "D:\programming\cpp projects\books_library\cmake-build-debug\CMakeFiles\books_library.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/books_library.dir/depend
