//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdlib.h>
#include "schedulers.h"

Process first_come_first_served(ProcessQueue ready_queue,
                                ProcessQueue waiting_queue,
                                Process *processes,
                                uint32_t size,
                                int now_time) {

    if (is_queue_empty(ready_queue))
        return NULL;

    return (*ready_queue)->process;
}