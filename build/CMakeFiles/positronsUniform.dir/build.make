# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/polina/B1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/polina/B1/build

# Include any dependencies generated for this target.
include CMakeFiles/positronsUniform.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/positronsUniform.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/positronsUniform.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/positronsUniform.dir/flags.make

CMakeFiles/positronsUniform.dir/exampleB1.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/exampleB1.cc.o: ../exampleB1.cc
CMakeFiles/positronsUniform.dir/exampleB1.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/positronsUniform.dir/exampleB1.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/exampleB1.cc.o -MF CMakeFiles/positronsUniform.dir/exampleB1.cc.o.d -o CMakeFiles/positronsUniform.dir/exampleB1.cc.o -c /home/polina/B1/exampleB1.cc

CMakeFiles/positronsUniform.dir/exampleB1.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/exampleB1.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/exampleB1.cc > CMakeFiles/positronsUniform.dir/exampleB1.cc.i

CMakeFiles/positronsUniform.dir/exampleB1.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/exampleB1.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/exampleB1.cc -o CMakeFiles/positronsUniform.dir/exampleB1.cc.s

CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o: ../src/ActionInitialization.cc
CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o -MF CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o.d -o CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o -c /home/polina/B1/src/ActionInitialization.cc

CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/ActionInitialization.cc > CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.i

CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/ActionInitialization.cc -o CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.s

CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o -MF CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o.d -o CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o -c /home/polina/B1/src/DetectorConstruction.cc

CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/DetectorConstruction.cc > CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.i

CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/DetectorConstruction.cc -o CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.s

CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o: ../src/PhysicsList.cc
CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o -MF CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o.d -o CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o -c /home/polina/B1/src/PhysicsList.cc

CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/PhysicsList.cc > CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.i

CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/PhysicsList.cc -o CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.s

CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o: ../src/PmtSD.cc
CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o -MF CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o.d -o CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o -c /home/polina/B1/src/PmtSD.cc

CMakeFiles/positronsUniform.dir/src/PmtSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/PmtSD.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/PmtSD.cc > CMakeFiles/positronsUniform.dir/src/PmtSD.cc.i

CMakeFiles/positronsUniform.dir/src/PmtSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/PmtSD.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/PmtSD.cc -o CMakeFiles/positronsUniform.dir/src/PmtSD.cc.s

CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o -MF CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o.d -o CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o -c /home/polina/B1/src/PrimaryGeneratorAction.cc

CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/PrimaryGeneratorAction.cc > CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/PrimaryGeneratorAction.cc -o CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/positronsUniform.dir/src/RunAction.cc.o: CMakeFiles/positronsUniform.dir/flags.make
CMakeFiles/positronsUniform.dir/src/RunAction.cc.o: ../src/RunAction.cc
CMakeFiles/positronsUniform.dir/src/RunAction.cc.o: CMakeFiles/positronsUniform.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/positronsUniform.dir/src/RunAction.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/positronsUniform.dir/src/RunAction.cc.o -MF CMakeFiles/positronsUniform.dir/src/RunAction.cc.o.d -o CMakeFiles/positronsUniform.dir/src/RunAction.cc.o -c /home/polina/B1/src/RunAction.cc

CMakeFiles/positronsUniform.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/positronsUniform.dir/src/RunAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polina/B1/src/RunAction.cc > CMakeFiles/positronsUniform.dir/src/RunAction.cc.i

CMakeFiles/positronsUniform.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/positronsUniform.dir/src/RunAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polina/B1/src/RunAction.cc -o CMakeFiles/positronsUniform.dir/src/RunAction.cc.s

# Object files for target positronsUniform
positronsUniform_OBJECTS = \
"CMakeFiles/positronsUniform.dir/exampleB1.cc.o" \
"CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o" \
"CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o" \
"CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o" \
"CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/positronsUniform.dir/src/RunAction.cc.o"

# External object files for target positronsUniform
positronsUniform_EXTERNAL_OBJECTS =

positronsUniform: CMakeFiles/positronsUniform.dir/exampleB1.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/ActionInitialization.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/DetectorConstruction.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/PhysicsList.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/PmtSD.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/PrimaryGeneratorAction.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/src/RunAction.cc.o
positronsUniform: CMakeFiles/positronsUniform.dir/build.make
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4Tree.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4FR.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4GMocren.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4visHepRep.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4RayTracer.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4VRML.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4ToolsSG.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4OpenGL.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4vis_management.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4modeling.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4interfaces.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4mctruth.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4geomtext.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4error_propagation.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4readout.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4physicslists.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4run.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4event.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4tracking.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4parmodels.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4processes.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4digits_hits.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4track.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4particles.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4geometry.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4materials.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4graphics_reps.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libGL.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
positronsUniform: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
positronsUniform: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
positronsUniform: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
positronsUniform: /usr/lib/x86_64-linux-gnu/libXmu.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libXext.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libXt.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libICE.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libSM.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libX11.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4analysis.so
positronsUniform: /usr/lib/x86_64-linux-gnu/libexpat.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4zlib.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4intercoms.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4global.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4clhep.so
positronsUniform: /home/polina/GEANT4/geant4-v11.2.2-install/lib/libG4ptl.so.2.3.3
positronsUniform: CMakeFiles/positronsUniform.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/polina/B1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable positronsUniform"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/positronsUniform.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/positronsUniform.dir/build: positronsUniform
.PHONY : CMakeFiles/positronsUniform.dir/build

CMakeFiles/positronsUniform.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/positronsUniform.dir/cmake_clean.cmake
.PHONY : CMakeFiles/positronsUniform.dir/clean

CMakeFiles/positronsUniform.dir/depend:
	cd /home/polina/B1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/polina/B1 /home/polina/B1 /home/polina/B1/build /home/polina/B1/build /home/polina/B1/build/CMakeFiles/positronsUniform.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/positronsUniform.dir/depend
