#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "options.h"
#include "processes.h"
#include "queues.h"
#include "schedulers.h"
#include "print.h"
#include "schedule.h"

Scheduler schedulers[] = {first_come_first_served};
int scheduler_num = 1;
int scheduler_index = 0;

Process *processes;
ProcessQueue ready_queue;
ProcessQueue waiting_queue;
int terminated_process_num;
int i;
int now_time;

Schedule schedules;

void put_arrived_process_to_ready_queue(ProcessQueue ready_queue, Process *processes, uint32_t size, int now_time);

void put_io_done_process_to_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue);

void put_process_to_waiting_queue_from_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue, Process p);

void progress_waiting_queue(ProcessQueue waiting_queue);

int main() {
    srand((unsigned int) time(NULL));

    processes = create_processes(PROCESS_NUM);
    ready_queue = create_process_queue();
    waiting_queue = create_process_queue();

    print_processes(processes, PROCESS_NUM);

    for (scheduler_index = 0; scheduler_index < scheduler_num; scheduler_index++) {
        Scheduler now_scheduler = schedulers[scheduler_index];

        for (now_time = 0; terminated_process_num != PROCESS_NUM; now_time++) {

            // Put arrived process to ready queue
            put_arrived_process_to_ready_queue(ready_queue, processes, PROCESS_NUM, now_time);

            // Choose process
            Process p = now_scheduler(ready_queue, waiting_queue, processes, PROCESS_NUM, now_time);

            // Run process (cpu and io)
            if (p != NULL)
                p->remaining_cpu_burst_time -= 1; // run on cpu
            progress_waiting_queue(waiting_queue); // run on each io devices

            // Terminate process if cpu burst done
            if (p != NULL)
                if (p->remaining_cpu_burst_time == 0) {
                    remove_from_queue(ready_queue, p);
                    terminated_process_num++;
                }

            // Put process to ready queue when I/O done
            put_io_done_process_to_ready_queue(ready_queue, waiting_queue);

            BOOL io_occurred = FALSE;
            if (p != NULL && p->remaining_cpu_burst_time != 0) {
                // Check I/O occurred
                io_occurred = random_double() < IO_OCCUR_PROBABILITY ? TRUE : FALSE;

                // Put process if I/O occurred
                if (io_occurred)
                    put_process_to_waiting_queue_from_ready_queue(ready_queue, waiting_queue, p);
            }

            // Write logs
            if (schedules == NULL)
                schedules = create_schedule(p, io_occurred);
            else
                add_schedule(schedules, p, io_occurred);
        }

        print_schedule(schedules);
    }

    return 0;
}

void put_arrived_process_to_ready_queue(ProcessQueue ready_queue, Process *processes, uint32_t size, int now_time) {
    int i;
    for (i = 0; i < size; i++) {
        Process p = processes[i];
        if (p->arrival_time == now_time) {
            add_to_queue(ready_queue, p);
        }
    }
}

void progress_waiting_queue(ProcessQueue waiting_queue) {
    Process *array = create_process_array_from_queue(waiting_queue);
    int size = size_of_queue(waiting_queue);
    int i;

    for (i = 0; i < size; i++) {
        array[i]->remaining_io_burst_time -= 1;
    }

    free(array);
}

void put_io_done_process_to_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue) {
    Process *array = create_process_array_from_queue(waiting_queue);
    int size = size_of_queue(waiting_queue);
    int i;

    for (i = 0; i < size; i++) {
        Process p = array[i];
        if (p->remaining_io_burst_time == 0) {
            remove_from_queue(waiting_queue, p);
            add_to_queue(ready_queue, p);
            p->remaining_io_burst_time = (uint32_t) -1;
        }
    }

    free(array);
}

void put_process_to_waiting_queue_from_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue, Process p) {
    remove_from_queue(ready_queue, p);
    add_to_queue(waiting_queue, p);
    p->remaining_io_burst_time = p->io_burst_time;
}