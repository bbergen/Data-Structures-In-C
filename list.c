/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Single Linked List Implementation     *
****************************************/
#include <stdlib.h> // for malloc, free & NULL 
#include <stdio.h> // for printf
#include "list.h"

#define true 1
#define false 0

struct node_t {
  char data;
  struct node_t *next;
};

struct list_t {
  struct node_t *head;
};

b_list list_init(void) {
  struct list_t *list = malloc(sizeof(struct list_t));
  list->head = NULL;
  return list;
}

static struct node_t* node_init(char c) {
  struct node_t *node = malloc(sizeof(struct node_t));
  node->data = c;
  node->next = NULL;
  return node;
}

static void list_free_impl(struct node_t *n) {
  if (n) {
    list_free_impl(n->next);
    free(n);
  }
}

void list_free(b_list b) {
  struct list_t *list = b;
  if (list) {
    list_free_impl(list->head);
    free(list);
  }
}

void list_add_front(b_list b, char c) {
  struct list_t *list = b;
  struct node_t *node = node_init(c);
  node->next = list->head;
  list->head = node;
}

void list_add_back(b_list b, char c) {
  struct list_t *list = b;
  if (list_empty(b)) {
    list->head = node_init(c);
  } else {
    struct node_t *current = list->head;
    while (current->next) {
      current = current->next;
    }
    current->next = node_init(c);
  }
}

static int size(struct node_t *n) {
  return n ? 1 + size(n->next) : 0;
}

int list_size(b_list b) {
  struct list_t *list = b;
  return size(list->head);
}

static void reverse(struct node_t *head, int start, int end) {
  // base case
  if (start >= end) {
    return;
  }

  // first we navigate to our start
  struct node_t *current = head;
  int i;
  for (i = 0; i < start; i++) {
    current = current->next;
  }
  // there we grab a pointer to our data
  char *left = &current->data;

  // now, we navigate to our end
  current = head;
  for (i = 0; i < end; i++) {
    current = current->next;
  }

  // now, we swap swap the chars at start, end
  char tmp = *left;
  *left = current->data;
  current->data = tmp;

  // finally, we recursively solve the solution
  // on a slightly smaller list
  reverse(head, start + 1, end - 1);
}

void list_reverse_ip(b_list b) {
  reverse(((struct list_t*)b)->head, 0, list_size(b) - 1);
}

b_list list_reverse(b_list b) {
  struct list_t *oldlist_t = b;
  struct list_t *newlist_t = list_init();

  if (!list_empty(oldlist_t)) {
    struct node_t *current = oldlist_t->head;
    while(current) {
      if (current->data) {
        list_add_front(newlist_t, current->data);
        current = current->next;
      }
    }
  }

  return newlist_t;
}

void list_print(b_list b) {
  struct list_t *list = b;
  struct node_t *node = list->head;
  printf("[");
  if (!list_empty(b)) {
    while (node) {
      printf("%c", node->data);
      if (node->next) {
        printf(", ");
      }
      node = node->next;
    }
  }
  printf("]\n");
}

int8_t list_empty(b_list b) {
  return list_size(b) == 0;
}

static int8_t contains(struct node_t *n, char c) {
  if (n == NULL) {
    return false;
  } else if (n->data == c) {
    return true;
  } else {
    return contains(n->next, c);
  }
}

int8_t list_contains(b_list b, char c) {
  struct list_t *list = b;
  return contains(list->head, c);
}

void list_remove(b_list b, int n) {
  struct list_t *list = b;
  if (!list_empty(list) && n >= 0) {
    struct node_t *current = list->head;
    struct node_t *tmp;
    if (n == 0) {
      // remove at head
      list->head = current->next; 
    } else if (n >= list_size(list) - 1){
      // remove at tail 
      while (current->next->next) {
        current = current->next;
      }
      tmp = current->next;
      current->next = NULL;
      current = tmp;
    } else {
      // remove in middle
      int i;
      for (i = 0; i < n - 2; i++) {
        current = current->next;
      }
      tmp = current->next;
      current->next = current->next->next;
      current = tmp;
    }
    free(current);
  }
}
