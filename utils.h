//
// Created by Noverish Harold on 2018. 5. 25..
//

#ifndef CPU_SCHEDULING_SIMULATOR_UTILS_H
#define CPU_SCHEDULING_SIMULATOR_UTILS_H

typedef enum _BOOL BOOL;
enum _BOOL {
    TRUE = 1, FALSE = 0
};

uint32_t random_number(uint32_t from, uint32_t to);

double random_double();

uint32_t *get_rand_nums(uint32_t from, uint32_t to, uint32_t size);

void swap(uint32_t *a, uint32_t *b);

BOOL is_number_in_array(uint32_t num, uint32_t **arr, uint32_t size);

#endif //CPU_SCHEDULING_SIMULATOR_UTILS_H
