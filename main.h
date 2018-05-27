//
// Created by Noverish Harold on 2018. 5. 27..
//

#ifndef CPU_SCHEDULING_SIMULATOR_MAIN_H
#define CPU_SCHEDULING_SIMULATOR_MAIN_H

#include "queues.h"

void put_arrived_process_to_ready_queue(ProcessQueue ready_queue, Process *processes, uint32_t size, int now_time);

void put_io_done_process_to_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue);

void put_process_to_waiting_queue_from_ready_queue(ProcessQueue ready_queue, ProcessQueue waiting_queue, Process p);

void decrease_io_burst_time_in_waiting_queue(ProcessQueue waiting_queue);

void reset_process_information(Process *processes, int size);

void increase_waiting_time(ProcessQueue ready_queue, Process now_running_process);

#endif //CPU_SCHEDULING_SIMULATOR_MAIN_H
