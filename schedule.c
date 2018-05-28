//
// Created by Noverish Harold on 2018. 5. 26..
//

#include "schedule.h"
#include <stdio.h>
#include <stdlib.h>

Schedule create_schedule(Process p, BOOL io_occurred) {
    Schedule schedule = (Schedule) malloc(sizeof(struct _Schedule));
    schedule->process = p;
    schedule->io_occurred = io_occurred;
    schedule->next_schedule = NULL;
    return schedule;
}

void add_schedule(Schedule schedule, Process p, BOOL io_occurred) {
    Schedule now = schedule;
    while (now->next_schedule != NULL) {
        now = now->next_schedule;
    }
    now->next_schedule = create_schedule(p, io_occurred);
}

int schedule_size(Schedule schedule) {
    Schedule now = schedule;
    int size = 1;
    while (now->next_schedule != NULL) {
        size++;
        now = now->next_schedule;
    }
    return size;
}

void free_schedule(Schedule schedule) {
    Schedule now = schedule;
    while (now != NULL) {
        Schedule tmp = now->next_schedule;
        free(now);
        now = tmp;
    }
}

Schedule get_last_schedule(Schedule schedule) {
    Schedule now = schedule;
    while (now->next_schedule != NULL) {
        now = now->next_schedule;
    }
    return now;
}