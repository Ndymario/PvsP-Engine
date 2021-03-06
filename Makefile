# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.19.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.19.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ndymario/Desktop/Programming/C/PvsP-Engine/PvsP-Engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ndymario/Desktop/Programming/C/PvsP-Engine/PvsP-Engine

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.19.1/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.19.1/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/ndymario/Desktop/Programming/C/PvsP-Engine/PvsP-Engine/CMakeFiles /Users/ndymario/Desktop/Programming/C/PvsP-Engine/PvsP-Engine//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/ndymario/Desktop/Programming/C/PvsP-Engine/PvsP-Engine/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named pvsp_engine

# Build rule for target.
pvsp_engine: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 pvsp_engine
.PHONY : pvsp_engine

# fast build rule for target.
pvsp_engine/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/build
.PHONY : pvsp_engine/fast

src/assetManager.o: src/assetManager.cpp.o

.PHONY : src/assetManager.o

# target to build an object file
src/assetManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/assetManager.cpp.o
.PHONY : src/assetManager.cpp.o

src/assetManager.i: src/assetManager.cpp.i

.PHONY : src/assetManager.i

# target to preprocess a source file
src/assetManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/assetManager.cpp.i
.PHONY : src/assetManager.cpp.i

src/assetManager.s: src/assetManager.cpp.s

.PHONY : src/assetManager.s

# target to generate assembly for a file
src/assetManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/assetManager.cpp.s
.PHONY : src/assetManager.cpp.s

src/entity.o: src/entity.cpp.o

.PHONY : src/entity.o

# target to build an object file
src/entity.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/entity.cpp.o
.PHONY : src/entity.cpp.o

src/entity.i: src/entity.cpp.i

.PHONY : src/entity.i

# target to preprocess a source file
src/entity.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/entity.cpp.i
.PHONY : src/entity.cpp.i

src/entity.s: src/entity.cpp.s

.PHONY : src/entity.s

# target to generate assembly for a file
src/entity.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/entity.cpp.s
.PHONY : src/entity.cpp.s

src/gameplay.o: src/gameplay.cpp.o

.PHONY : src/gameplay.o

# target to build an object file
src/gameplay.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/gameplay.cpp.o
.PHONY : src/gameplay.cpp.o

src/gameplay.i: src/gameplay.cpp.i

.PHONY : src/gameplay.i

# target to preprocess a source file
src/gameplay.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/gameplay.cpp.i
.PHONY : src/gameplay.cpp.i

src/gameplay.s: src/gameplay.cpp.s

.PHONY : src/gameplay.s

# target to generate assembly for a file
src/gameplay.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/gameplay.cpp.s
.PHONY : src/gameplay.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/mdl.o: src/mdl.cpp.o

.PHONY : src/mdl.o

# target to build an object file
src/mdl.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/mdl.cpp.o
.PHONY : src/mdl.cpp.o

src/mdl.i: src/mdl.cpp.i

.PHONY : src/mdl.i

# target to preprocess a source file
src/mdl.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/mdl.cpp.i
.PHONY : src/mdl.cpp.i

src/mdl.s: src/mdl.cpp.s

.PHONY : src/mdl.s

# target to generate assembly for a file
src/mdl.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/mdl.cpp.s
.PHONY : src/mdl.cpp.s

src/player.o: src/player.cpp.o

.PHONY : src/player.o

# target to build an object file
src/player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/player.cpp.o
.PHONY : src/player.cpp.o

src/player.i: src/player.cpp.i

.PHONY : src/player.i

# target to preprocess a source file
src/player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/player.cpp.i
.PHONY : src/player.cpp.i

src/player.s: src/player.cpp.s

.PHONY : src/player.s

# target to generate assembly for a file
src/player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/player.cpp.s
.PHONY : src/player.cpp.s

src/pvpScene.o: src/pvpScene.cpp.o

.PHONY : src/pvpScene.o

# target to build an object file
src/pvpScene.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/pvpScene.cpp.o
.PHONY : src/pvpScene.cpp.o

src/pvpScene.i: src/pvpScene.cpp.i

.PHONY : src/pvpScene.i

# target to preprocess a source file
src/pvpScene.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/pvpScene.cpp.i
.PHONY : src/pvpScene.cpp.i

src/pvpScene.s: src/pvpScene.cpp.s

.PHONY : src/pvpScene.s

# target to generate assembly for a file
src/pvpScene.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/pvpScene.cpp.s
.PHONY : src/pvpScene.cpp.s

src/scene.o: src/scene.cpp.o

.PHONY : src/scene.o

# target to build an object file
src/scene.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/scene.cpp.o
.PHONY : src/scene.cpp.o

src/scene.i: src/scene.cpp.i

.PHONY : src/scene.i

# target to preprocess a source file
src/scene.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/scene.cpp.i
.PHONY : src/scene.cpp.i

src/scene.s: src/scene.cpp.s

.PHONY : src/scene.s

# target to generate assembly for a file
src/scene.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/scene.cpp.s
.PHONY : src/scene.cpp.s

src/screen.o: src/screen.cpp.o

.PHONY : src/screen.o

# target to build an object file
src/screen.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/screen.cpp.o
.PHONY : src/screen.cpp.o

src/screen.i: src/screen.cpp.i

.PHONY : src/screen.i

# target to preprocess a source file
src/screen.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/screen.cpp.i
.PHONY : src/screen.cpp.i

src/screen.s: src/screen.cpp.s

.PHONY : src/screen.s

# target to generate assembly for a file
src/screen.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/screen.cpp.s
.PHONY : src/screen.cpp.s

src/tile.o: src/tile.cpp.o

.PHONY : src/tile.o

# target to build an object file
src/tile.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/tile.cpp.o
.PHONY : src/tile.cpp.o

src/tile.i: src/tile.cpp.i

.PHONY : src/tile.i

# target to preprocess a source file
src/tile.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/tile.cpp.i
.PHONY : src/tile.cpp.i

src/tile.s: src/tile.cpp.s

.PHONY : src/tile.s

# target to generate assembly for a file
src/tile.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/tile.cpp.s
.PHONY : src/tile.cpp.s

src/titleScreen.o: src/titleScreen.cpp.o

.PHONY : src/titleScreen.o

# target to build an object file
src/titleScreen.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/titleScreen.cpp.o
.PHONY : src/titleScreen.cpp.o

src/titleScreen.i: src/titleScreen.cpp.i

.PHONY : src/titleScreen.i

# target to preprocess a source file
src/titleScreen.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/titleScreen.cpp.i
.PHONY : src/titleScreen.cpp.i

src/titleScreen.s: src/titleScreen.cpp.s

.PHONY : src/titleScreen.s

# target to generate assembly for a file
src/titleScreen.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/titleScreen.cpp.s
.PHONY : src/titleScreen.cpp.s

src/ui.o: src/ui.cpp.o

.PHONY : src/ui.o

# target to build an object file
src/ui.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/ui.cpp.o
.PHONY : src/ui.cpp.o

src/ui.i: src/ui.cpp.i

.PHONY : src/ui.i

# target to preprocess a source file
src/ui.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/ui.cpp.i
.PHONY : src/ui.cpp.i

src/ui.s: src/ui.cpp.s

.PHONY : src/ui.s

# target to generate assembly for a file
src/ui.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/pvsp_engine.dir/build.make CMakeFiles/pvsp_engine.dir/src/ui.cpp.s
.PHONY : src/ui.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... pvsp_engine"
	@echo "... src/assetManager.o"
	@echo "... src/assetManager.i"
	@echo "... src/assetManager.s"
	@echo "... src/entity.o"
	@echo "... src/entity.i"
	@echo "... src/entity.s"
	@echo "... src/gameplay.o"
	@echo "... src/gameplay.i"
	@echo "... src/gameplay.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/mdl.o"
	@echo "... src/mdl.i"
	@echo "... src/mdl.s"
	@echo "... src/player.o"
	@echo "... src/player.i"
	@echo "... src/player.s"
	@echo "... src/pvpScene.o"
	@echo "... src/pvpScene.i"
	@echo "... src/pvpScene.s"
	@echo "... src/scene.o"
	@echo "... src/scene.i"
	@echo "... src/scene.s"
	@echo "... src/screen.o"
	@echo "... src/screen.i"
	@echo "... src/screen.s"
	@echo "... src/tile.o"
	@echo "... src/tile.i"
	@echo "... src/tile.s"
	@echo "... src/titleScreen.o"
	@echo "... src/titleScreen.i"
	@echo "... src/titleScreen.s"
	@echo "... src/ui.o"
	@echo "... src/ui.i"
	@echo "... src/ui.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
