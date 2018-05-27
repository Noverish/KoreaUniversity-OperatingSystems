//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H

#include "processes.h"
#include "queues.h"


typedef Process (*Scheduler)(ProcessQueue, Process);

Process first_come_first_served(ProcessQueue, Process);

Process shortest_job_first_preemptive(ProcessQueue, Process);

Process shortest_job_first_non_preemptive(ProcessQueue, Process);

Process priority_preemptive(ProcessQueue, Process);

Process priority_non_preemptive(ProcessQueue, Process);

Process round_robin(ProcessQueue, Process);

extern int terminated_process_num;

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULERS_H
