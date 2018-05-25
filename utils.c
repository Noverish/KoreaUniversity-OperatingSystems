//
// Created by Noverish Harold on 2018. 5. 25..
//

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

uint32_t random_number(uint32_t from, uint32_t to) {
    if(from > to)
        swap(&from, &to);

    uint32_t tmp = (uint32_t) rand();
    return tmp % (to - from + 1) + from;
}

uint32_t* get_rand_nums(uint32_t from, uint32_t to, uint32_t size) {
    int i;
    uint32_t* array = (uint32_t*) malloc(size * sizeof(uint32_t));

    for(i = 0; i < size; i++) {
        uint32_t new_rand;
        do {
            new_rand = random_number(from, to);
        } while(is_number_in_array(new_rand, &array, size));
        array[i] = new_rand;
    }

    return array;
}

void swap(uint32_t* a, uint32_t* b) {
    uint32_t tmp = *a;
    *a = *b;
    *b = tmp;
}

BOOL is_number_in_array(uint32_t num, uint32_t** arr, uint32_t size) {
    int i;
    for(i = 0; i < size; i++) {
        if((*arr)[i] == num)
            return TRUE;
    }
    return FALSE;
}