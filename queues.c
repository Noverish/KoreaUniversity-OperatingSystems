//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include <assert.h>
#include "queues.h"

ProcessQueue create_process_queue(uint32_t size) {
    ProcessQueue queue = (ProcessQueue) malloc(sizeof(struct _ProcessQueue));
    queue->processes = (Process*) malloc(size * sizeof(struct _Process));
    queue->start = 0;
    queue->end = 0;
    queue->size = size;
    return queue;
}

BOOL is_queue_empty(ProcessQueue queue) {
    return (queue->start == queue->end) ? TRUE : FALSE;
}

BOOL is_queue_full(ProcessQueue queue) {
    int start_plus_1 = (queue->start + 1) % queue->size;
    return (start_plus_1 == queue->end) ? TRUE : FALSE;
}

Process pop(ProcessQueue queue) {
    assert(!is_queue_empty(queue));

    Process p = queue->processes[queue->start];
    queue->start = (queue->start + 1) % queue->size;
    return p;
}

void push(ProcessQueue queue, Process p) {
    assert(!is_queue_full(queue));

    queue->end = (queue->end + 1) % queue->size;
    queue->processes[queue->end] = p;
}