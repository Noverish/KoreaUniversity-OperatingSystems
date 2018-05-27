//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include "schedulers.h"

Process first_come_first_served(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    return (*ready_queue)->process;
}

Process shortest_job_first_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    while(now != NULL) {
        if (min->remaining_cpu_burst_time > now->process->remaining_cpu_burst_time) {
            min = now->process;
        }

        now = now->next;
    }

    return min;
}

Process shortest_job_first_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    ProcessQueueNode now = *ready_queue;
    Process min = now->process;

    while(now != NULL) {
        if (min->remaining_cpu_burst_time > now->process->remaining_cpu_burst_time) {
            min = now->process;
        }

        now = now->next;
    }

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return min;
}

Process priority_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    while(now != NULL) {
        if(highest->priority < now->process->priority)
            highest = now->process;

        now = now->next;
    }

    return highest;
}

Process priority_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    ProcessQueueNode now = *ready_queue;
    Process highest = now->process;

    while(now != NULL) {
        if(highest->priority < now->process->priority)
            highest = now->process;

        now = now->next;
    }

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return highest;
}