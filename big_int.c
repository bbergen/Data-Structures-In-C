#include "stdlib.h"
#include "stdio.h"
#include "big_int.h"

struct node_t {
  char value;
  struct node_t *next;
};

struct big_int_t {
  struct node_t *head;
};

big_int big_int_init(void) {
  struct big_int_t *b_int = malloc(sizeof(struct big_int_t));
  b_int->head = NULL;
  return b_int;
}

static struct node_t* node_init(char value) {
  struct node_t *node = malloc(sizeof(struct node_t));
  node->value = value;
  node->next = NULL;
  return node;
}

static void free_impl(struct node_t *node) {
  if (node) {
    free_impl(node->next);
    free(node);
  }
}

void big_int_free(big_int b_int) {
  if (b_int) {
    free_impl(((struct big_int_t*)b_int)->head);
    free(b_int);
  }
}

int8_t big_int_empty(big_int b) {
  return ((struct big_int_t*)b)->head == NULL;
}

void big_int_insert(big_int b, int n) {
  struct big_int_t *b_int = b;
  while (n) {
    char i = n % 10;
    n /= 10;
    struct node_t *new = node_init(i);
    new->next = b_int->head;
    b_int->head = new;
  }
}

static void print_impl(struct node_t *node) {
  if (node) {
    printf("%d", node->value);
    print_impl(node->next);
  }
}

void big_int_print(big_int b) {
  print_impl(((struct big_int_t*)b)->head);
  printf("\n");
}

static int size_impl(struct node_t *node) {
  if (node) {
    return 1 + size_impl(node->next);
  } else {
    return 0;
  }
}

int big_int_digits(big_int b) {
  return size_impl(((struct big_int_t*)b)->head);
}

static void reverse(struct node_t *head, int start, int end) {
  // base case
  if (start >= end) {
    return;
  }

  struct node_t *current = head;
  int i;
  for (i = 0; i < start; i++) {
    current = current->next;  
  }
  char *left = &current->value;

  current = head;
  for (i = 0; i < end; i++) {
    current = current->next;
  }
  
  char tmp = *left;
  *left = current->value;
  current->value = tmp;

  reverse(head, start + 1, end - 1);
}

void big_int_reverse(big_int b) {
  struct big_int_t *b_int = b;
  reverse(b_int->head, 0, size_impl(b_int->head) - 1);
}
