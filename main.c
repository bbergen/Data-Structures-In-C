/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Driver File for Lab 3                 *
****************************************/
#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"

int main(int argc, char **argv) {
 
  // List Testing
  b_list list = list_init();
  list_add_front(list, '5');
  list_add_front(list, 'G');
  list_add_back(list,'B');
  list_print(list);
  list_reverse_ip(list);
  list_print(list);

  // Tree Testing
  b_tree tree = tree_init();
  tree_add(tree, '5');
  tree_add(tree, '1');
  tree_add(tree, '4');
  tree_add(tree, '9');

  printf("Tree Size: %d\n", tree_size(tree));
  tree_print(tree);
  printf("Removing '1'\n");
  tree_remove(tree, '1');
  tree_print(tree);
  tree_free(tree);

  return 0;
}
