//
// Created by Noverish Harold on 2018. 5. 26..
//

#ifndef CPU_SCHEDULING_SIMULATOR_PRINT_H
#define CPU_SCHEDULING_SIMULATOR_PRINT_H

#include "processes.h"
#include "schedule.h"
#include "queues.h"

void print_processes(Process *processes, int size);

void print_schedule(Schedule schedule);

void print_process_queue(ProcessQueue queue);

void __print_two_queues(ProcessQueue ready_queue, ProcessQueue waiting_queue);

#endif //CPU_SCHEDULING_SIMULATOR_PRINT_H
