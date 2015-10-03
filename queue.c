/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Queue Impl         *
****************************************/
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct _node {
  char data;
  struct _node *next;
};

struct _queue {
  struct _node *front;
};

b_queue queue_init(void) {
  struct _queue *q = malloc(sizeof(struct _queue));
  q->front = NULL;
  return q;
}

static struct _node* node_init(char c) {
  struct _node *node = malloc(sizeof(struct _node));
  node->data = c;
  node->next = NULL;
  return node;
}

int8_t queue_empty(b_queue b) {
  return ((struct _queue*)b)->front == NULL;
}

static void queue_free_impl(struct _node *n) {
  if (n) {
    queue_free_impl(n->next);
    free(n);
  }
}

void queue_free(b_queue b) {
  if (b) {
    queue_free_impl(((struct _queue*)b)->front);
    free(b);
  }
}

void enqueue(b_queue b, char c) {
  struct _queue *q = b;
  struct _node *node = node_init(c);
  node->next = q->front;
  q->front = node;
}

char dequeue(b_queue b) {
  if (!queue_empty(b)) {
    struct _queue *q = b;
    struct _node *current = q->front;
    while (current->next->next) {
      current = current->next; 
    }
    struct _node *tmp = current->next;
    current->next = NULL;
    char c = tmp->data;
    free(tmp);
    return c;
  } else {
    return ' ';
  }
}

static void queue_print_impl(struct _node *n) {
  if (n) {
    queue_print_impl(n->next);
    if (n->next) { 
      printf(", ");
    }
    printf("%c", n->data);
  }
}

void queue_print(b_queue b) {
  struct _node *n = ((struct _queue*)b)->front;
  printf("[");
  if (!queue_empty(b)) {
    queue_print_impl(n);
  }
  printf("]\n");
}

