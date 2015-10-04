/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Linked List Backed Queue Impl         *
****************************************/
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

struct node_t {
  char data;
  struct node_t *next;
};

struct queue_t {
  struct node_t *front;
};

b_queue queue_init(void) {
  struct queue_t *q = malloc(sizeof(struct queue_t));
  q->front = NULL;
  return q;
}

static struct node_t* node_init(char c) {
  struct node_t *node = malloc(sizeof(struct node_t));
  node->data = c;
  node->next = NULL;
  return node;
}

int8_t queue_empty(b_queue b) {
  return ((struct queue_t*)b)->front == NULL;
}

static void queue_free_impl(struct node_t *n) {
  if (n) {
    queue_free_impl(n->next);
    free(n);
  }
}

void queue_free(b_queue b) {
  if (b) {
    queue_free_impl(((struct queue_t*)b)->front);
    free(b);
  }
}

void enqueue(b_queue b, char c) {
  struct queue_t *q = b;
  struct node_t *node = node_init(c);
  node->next = q->front;
  q->front = node;
}

char dequeue(b_queue b) {
  if (!queue_empty(b)) {
    struct queue_t *q = b;
    struct node_t *current = q->front;
    while (current->next->next) {
      current = current->next; 
    }
    struct node_t *tmp = current->next;
    current->next = NULL;
    char c = tmp->data;
    free(tmp);
    return c;
  } else {
    return ' ';
  }
}

static void queue_print_impl(struct node_t *n) {
  if (n) {
    queue_print_impl(n->next);
    if (n->next) { 
      printf(", ");
    }
    printf("%c", n->data);
  }
}

void queue_print(b_queue b) {
  struct node_t *n = ((struct queue_t*)b)->front;
  printf("[");
  if (!queue_empty(b)) {
    queue_print_impl(n);
  }
  printf("]\n");
}

