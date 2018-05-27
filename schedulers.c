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

    Process *array = create_process_array_from_queue(ready_queue);
    Process min = array[0];
    int array_size = size_of_queue(ready_queue);
    int i;

    for (i = 0; i < array_size; i++) {
        Process p = array[i];
        if (min->remaining_cpu_burst_time > p->remaining_cpu_burst_time) {
            min = p;
        }
    }

    free(array);
    return min;
}

Process shortest_job_first_non_preemptive(ProcessQueue ready_queue, Process before_processed) {
    if (is_queue_empty(ready_queue))
        return NULL;

    Process *array = create_process_array_from_queue(ready_queue);
    Process min = array[0];
    int array_size = size_of_queue(ready_queue);
    int i;

    for (i = 0; i < array_size; i++) {
        Process p = array[i];
        if (min->remaining_cpu_burst_time > p->remaining_cpu_burst_time) {
            min = p;
        }
    }

    free(array);

    if (before_processed != NULL && is_process_in_queue(ready_queue, before_processed))
        return before_processed;
    else
        return min;
}
