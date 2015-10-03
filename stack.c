/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Stack Impl.        *
****************************************/
#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

struct _node {
  char data;
  struct _node *next;
};

struct _stack {
  struct _node *top;
};

static struct _node* node_init(char c) {
  struct _node *node = malloc(sizeof(struct _node));
  node->data = c;
  node->next = NULL;
  return node;
}

b_stack stack_init(void) {
  struct _stack *stack = malloc(sizeof(struct _stack));
  stack->top = NULL;
  return stack;
}

void stack_free(b_stack b) {
  while (!stack_empty(b)) {
    stack_pop(b);
  }
  free(b);
}

void stack_push(b_stack b, char c) {
  struct _stack *stack = b;
  struct _node *node = node_init(c);
  node->next = stack->top;
  stack->top = node;
}

char stack_top(b_stack b) {
  struct _stack *stack = b;
  if (!stack_empty(stack)) {
    return stack->top->data;
  } else {
    return '\0';
  }
}

void stack_pop(b_stack b) {
  if (!stack_empty(b)) {
    struct _stack *stack = b;
    struct _node *node = stack->top;
    stack->top = node->next;
    free(node);
  }
}

int8_t stack_empty(b_stack b) {
  return ((struct _stack*)b)->top == NULL;
}

void stack_print(b_stack b) {
  struct _stack *stack = b;
  struct _node *node = stack->top;
  printf("[");
  if (!stack_empty(b)) {
    while(node) {
      printf("%c", node->data);
      if (node->next) {
        printf(", ");
      }
      node = node->next;
    }
  }
  printf("]\n");
}

