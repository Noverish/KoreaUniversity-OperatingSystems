//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include "processes.h"
#include "queues.h"


typedef Process (*Scheduler)(ProcessQueue, ProcessQueue, Process *, uint32_t, int);

Process first_come_first_served(ProcessQueue ready_queue, ProcessQueue waiting_queue, Process *processes, uint32_t size,
                                int now_time);

extern int terminated_process_num;

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
