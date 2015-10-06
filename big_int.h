/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Arbitrarily Large Number API          *
****************************************/
#ifndef BIG_INT_H
#define BIG_INT_H

#include "stdint.h"

/*
* Hidden Implementation
*/ 
typedef void* big_int;

big_int big_int_init(void);

void big_int_free(big_int);

void big_int_insert(big_int, int);

big_int big_int_add(big_int, big_int);

big_int big_int_sub(big_int, big_int);

big_int big_int_mul(big_int, big_int);

big_int big_int_div(big_int, big_int);

int8_t big_int_empty(big_int);

void big_int_print(big_int);

void big_int_reverse(big_int);

int big_int_digits(big_int);

#endif

