# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/julien/Documents/master2/FIG/Projet/git/FIG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julien/Documents/master2/FIG/Projet/git/FIG/include

# Include any dependencies generated for this target.
include CMakeFiles/fig.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fig.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fig.dir/flags.make

CMakeFiles/fig.dir/src/main.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fig.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/main.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/main.cpp

CMakeFiles/fig.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/main.cpp > CMakeFiles/fig.dir/src/main.cpp.i

CMakeFiles/fig.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/main.cpp -o CMakeFiles/fig.dir/src/main.cpp.s

CMakeFiles/fig.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/main.cpp.o.requires

CMakeFiles/fig.dir/src/main.cpp.o.provides: CMakeFiles/fig.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/main.cpp.o.provides

CMakeFiles/fig.dir/src/main.cpp.o.provides.build: CMakeFiles/fig.dir/src/main.cpp.o


CMakeFiles/fig.dir/src/mainwindow.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/mainwindow.cpp.o: ../src/mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fig.dir/src/mainwindow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/mainwindow.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/mainwindow.cpp

CMakeFiles/fig.dir/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/mainwindow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/mainwindow.cpp > CMakeFiles/fig.dir/src/mainwindow.cpp.i

CMakeFiles/fig.dir/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/mainwindow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/mainwindow.cpp -o CMakeFiles/fig.dir/src/mainwindow.cpp.s

CMakeFiles/fig.dir/src/mainwindow.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/mainwindow.cpp.o.requires

CMakeFiles/fig.dir/src/mainwindow.cpp.o.provides: CMakeFiles/fig.dir/src/mainwindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/mainwindow.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/mainwindow.cpp.o.provides

CMakeFiles/fig.dir/src/mainwindow.cpp.o.provides.build: CMakeFiles/fig.dir/src/mainwindow.cpp.o


CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o: ../src/meshviewerwidget.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/meshviewerwidget.cpp

CMakeFiles/fig.dir/src/meshviewerwidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/meshviewerwidget.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/meshviewerwidget.cpp > CMakeFiles/fig.dir/src/meshviewerwidget.cpp.i

CMakeFiles/fig.dir/src/meshviewerwidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/meshviewerwidget.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/meshviewerwidget.cpp -o CMakeFiles/fig.dir/src/meshviewerwidget.cpp.s

CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.requires

CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.provides: CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.provides

CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.provides.build: CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o


CMakeFiles/fig.dir/src/drawableobject.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/drawableobject.cpp.o: ../src/drawableobject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fig.dir/src/drawableobject.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/drawableobject.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/drawableobject.cpp

CMakeFiles/fig.dir/src/drawableobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/drawableobject.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/drawableobject.cpp > CMakeFiles/fig.dir/src/drawableobject.cpp.i

CMakeFiles/fig.dir/src/drawableobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/drawableobject.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/drawableobject.cpp -o CMakeFiles/fig.dir/src/drawableobject.cpp.s

CMakeFiles/fig.dir/src/drawableobject.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/drawableobject.cpp.o.requires

CMakeFiles/fig.dir/src/drawableobject.cpp.o.provides: CMakeFiles/fig.dir/src/drawableobject.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/drawableobject.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/drawableobject.cpp.o.provides

CMakeFiles/fig.dir/src/drawableobject.cpp.o.provides.build: CMakeFiles/fig.dir/src/drawableobject.cpp.o


CMakeFiles/fig.dir/src/axis.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/axis.cpp.o: ../src/axis.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/fig.dir/src/axis.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/axis.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/axis.cpp

CMakeFiles/fig.dir/src/axis.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/axis.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/axis.cpp > CMakeFiles/fig.dir/src/axis.cpp.i

CMakeFiles/fig.dir/src/axis.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/axis.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/axis.cpp -o CMakeFiles/fig.dir/src/axis.cpp.s

CMakeFiles/fig.dir/src/axis.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/axis.cpp.o.requires

CMakeFiles/fig.dir/src/axis.cpp.o.provides: CMakeFiles/fig.dir/src/axis.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/axis.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/axis.cpp.o.provides

CMakeFiles/fig.dir/src/axis.cpp.o.provides.build: CMakeFiles/fig.dir/src/axis.cpp.o


CMakeFiles/fig.dir/src/light.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/light.cpp.o: ../src/light.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/fig.dir/src/light.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/light.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/light.cpp

CMakeFiles/fig.dir/src/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/light.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/light.cpp > CMakeFiles/fig.dir/src/light.cpp.i

CMakeFiles/fig.dir/src/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/light.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/light.cpp -o CMakeFiles/fig.dir/src/light.cpp.s

CMakeFiles/fig.dir/src/light.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/light.cpp.o.requires

CMakeFiles/fig.dir/src/light.cpp.o.provides: CMakeFiles/fig.dir/src/light.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/light.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/light.cpp.o.provides

CMakeFiles/fig.dir/src/light.cpp.o.provides.build: CMakeFiles/fig.dir/src/light.cpp.o


CMakeFiles/fig.dir/src/arcball.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/arcball.cpp.o: ../src/arcball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/fig.dir/src/arcball.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/arcball.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/arcball.cpp

CMakeFiles/fig.dir/src/arcball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/arcball.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/arcball.cpp > CMakeFiles/fig.dir/src/arcball.cpp.i

CMakeFiles/fig.dir/src/arcball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/arcball.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/arcball.cpp -o CMakeFiles/fig.dir/src/arcball.cpp.s

CMakeFiles/fig.dir/src/arcball.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/arcball.cpp.o.requires

CMakeFiles/fig.dir/src/arcball.cpp.o.provides: CMakeFiles/fig.dir/src/arcball.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/arcball.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/arcball.cpp.o.provides

CMakeFiles/fig.dir/src/arcball.cpp.o.provides.build: CMakeFiles/fig.dir/src/arcball.cpp.o


CMakeFiles/fig.dir/src/cloud.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/src/cloud.cpp.o: ../src/cloud.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/fig.dir/src/cloud.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/src/cloud.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/src/cloud.cpp

CMakeFiles/fig.dir/src/cloud.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/src/cloud.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/src/cloud.cpp > CMakeFiles/fig.dir/src/cloud.cpp.i

CMakeFiles/fig.dir/src/cloud.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/src/cloud.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/src/cloud.cpp -o CMakeFiles/fig.dir/src/cloud.cpp.s

CMakeFiles/fig.dir/src/cloud.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/src/cloud.cpp.o.requires

CMakeFiles/fig.dir/src/cloud.cpp.o.provides: CMakeFiles/fig.dir/src/cloud.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/src/cloud.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/src/cloud.cpp.o.provides

CMakeFiles/fig.dir/src/cloud.cpp.o.provides.build: CMakeFiles/fig.dir/src/cloud.cpp.o


CMakeFiles/fig.dir/fig_automoc.cpp.o: CMakeFiles/fig.dir/flags.make
CMakeFiles/fig.dir/fig_automoc.cpp.o: fig_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/fig.dir/fig_automoc.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fig.dir/fig_automoc.cpp.o -c /home/julien/Documents/master2/FIG/Projet/git/FIG/include/fig_automoc.cpp

CMakeFiles/fig.dir/fig_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fig.dir/fig_automoc.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/julien/Documents/master2/FIG/Projet/git/FIG/include/fig_automoc.cpp > CMakeFiles/fig.dir/fig_automoc.cpp.i

CMakeFiles/fig.dir/fig_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fig.dir/fig_automoc.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/julien/Documents/master2/FIG/Projet/git/FIG/include/fig_automoc.cpp -o CMakeFiles/fig.dir/fig_automoc.cpp.s

CMakeFiles/fig.dir/fig_automoc.cpp.o.requires:

.PHONY : CMakeFiles/fig.dir/fig_automoc.cpp.o.requires

CMakeFiles/fig.dir/fig_automoc.cpp.o.provides: CMakeFiles/fig.dir/fig_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/fig.dir/build.make CMakeFiles/fig.dir/fig_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/fig.dir/fig_automoc.cpp.o.provides

CMakeFiles/fig.dir/fig_automoc.cpp.o.provides.build: CMakeFiles/fig.dir/fig_automoc.cpp.o


# Object files for target fig
fig_OBJECTS = \
"CMakeFiles/fig.dir/src/main.cpp.o" \
"CMakeFiles/fig.dir/src/mainwindow.cpp.o" \
"CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o" \
"CMakeFiles/fig.dir/src/drawableobject.cpp.o" \
"CMakeFiles/fig.dir/src/axis.cpp.o" \
"CMakeFiles/fig.dir/src/light.cpp.o" \
"CMakeFiles/fig.dir/src/arcball.cpp.o" \
"CMakeFiles/fig.dir/src/cloud.cpp.o" \
"CMakeFiles/fig.dir/fig_automoc.cpp.o"

# External object files for target fig
fig_EXTERNAL_OBJECTS =

fig: CMakeFiles/fig.dir/src/main.cpp.o
fig: CMakeFiles/fig.dir/src/mainwindow.cpp.o
fig: CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o
fig: CMakeFiles/fig.dir/src/drawableobject.cpp.o
fig: CMakeFiles/fig.dir/src/axis.cpp.o
fig: CMakeFiles/fig.dir/src/light.cpp.o
fig: CMakeFiles/fig.dir/src/arcball.cpp.o
fig: CMakeFiles/fig.dir/src/cloud.cpp.o
fig: CMakeFiles/fig.dir/fig_automoc.cpp.o
fig: CMakeFiles/fig.dir/build.make
fig: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.5.1
fig: /usr/lib/x86_64-linux-gnu/libGLU.so
fig: /usr/lib/x86_64-linux-gnu/libGL.so
fig: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.5.1
fig: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.5.1
fig: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
fig: CMakeFiles/fig.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable fig"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fig.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fig.dir/build: fig

.PHONY : CMakeFiles/fig.dir/build

CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/main.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/mainwindow.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/meshviewerwidget.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/drawableobject.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/axis.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/light.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/arcball.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/src/cloud.cpp.o.requires
CMakeFiles/fig.dir/requires: CMakeFiles/fig.dir/fig_automoc.cpp.o.requires

.PHONY : CMakeFiles/fig.dir/requires

CMakeFiles/fig.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fig.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fig.dir/clean

CMakeFiles/fig.dir/depend:
	cd /home/julien/Documents/master2/FIG/Projet/git/FIG/include && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julien/Documents/master2/FIG/Projet/git/FIG /home/julien/Documents/master2/FIG/Projet/git/FIG /home/julien/Documents/master2/FIG/Projet/git/FIG/include /home/julien/Documents/master2/FIG/Projet/git/FIG/include /home/julien/Documents/master2/FIG/Projet/git/FIG/include/CMakeFiles/fig.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fig.dir/depend

