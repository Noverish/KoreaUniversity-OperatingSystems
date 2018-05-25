//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_PROCESSES_H
#define CPU_SCHEDULING_SIMULATOR_PROCESSES_H

#include <stdint.h>

struct _Process {
    uint32_t p_id;
    uint32_t cpu_burst_time;
    uint32_t io_burst_time;
    uint32_t arrival_time;
    uint32_t priority;
};
typedef struct _Process *Process;

Process* create_processes(uint32_t process_num);
Process create_process(uint32_t p_id, uint32_t cpu_burst_time, uint32_t io_burst_time, uint32_t arrival_time, uint32_t priority);

#endif //CPU_SCHEDULING_SIMULATOR_PROCESSES_H
