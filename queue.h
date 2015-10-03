/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Queue API          *
****************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include <stdint.h>

/*
* Hidden Implementation
*/
typedef void * b_queue;

/*
* Initializes and returns a pointer to a queue
*/
b_queue queue_init(void);

/*
* Frees all memory associated with a queue
*/
void queue_free(b_queue);

/*
* Adds an element to the back of the queue
*/
void enqueue(b_queue, char);

/*
* Removes and returns the element at the front 
* of the queue.
* Returns ' ' if the queue is empty
*/
char dequeue(b_queue);

/*
* Returns 0 if there are elements in the queue
*/
int8_t queue_empty(b_queue);

/*
* Prints the queue to stdout
*/
void queue_print(b_queue);

#endif
