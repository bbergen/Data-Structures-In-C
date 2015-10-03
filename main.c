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
  
  b_tree tree = tree_init();
  tree_add(tree, '5');
  tree_add(tree, '1');
  tree_add(tree, '4');
  tree_add(tree, '9');

  printf("Tree Size: %d\n", tree_size(tree));
  if (tree_contains(tree, '1')) {
    printf("Contains 1!\n");
  }
  if (!tree_contains(tree, '$')) {
    printf("Doesnt contain $\n");
  }

  printf("Largest: %c\n", tree_max(tree));
  printf("Smallest: %c\n", tree_min(tree));

  tree_print(tree);

  printf("Removing '1'\n");
  tree_remove(tree, '1');
  tree_print(tree);

  tree_free(tree);

  return 0;
}
