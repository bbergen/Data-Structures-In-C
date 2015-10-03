/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Stack API          *
****************************************/
#ifndef STACK_H
#define STACK_H
#include <stdint.h>

/*
* Hidden Implementation
*/
typedef void* b_stack;

/*
* Initializes and returns a pointer to a new stack
*/
b_stack stack_init(void);

/*
* Frees all memory associated with the stack
*/
void stack_free(b_stack);

/*
* Push passed char onto stack
*/
void stack_push(b_stack, char);

/*
* Returns a copy of the char on top the stack
* Note: Does not pop the char off the stack
* Note: Returns \0 if stack is empty
*/
char stack_top(b_stack);

/*
* Pops the top item off of the stack
*/
void stack_pop(b_stack);

/*
* Returns 0 if stack has any elements
*/
int8_t stack_empty(b_stack);

/*
* Prints entire stack to console
*/
void stack_print(b_stack);

#endif
