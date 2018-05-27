//
// Created by Noverish Harold on 2018. 5. 26..
//

#ifndef CPU_SCHEDULING_SIMULATOR_SCHEDULE_H
#define CPU_SCHEDULING_SIMULATOR_SCHEDULE_H

#include "processes.h"
#include "utils.h"

struct _Schedule {
    Process process;
    BOOL io_occurred;
    struct _Schedule *next_schedule;
};
typedef struct _Schedule *Schedule;

Schedule create_schedule(Process p, BOOL io_occurred);

void add_schedule(Schedule schedule, Process p, BOOL io_occurred);

int schedule_size(Schedule schedule);

void free_schedule(Schedule schedule);

Schedule get_last_schedule(Schedule schedule);

#endif //CPU_SCHEDULING_SIMULATOR_SCHEDULE_H
