# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.24.1/bin/cmake

# The command to remove a file.
RM = /home/linuxbrew/.linuxbrew/Cellar/cmake/3.24.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jaros/gitProjects/c++/TDgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jaros/gitProjects/c++/TDgame/build

# Include any dependencies generated for this target.
include CMakeFiles/TowerDefence.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TowerDefence.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TowerDefence.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TowerDefence.dir/flags.make

CMakeFiles/TowerDefence.dir/src/Base.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/Base.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/Base.cpp
CMakeFiles/TowerDefence.dir/src/Base.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TowerDefence.dir/src/Base.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/Base.cpp.o -MF CMakeFiles/TowerDefence.dir/src/Base.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/Base.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/Base.cpp

CMakeFiles/TowerDefence.dir/src/Base.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/Base.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/Base.cpp > CMakeFiles/TowerDefence.dir/src/Base.cpp.i

CMakeFiles/TowerDefence.dir/src/Base.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/Base.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/Base.cpp -o CMakeFiles/TowerDefence.dir/src/Base.cpp.s

CMakeFiles/TowerDefence.dir/src/main.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/main.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/main.cpp
CMakeFiles/TowerDefence.dir/src/main.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TowerDefence.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/main.cpp.o -MF CMakeFiles/TowerDefence.dir/src/main.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/main.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/main.cpp

CMakeFiles/TowerDefence.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/main.cpp > CMakeFiles/TowerDefence.dir/src/main.cpp.i

CMakeFiles/TowerDefence.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/main.cpp -o CMakeFiles/TowerDefence.dir/src/main.cpp.s

CMakeFiles/TowerDefence.dir/src/Game.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/Game.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/Game.cpp
CMakeFiles/TowerDefence.dir/src/Game.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TowerDefence.dir/src/Game.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/Game.cpp.o -MF CMakeFiles/TowerDefence.dir/src/Game.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/Game.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/Game.cpp

CMakeFiles/TowerDefence.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/Game.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/Game.cpp > CMakeFiles/TowerDefence.dir/src/Game.cpp.i

CMakeFiles/TowerDefence.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/Game.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/Game.cpp -o CMakeFiles/TowerDefence.dir/src/Game.cpp.s

CMakeFiles/TowerDefence.dir/src/Timers.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/Timers.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/Timers.cpp
CMakeFiles/TowerDefence.dir/src/Timers.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TowerDefence.dir/src/Timers.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/Timers.cpp.o -MF CMakeFiles/TowerDefence.dir/src/Timers.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/Timers.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/Timers.cpp

CMakeFiles/TowerDefence.dir/src/Timers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/Timers.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/Timers.cpp > CMakeFiles/TowerDefence.dir/src/Timers.cpp.i

CMakeFiles/TowerDefence.dir/src/Timers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/Timers.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/Timers.cpp -o CMakeFiles/TowerDefence.dir/src/Timers.cpp.s

CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/EnemiesWay.cpp
CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o -MF CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/EnemiesWay.cpp

CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/EnemiesWay.cpp > CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.i

CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/EnemiesWay.cpp -o CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.s

CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/approximateComparison.cpp
CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o -MF CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/approximateComparison.cpp

CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/approximateComparison.cpp > CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.i

CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/approximateComparison.cpp -o CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.s

CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Enemy.cpp
CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o -MF CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Enemy.cpp

CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Enemy.cpp > CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.i

CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Enemy.cpp -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.s

CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/enemies/BasicEnemy.cpp
CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o -MF CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/enemies/BasicEnemy.cpp

CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/enemies/BasicEnemy.cpp > CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.i

CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/enemies/BasicEnemy.cpp -o CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.s

CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Tower.cpp
CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o -MF CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Tower.cpp

CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Tower.cpp > CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.i

CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Tower.cpp -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.s

CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/towers/BasicTower.cpp
CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o -MF CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/towers/BasicTower.cpp

CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/towers/BasicTower.cpp > CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.i

CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/towers/BasicTower.cpp -o CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.s

CMakeFiles/TowerDefence.dir/src/Grid.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/Grid.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/Grid.cpp
CMakeFiles/TowerDefence.dir/src/Grid.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/TowerDefence.dir/src/Grid.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/Grid.cpp.o -MF CMakeFiles/TowerDefence.dir/src/Grid.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/Grid.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/Grid.cpp

CMakeFiles/TowerDefence.dir/src/Grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/Grid.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/Grid.cpp > CMakeFiles/TowerDefence.dir/src/Grid.cpp.i

CMakeFiles/TowerDefence.dir/src/Grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/Grid.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/Grid.cpp -o CMakeFiles/TowerDefence.dir/src/Grid.cpp.s

CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/entityManagers/EnemyManager.cpp
CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o -MF CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/entityManagers/EnemyManager.cpp

CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/entityManagers/EnemyManager.cpp > CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.i

CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/entityManagers/EnemyManager.cpp -o CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.s

CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Projectile.cpp
CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o -MF CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Projectile.cpp

CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Projectile.cpp > CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.i

CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/abstractClasses/Projectile.cpp -o CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.s

CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/GridTile.cpp
CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o -MF CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/GridTile.cpp

CMakeFiles/TowerDefence.dir/src/GridTile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/GridTile.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/GridTile.cpp > CMakeFiles/TowerDefence.dir/src/GridTile.cpp.i

CMakeFiles/TowerDefence.dir/src/GridTile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/GridTile.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/GridTile.cpp -o CMakeFiles/TowerDefence.dir/src/GridTile.cpp.s

CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o: CMakeFiles/TowerDefence.dir/flags.make
CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o: /home/jaros/gitProjects/c++/TDgame/src/entityManagers/TowerManager.cpp
CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o: CMakeFiles/TowerDefence.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o -MF CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o.d -o CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o -c /home/jaros/gitProjects/c++/TDgame/src/entityManagers/TowerManager.cpp

CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jaros/gitProjects/c++/TDgame/src/entityManagers/TowerManager.cpp > CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.i

CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jaros/gitProjects/c++/TDgame/src/entityManagers/TowerManager.cpp -o CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.s

# Object files for target TowerDefence
TowerDefence_OBJECTS = \
"CMakeFiles/TowerDefence.dir/src/Base.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/main.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/Game.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/Timers.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/Grid.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o" \
"CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o"

# External object files for target TowerDefence
TowerDefence_EXTERNAL_OBJECTS =

TowerDefence: CMakeFiles/TowerDefence.dir/src/Base.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/main.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/Game.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/Timers.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/EnemiesWay.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/approximateComparison.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/abstractClasses/Enemy.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/enemies/BasicEnemy.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/abstractClasses/Tower.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/towers/BasicTower.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/Grid.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/entityManagers/EnemyManager.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/abstractClasses/Projectile.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/GridTile.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/src/entityManagers/TowerManager.cpp.o
TowerDefence: CMakeFiles/TowerDefence.dir/build.make
TowerDefence: libs/SDL/libSDL2maind.a
TowerDefence: libs/SDL/libSDL2d.a
TowerDefence: CMakeFiles/TowerDefence.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jaros/gitProjects/c++/TDgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Linking CXX executable TowerDefence"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TowerDefence.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TowerDefence.dir/build: TowerDefence
.PHONY : CMakeFiles/TowerDefence.dir/build

CMakeFiles/TowerDefence.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TowerDefence.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TowerDefence.dir/clean

CMakeFiles/TowerDefence.dir/depend:
	cd /home/jaros/gitProjects/c++/TDgame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jaros/gitProjects/c++/TDgame /home/jaros/gitProjects/c++/TDgame /home/jaros/gitProjects/c++/TDgame/build /home/jaros/gitProjects/c++/TDgame/build /home/jaros/gitProjects/c++/TDgame/build/CMakeFiles/TowerDefence.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TowerDefence.dir/depend

