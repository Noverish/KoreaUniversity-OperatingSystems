//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include <assert.h>
#include "queues.h"

ProcessQueue create_process_queue() {
    ProcessQueue queue = (ProcessQueue) malloc(sizeof(ProcessQueueNode));
    *queue = NULL;
    return queue;
}

BOOL is_queue_empty(ProcessQueue queue) {
    return (queue == NULL || *queue == NULL) ? TRUE : FALSE;
}

int size_of_queue(ProcessQueue queue) {
    if (is_queue_empty(queue))
        return 0;

    ProcessQueueNode now = *queue;
    int size = 0;

    while (now != NULL) {
        size++;
        now = now->next;
    }

    return size;
}

ProcessQueueNode get_last_node_of_queue(ProcessQueue queue) {
    if (is_queue_empty(queue))
        return NULL;

    ProcessQueueNode now = *queue;
    while (now->next != NULL) {
        now = now->next;
    }
    return now;
}

void add_to_queue(ProcessQueue queue, Process process) {
    ProcessQueueNode new_node = (ProcessQueueNode) malloc(sizeof(struct _ProcessQueueNode));
    new_node->process = process;
    new_node->next = NULL;

    if (is_queue_empty(queue)) {
        *queue = new_node;
    } else {
        get_last_node_of_queue(queue)->next = new_node;
    }
}

void remove_from_queue(ProcessQueue queue, Process process) {

    // Replace queue first node
    while (TRUE) {
        if (is_queue_empty(queue))
            return;

        ProcessQueueNode now = *queue;

        if (now->process == process) {
            *queue = now->next;
            free(now);
        } else {
            break;
        }
    }

    ProcessQueueNode now = *queue;
    ProcessQueueNode next = now->next;
    while (next != NULL) {
        if (next->process == process) {
            now->next = next->next;
            free(next);
            next = now->next;
        } else {
            now = next;
            next = now->next;
        }
    }
}

Process *create_process_array_from_queue(ProcessQueue queue) {
    int size = size_of_queue(queue);
    if (size == 0)
        return NULL;

    Process *array = (Process *) malloc(size * sizeof(struct _Process));
    ProcessQueueNode now = *queue;
    int i;
    for (i = 0; i < size; i++) {
        array[i] = now->process;
        now = now->next;
    }

    return array;
}

BOOL is_process_in_queue(ProcessQueue queue, Process process) {
    ProcessQueueNode now = *queue;

    while (now != NULL) {
        if (now->process == process)
            return TRUE;

        now = now->next;
    }
    return FALSE;
}
