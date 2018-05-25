cmake_minimum_required(VERSION 3.8)
project(CPU_Scheduling_Simulator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c utils.c utils.h processes.c processes.h options.h queues.c queues.h schedulers.c schedulers.h)
add_executable(CPU_Scheduling_Simulator ${SOURCE_FILES})