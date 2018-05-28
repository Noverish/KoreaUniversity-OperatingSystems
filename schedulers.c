//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include <stdio.h>
#include "schedulers.h"
#include "options.h"
#include "print.h"

Process first_come_first_served(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    return (*ready_queue)->process;
}

Process shortest_job_first_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    do {
        if (min->cpu_burst_time > now->process->cpu_burst_time)
            min = now->process;
    } while ((now = now->next) != NULL);

    return min;
}

Process shortest_job_first_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    do {
        if (min->cpu_burst_time > now->process->cpu_burst_time)
            min = now->process;
    } while ((now = now->next) != NULL);

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return min;
}

Process priority_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    do {
        if (highest->priority < now->process->priority)
            highest = now->process;
    } while ((now = now->next) != NULL);

    return highest;
}

Process priority_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    do {
        if (highest->priority < now->process->priority)
            highest = now->process;
    } while ((now = now->next) != NULL);

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return highest;
}

Process round_robin(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;

    do {
        printf("1\n");
        __print_schedule_pointers(schedules);
        if (now->process->continuous_cpu_burst_time == ROUND_ROBIN_TIME_QUANTUM) {
            printf("2\n");
            __print_schedule_pointers(schedules);
            remove_from_queue(ready_queue, now->process);
            printf("3\n");
            __print_schedule_pointers(schedules);
            add_to_queue(ready_queue, now->process);
            printf("4\n");
            __print_schedule_pointers(schedules);
            now->process->continuous_cpu_burst_time = 0;
            printf("5\n");
            __print_schedule_pointers(schedules);
            now = *ready_queue;
            printf("6\n");
            __print_schedule_pointers(schedules);
        } else {
            printf("7\n");
            __print_schedule_pointers(schedules);
            return now->process;
        }
    } while (now != NULL);

    return NULL;
}

Process shortest_remaining_time_first_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    do {
        if (min->cpu_burst_time > now->process->cpu_burst_time)
            min = now->process;
    } while ((now = now->next) != NULL);

    return min;
}

Process shortest_remaining_time_first_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    do {
        if (min->cpu_burst_time > now->process->cpu_burst_time)
            min = now->process;
    } while ((now = now->next) != NULL);

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return min;
}

Process highest_response_ratio_next_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    do {
        double highest_priority = ((double) highest->waiting_time + highest->cpu_burst_time) / highest->cpu_burst_time;
        double now_priority =
                ((double) now->process->waiting_time + now->process->cpu_burst_time) / now->process->cpu_burst_time;

        if (highest_priority < now_priority)
            highest = now->process;
    } while ((now = now->next) != NULL);

    return highest;
}

Process highest_response_ratio_next_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue)) return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    do {
        double highest_priority = ((double) highest->waiting_time + highest->cpu_burst_time) / highest->cpu_burst_time;
        double now_priority =
                ((double) now->process->waiting_time + now->process->cpu_burst_time) / now->process->cpu_burst_time;

        if (highest_priority < now_priority)
            highest = now->process;
    } while ((now = now->next) != NULL);

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return highest;
}