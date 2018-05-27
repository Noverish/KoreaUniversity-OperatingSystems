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
    printf("\n");
}

void print_schedule(Schedule schedule) {
    char strings[100][100] = {0};
    Schedule now = schedule;
    Schedule previous = NULL;
    int now_time = 0, now_col = 0;
    int r, c, i;

    while (now != NULL) {

        if (previous == NULL || now->process != previous->process) {
            if (now_time >= 10)
                sprintf(&(strings[0][now_col - 1]), "%2d", now_time);
            else
                sprintf(&(strings[0][now_col]), "%d", now_time);
            sprintf(&(strings[1][now_col]), "+");
            sprintf(&(strings[2][now_col]), "|");
            sprintf(&(strings[3][now_col]), "+");

            if (previous != NULL && previous->io_occurred) {
                for (i = 0; i < now_col; i++) {
                    if (strings[4][i] == 0)
                        strings[4][i] = ' ';
                    if (strings[5][i] == 0)
                        strings[5][i] = ' ';
                }

                sprintf(&(strings[4][now_col]), "^");
                sprintf(&(strings[5][now_col-1]), "I/O");
            }


            now_col++;
        }

        sprintf(&(strings[0][now_col]), " ");
        sprintf(&(strings[1][now_col]), "-");
        sprintf(&(strings[2][now_col]), "%c", (now->process == NULL) ? ' ' : now->process->p_id);
        sprintf(&(strings[3][now_col]), "-");
        now_col++;

        now_time++;
        previous = now;
        now = now->next_schedule;
    }

    if (now_time >= 10)
        sprintf(&(strings[0][now_col - 1]), "%2d", now_time);
    else
        sprintf(&(strings[0][now_col]), "%d", now_time);
    sprintf(&(strings[1][now_col]), "+");
    sprintf(&(strings[2][now_col]), "|");
    sprintf(&(strings[3][now_col]), "+");

    for (r = 0; r < 100; r++) {
        for (c = 0; c < 100; c++) {
            char ch = strings[r][c];
            if (ch != 0) {
                printf("%c", ch);
            }
        }
        if (strings[r][0] != 0)
            printf("\n");
    }
    printf("\n");
}

void print_process_queue(ProcessQueue queue) {
    Process *array = create_process_array_from_queue(queue);
    int size = size_of_queue(queue);
    int i;

    for (i = 0; i < size; i++) {
        Process p = array[i];
        printf("[%c:%2d,%2d,%2d]", p->p_id, p->remaining_cpu_burst_time, p->remaining_io_burst_time,
               p->continuous_cpu_burst_time);
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

void __print_waiting_and_turnaround_time(Process *processes, int size) {
    int waiting_time_sum = 0;
    int turnaround_time_sum = 0;

    int i;
//    printf("p_id | wait | turnaround\n");
    for (i = 0; i < size; i++) {
        Process p = processes[i];
//        printf("%4c | %4d | %10d\n", p->p_id, p->waiting_time, p->turnaround_time);
        waiting_time_sum += p->waiting_time;
        turnaround_time_sum += p->turnaround_time;
    }

    printf("average waiting time : %f\n", (double) waiting_time_sum / size);
    printf("average turnaround time : %f\n", (double) turnaround_time_sum / size);
}

void clear_string(char *string, int size) {
    int i;
    for (i = 0; i < size; i++)
        string[i] = 0;
}