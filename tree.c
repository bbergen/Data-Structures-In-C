#include "stdlib.h"
#include "stdio.h"
#include "tree.h"

#define true 1
#define false 0

struct node_t {
  char data;
  struct node_t *left;
  struct node_t *right;
};

struct tree_t {
  struct node_t *root;
};

struct node_t* node_init(char c) {
  struct node_t *node = malloc(sizeof(struct node_t));
  node->data = c;
  node->left = NULL;
  node->right = NULL;
  return node;
}

b_tree tree_init(void) {
  struct tree_t *tree = malloc(sizeof(struct tree_t));
  tree->root = NULL;
  return tree;
}

static void free_impl(struct node_t *node) {

  if (node->left) {
    free_impl(node->left);
  }

  if (node->right) {
    free_impl(node->right);
  }

  free(node);
}

void tree_free(b_tree b) {
  struct tree_t *tree = b;
  if (tree->root) {
    free_impl(tree->root);
  }
  free(tree);
}

static void add_impl(struct node_t **node, char c) {
  struct node_t *this = *node;
  if (this == NULL) {
    *node = node_init(c);
  } else if (c < this->data) {
    add_impl(&this->left, c);
  } else if (c > this->data) {
    add_impl(&this->right, c);
  } else {
    //TODO duplicate handling
  }
}

void tree_add(b_tree b, char c) {
  struct tree_t *tree = b;
  add_impl(&tree->root, c);
}

static int size_impl(struct node_t *node) {
  if (node) {
    int left = size_impl(node->left);
    int right = size_impl(node->right);
    return 1 + right + left;
  } else {
    return 0;
  }
}

int tree_size(b_tree b) {
  struct tree_t *tree = b;
  return size_impl(tree->root);
}

static int8_t contains_impl(struct node_t *node, char c) {
  if (!node) {
    return false;
  } else if (c < node->data) {
    return contains_impl(node->left, c); 
  } else if (c > node->data) {
    return contains_impl(node->right, c);
  } else {
    return true;
  }
}

int8_t tree_contains(b_tree b, char c) {
  return contains_impl(((struct tree_t*)b)->root, c);
}

static void print_impl(struct node_t *node, int depth) {
  if (node) {
    int i = depth;
    while (i--) {
      printf("  ");
    }
    printf("%c\n", node->data);
    print_impl(node->left, depth + 1);
    print_impl(node->right, depth + 1);
  }
}

void tree_print(b_tree b) {
  print_impl(((struct tree_t*)b)->root, 0);
}

static struct node_t* min_impl(struct node_t *node) {
  if (!node) {
    return NULL;
  } else if (!node->left) {
    return node; 
  } else {
    return min_impl(node->left);
  }
}

char tree_min(b_tree b) {
  struct node_t *min = min_impl(((struct tree_t*)b)->root);
  if (min) {
    return min->data;
  } else {
    return ' ';
  }
}

static void remove_impl(struct node_t **node, char c) {
  struct node_t *this = *node;
  if (this == NULL) {
    return; // element not in tree
  } else if (c < this->data) {
    remove_impl(&this->left, c); 
  } else if (c > this->data) {
    remove_impl(&this->right, c);
  } else if (this->left && this->right) {
    // we have two children
    this->data = min_impl(this->right)->data;
    remove_impl(&this->right, c);
  } else {
    struct node_t *tmp = this;
    if (this->left) {
      *node = this->left;
    } else {
      *node = this->right;
    }
    free(tmp);
  }
}

void tree_remove(b_tree b, char c) {
  struct tree_t *tree = b;
  remove_impl(&tree->root, c);
}

static struct node_t* max_impl(struct node_t *node) {
  if (!node) {
    return NULL;
  } else if (!node->right) {
    return node;
  } else {
    return max_impl(node->right);
  }
}

char tree_max(b_tree b) {
  struct node_t *max = max_impl(((struct tree_t*)b)->root);
  if (max) {
    return max->data;
  } else {
    return ' ';
  }
}


