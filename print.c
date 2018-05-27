//
// Created by Noverish Harold on 2018. 5. 26..
//

#include <stdio.h>
#include <stdlib.h>
#include "print.h"

void print_processes(Process *processes, int size) {
    int i;
    printf("p_id | cpu |  io | arrive | priority\n");
    for (i = 0; i < size; i++) {
        Process p = processes[i];
        printf("%4c | %3d | %3d | %6d | %8d\n", p->p_id, p->cpu_burst_time, p->io_burst_time, p->arrival_time,
               p->priority);
    }
}

void print_schedule(Schedule schedule) {
    Schedule now = schedule;
    while (now != NULL) {

        printf("-");

        now = now->next_schedule;
    }
    printf("\n");

    now = schedule;
    while (now != NULL) {

        if (now->process == NULL)
            printf(" ");
        else
            printf("%c", now->process->p_id);

        now = now->next_schedule;
    }
    printf("\n");

    now = schedule;
    while (now != NULL) {

        printf("-");

        now = now->next_schedule;
    }
    printf("\n");

    now = schedule;
    while (now != NULL) {

        if (now->io_occurred)
            printf("|");
        else
            printf(" ");

        now = now->next_schedule;
    }
    printf("\n");
}

void print_process_queue(ProcessQueue queue) {
    Process *array = create_process_array_from_queue(queue);
    int size = size_of_queue(queue);
    int i;

    for (i = 0; i < size; i++) {
        Process p = array[i];
        printf("[%c:%2d,%2d]", p->p_id, p->remaining_cpu_burst_time, p->remaining_io_burst_time);
    }
    printf("\n");

    free(array);
}

void __print_two_queues(ProcessQueue ready_queue, ProcessQueue waiting_queue) {
    printf("  ready_queue : ");
    print_process_queue(ready_queue);
    printf("waiting_queue : ");
    print_process_queue(waiting_queue);
}