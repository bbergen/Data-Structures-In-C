/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Stack Impl.        *
****************************************/
#include "stdlib.h"
#include "stdio.h"
#include "stack.h"

struct node_t {
  char data;
  struct node_t *next;
};

struct stack_t {
  struct node_t *top;
};

static struct node_t* node_init(char c) {
  struct node_t *node = malloc(sizeof(struct node_t));
  node->data = c;
  node->next = NULL;
  return node;
}

b_stack stack_init(void) {
  struct stack_t *stack = malloc(sizeof(struct stack_t));
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
  struct stack_t *stack = b;
  struct node_t *node = node_init(c);
  node->next = stack->top;
  stack->top = node;
}

char stack_top(b_stack b) {
  struct stack_t *stack = b;
  if (!stack_empty(stack)) {
    return stack->top->data;
  } else {
    return '\0';
  }
}

void stack_pop(b_stack b) {
  if (!stack_empty(b)) {
    struct stack_t *stack = b;
    struct node_t *node = stack->top;
    stack->top = node->next;
    free(node);
  }
}

int8_t stack_empty(b_stack b) {
  return ((struct stack_t*)b)->top == NULL;
}

void stack_print(b_stack b) {
  struct stack_t *stack = b;
  struct node_t *node = stack->top;
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

