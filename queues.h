//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_QUEUES_H
#define CPU_SCHEDULING_SIMULATOR_QUEUES_H

#include "processes.h"
#include "utils.h"

struct _ProcessQueueNode {
    Process process;
    struct _ProcessQueueNode *next;
};
typedef struct _ProcessQueueNode *ProcessQueueNode;
typedef struct _ProcessQueueNode **ProcessQueue;

ProcessQueue create_process_queue();

BOOL is_queue_empty(ProcessQueue queue);

int size_of_queue(ProcessQueue queue);

void add_to_queue(ProcessQueue queue, Process process);

void remove_from_queue(ProcessQueue queue, Process process);

Process *create_process_array_from_queue(ProcessQueue queue);

BOOL is_process_in_queue(ProcessQueue queue, Process process);

#endif //CPU_SCHEDULING_SIMULATOR_QUEUES_H
