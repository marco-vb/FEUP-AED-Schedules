# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/schedule.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/schedule.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/schedule.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/schedule.dir/flags.make

CMakeFiles/schedule.dir/main.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/main.cpp.obj: ../main.cpp
CMakeFiles/schedule.dir/main.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/schedule.dir/main.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/main.cpp.obj -MF CMakeFiles\schedule.dir\main.cpp.obj.d -o CMakeFiles\schedule.dir\main.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\main.cpp

CMakeFiles/schedule.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/main.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\main.cpp > CMakeFiles\schedule.dir\main.cpp.i

CMakeFiles/schedule.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/main.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\main.cpp -o CMakeFiles\schedule.dir\main.cpp.s

CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj: ../definitions/ClassCourse.cpp
CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj -MF CMakeFiles\schedule.dir\definitions\ClassCourse.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\ClassCourse.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassCourse.cpp

CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassCourse.cpp > CMakeFiles\schedule.dir\definitions\ClassCourse.cpp.i

CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassCourse.cpp -o CMakeFiles\schedule.dir\definitions\ClassCourse.cpp.s

CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj: ../definitions/ClassSchedule.cpp
CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj -MF CMakeFiles\schedule.dir\definitions\ClassSchedule.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\ClassSchedule.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassSchedule.cpp

CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassSchedule.cpp > CMakeFiles\schedule.dir\definitions\ClassSchedule.cpp.i

CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ClassSchedule.cpp -o CMakeFiles\schedule.dir\definitions\ClassSchedule.cpp.s

CMakeFiles/schedule.dir/definitions/Request.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/Request.cpp.obj: ../definitions/Request.cpp
CMakeFiles/schedule.dir/definitions/Request.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/schedule.dir/definitions/Request.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/Request.cpp.obj -MF CMakeFiles\schedule.dir\definitions\Request.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\Request.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Request.cpp

CMakeFiles/schedule.dir/definitions/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/Request.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Request.cpp > CMakeFiles\schedule.dir\definitions\Request.cpp.i

CMakeFiles/schedule.dir/definitions/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/Request.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Request.cpp -o CMakeFiles\schedule.dir\definitions\Request.cpp.s

CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj: ../definitions/ScheduleManagement.cpp
CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj -MF CMakeFiles\schedule.dir\definitions\ScheduleManagement.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\ScheduleManagement.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ScheduleManagement.cpp

CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ScheduleManagement.cpp > CMakeFiles\schedule.dir\definitions\ScheduleManagement.cpp.i

CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\ScheduleManagement.cpp -o CMakeFiles\schedule.dir\definitions\ScheduleManagement.cpp.s

CMakeFiles/schedule.dir/definitions/Slot.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/Slot.cpp.obj: ../definitions/Slot.cpp
CMakeFiles/schedule.dir/definitions/Slot.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/schedule.dir/definitions/Slot.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/Slot.cpp.obj -MF CMakeFiles\schedule.dir\definitions\Slot.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\Slot.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Slot.cpp

CMakeFiles/schedule.dir/definitions/Slot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/Slot.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Slot.cpp > CMakeFiles\schedule.dir\definitions\Slot.cpp.i

CMakeFiles/schedule.dir/definitions/Slot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/Slot.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Slot.cpp -o CMakeFiles\schedule.dir\definitions\Slot.cpp.s

CMakeFiles/schedule.dir/definitions/Student.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/Student.cpp.obj: ../definitions/Student.cpp
CMakeFiles/schedule.dir/definitions/Student.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/schedule.dir/definitions/Student.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/Student.cpp.obj -MF CMakeFiles\schedule.dir\definitions\Student.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\Student.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Student.cpp

CMakeFiles/schedule.dir/definitions/Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/Student.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Student.cpp > CMakeFiles\schedule.dir\definitions\Student.cpp.i

CMakeFiles/schedule.dir/definitions/Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/Student.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\Student.cpp -o CMakeFiles\schedule.dir\definitions\Student.cpp.s

CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj: CMakeFiles/schedule.dir/flags.make
CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj: ../definitions/WeeklySchedule.cpp
CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj: CMakeFiles/schedule.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj -MF CMakeFiles\schedule.dir\definitions\WeeklySchedule.cpp.obj.d -o CMakeFiles\schedule.dir\definitions\WeeklySchedule.cpp.obj -c E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\WeeklySchedule.cpp

CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.i"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\WeeklySchedule.cpp > CMakeFiles\schedule.dir\definitions\WeeklySchedule.cpp.i

CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.s"
	C:\Users\Lenovo\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\definitions\WeeklySchedule.cpp -o CMakeFiles\schedule.dir\definitions\WeeklySchedule.cpp.s

# Object files for target schedule
schedule_OBJECTS = \
"CMakeFiles/schedule.dir/main.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/Request.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/Slot.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/Student.cpp.obj" \
"CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj"

# External object files for target schedule
schedule_EXTERNAL_OBJECTS =

schedule.exe: CMakeFiles/schedule.dir/main.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/ClassCourse.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/ClassSchedule.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/Request.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/ScheduleManagement.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/Slot.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/Student.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/definitions/WeeklySchedule.cpp.obj
schedule.exe: CMakeFiles/schedule.dir/build.make
schedule.exe: CMakeFiles/schedule.dir/linklibs.rsp
schedule.exe: CMakeFiles/schedule.dir/objects1.rsp
schedule.exe: CMakeFiles/schedule.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable schedule.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\schedule.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/schedule.dir/build: schedule.exe
.PHONY : CMakeFiles/schedule.dir/build

CMakeFiles/schedule.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\schedule.dir\cmake_clean.cmake
.PHONY : CMakeFiles/schedule.dir/clean

CMakeFiles/schedule.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug E:\trabalhos(2)\FEUP\2o_ano_1o_semestre\AED\AED-Schedule\cmake-build-debug\CMakeFiles\schedule.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/schedule.dir/depend

