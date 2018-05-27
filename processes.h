//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_PROCESSES_H
#define CPU_SCHEDULING_SIMULATOR_PROCESSES_H

#include <stdint.h>
#include "utils.h"

struct _Process {
    uint8_t p_id;
    uint32_t cpu_burst_time;
    uint32_t io_burst_time;
    uint32_t arrival_time;
    uint32_t priority;

    uint32_t remaining_cpu_burst_time;
    uint32_t remaining_io_burst_time;
    BOOL is_in_io;
    uint32_t continuous_cpu_burst_time;

    uint32_t waiting_time;
    uint32_t turnaround_time;
};
typedef struct _Process *Process;

Process *create_processes(uint32_t process_num);

Process create_process(uint8_t p_id, uint32_t cpu_burst_time, uint32_t io_burst_time, uint32_t arrival_time,
                       uint32_t priority);

#endif //CPU_SCHEDULING_SIMULATOR_PROCESSES_H
