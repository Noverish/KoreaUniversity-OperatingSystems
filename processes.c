//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include "processes.h"
#include "options.h"

Process *create_processes(uint32_t process_num) {
    Process *processes = (Process *) malloc(process_num * sizeof(struct _Process));
    int i;

    for (i = 0; i < process_num; i++) {
        processes[i] = create_process(
                (uint8_t) ('A' + i),
                random_number(CPU_BURST_START_NUM, CPU_BURST_END_NUM),
                random_number(IO_BURST_START_NUM, IO_BURST_END_NUM),
                random_number(ARRIVAL_START_NUM, ARRIVAL_END_NUM),
                random_number(PRIORITY_START_NUM, PRIORITY_END_NUM)
        );
    }

    return processes;
}

Process create_process(uint8_t p_id, uint32_t cpu_burst_time, uint32_t io_burst_time, uint32_t arrival_time,
                       uint32_t priority) {
    Process process = (Process) malloc(sizeof(struct _Process));
    process->p_id = p_id;
    process->cpu_burst_time = cpu_burst_time;
    process->io_burst_time = io_burst_time;
    process->arrival_time = arrival_time;
    process->priority = priority;

    process->remaining_cpu_burst_time = process->cpu_burst_time;
    process->remaining_io_burst_time = 0;
    process->is_in_io = FALSE;
    process->continuous_cpu_burst_time = 0;

    process->waiting_time = 0;
    process->turnaround_time = 0;
    return process;
}