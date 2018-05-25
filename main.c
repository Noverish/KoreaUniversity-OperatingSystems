#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "options.h"
#include "processes.h"
#include "queues.h"

Process *processes;
ProcessQueue ready_queue;
ProcessQueue waiting_queue;

int i;

int main(int argc, char **argv) {

    srand((unsigned int) time(NULL));

    processes = create_processes(PROCESS_NUM);
    ready_queue = create_process_queue(READY_QUEUE_SIZE);
    waiting_queue = create_process_queue(WAITING_QUEUE_SIZE);

    for(i = 0; i < PROCESS_NUM; i++) {
        printf("%d ", processes[i]->p_id);
        printf("%d ", processes[i]->cpu_burst_time);
        printf("%d ", processes[i]->io_burst_time);
        printf("%d ", processes[i]->arrival_time);
        printf("%d\n", processes[i]->priority);
    }

    return 0;
}



