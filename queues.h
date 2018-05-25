//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_QUEUES_H
#define CPU_SCHEDULING_SIMULATOR_QUEUES_H

#include "processes.h"
#include "utils.h"

struct _ProcessQueue {
    Process* processes;
    uint32_t start;
    uint32_t end;
    uint32_t size;
};
typedef struct _ProcessQueue* ProcessQueue;

ProcessQueue create_process_queue(uint32_t size);
BOOL is_queue_empty(ProcessQueue queue);
BOOL is_queue_full(ProcessQueue queue);
Process pop(ProcessQueue queue);
void push(ProcessQueue queue, Process p);

#endif //CPU_SCHEDULING_SIMULATOR_QUEUES_H
