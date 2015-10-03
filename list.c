/****************************************
* Bryan Bergen - 300173752 - COSC 222   *
* Single Linked List Implementation     *
****************************************/
#include <stdlib.h> // for malloc, free & NULL 
#include <stdio.h> // for printf
#include "list.h"

#define true 1
#define false 0

struct _node {
  char data;
  struct _node *next;
};

struct _list {
  struct _node *head;
};

b_list list_init(void) {
  struct _list *list = malloc(sizeof(struct _list));
  list->head = NULL;
  return list;
}

static struct _node* node_init(char c) {
  struct _node *node = malloc(sizeof(struct _node));
  node->data = c;
  node->next = NULL;
  return node;
}

static void list_free_impl(struct _node *n) {
  if (n) {
    list_free_impl(n->next);
    free(n);
  }
}

void list_free(b_list b) {
  struct _list *list = b;
  if (list) {
    list_free_impl(list->head);
    free(list);
  }
}

void list_add_front(b_list b, char c) {
  struct _list *list = b;
  struct _node *node = node_init(c);
  node->next = list->head;
  list->head = node;
}

void list_add_back(b_list b, char c) {
  struct _list *list = b;
  if (list_empty(b)) {
    list->head = node_init(c);
  } else {
    struct _node *current = list->head;
    while (current->next) {
      current = current->next;
    }
    current->next = node_init(c);
  }
}

static int size(struct _node *n) {
  return n ? 1 + size(n->next) : 0;
}

int list_size(b_list b) {
  struct _list *list = b;
  return size(list->head);
}

static void reverse(struct _node *head, int start, int end) {
  // base case
  if (start >= end) {
    return;
  }

  // first we navigate to our start
  struct _node *current = head;
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
  reverse(((struct _list*)b)->head, 0, list_size(b) - 1);
}

b_list list_reverse(b_list b) {
  struct _list *old_list = b;
  struct _list *new_list = list_init();

  if (!list_empty(old_list)) {
    struct _node *current = old_list->head;
    while(current) {
      if (current->data) {
        list_add_front(new_list, current->data);
        current = current->next;
      }
    }
  }

  return new_list;
}

void list_print(b_list b) {
  struct _list *list = b;
  struct _node *node = list->head;
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

static int8_t contains(struct _node *n, char c) {
  if (n == NULL) {
    return false;
  } else if (n->data == c) {
    return true;
  } else {
    return contains(n->next, c);
  }
}

int8_t list_contains(b_list b, char c) {
  struct _list *list = b;
  return contains(list->head, c);
}

void list_remove(b_list b, int n) {
  struct _list *list = b;
  if (!list_empty(list) && n >= 0) {
    struct _node *current = list->head;
    struct _node *tmp;
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
