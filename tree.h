/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Binary Search Tree API                *
****************************************/
#ifndef TREE_H
#define TREE_H
#include <stdint.h>

/*
* Hidden Implementation
*/
typedef void* b_tree;

/*
* Initializes and allocates memory for a tree
*/
b_tree tree_init(void);

/*
* Frees all memory associated with the tree
*/
void tree_free(b_tree);

/*
* Adds a new element to the tree
*/
void tree_add(b_tree, char);

/*
* Returns the number of nodes/leafs in the tree
*/
int tree_size(b_tree);

/*
* Returns 0 if there are any elements in the tree
*/
int8_t tree_empty(b_tree);

/*
* Returns 0 if the element is not in the tree
*/
int8_t tree_contains(b_tree, char);

/*
* Prints the tree to stdout
*/
void tree_print(b_tree);

/*
* Removes the node from the tree, if it contains it
*/
void tree_remove(b_tree, char);

/*
* Returns the smallest element in the tree
*/
char tree_min(b_tree);

/*
* Returns the largest element in the tree
*/
char tree_max(b_tree);

#endif
