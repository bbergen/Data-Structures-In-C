/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Driver File for Lab 3                 *
****************************************/
#include <stdio.h>
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "tree.h"
#include "big_int.h"

int main(int argc, char **argv) {
 
  big_int b = big_int_init();
  big_int_insert(b, 30045);
  big_int_print(b);
  printf("Size: %d\n", big_int_digits(b));
  big_int_reverse(b);
  big_int_print(b);

  return 0;
}
