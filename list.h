/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Single Linked List API                *
****************************************/
#ifndef LIST_H
#define LIST_H
#include <stdint.h> // for int8_t

/*
* Hidden Implementation
*/
typedef void* b_list;

/*
* Initializes and returns a pointer to a new list
*/
b_list list_init(void);

/*
* Frees all memory associated with the list
*/
void list_free(b_list);

/*
* Adds a new item to the back of the list
* Complexity: O(n) (due to constraints)
*/
void list_add_back(b_list, char);

/*
* Adds a new item to the front of the list
* Complexity: O(1) 
*/
void list_add_front(b_list, char);

/*
* Returns the number elements in the list
* Complexity: O(n) (due to constraints)
*/
int list_size(b_list);

/*
* Returns the list reversed in place
*/
void list_reverse_ip(b_list);

/*
* Returns a copy of the list, reversed
*/
b_list list_reverse(b_list);

/*
* Prints the list to stdout
*/
void list_print(b_list);

/*
* Returns 0 if list has elements
*/
int8_t list_empty(b_list);

/*
* Returns 0 if second parameter not in list
*/
int8_t list_contains(b_list, char);

/*
* Removes the element at the passed index
* if index > list_size, the last item
* will be removed
*/
void list_remove(b_list, int);

#endif
