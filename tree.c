#include "stdlib.h"
#include "stdio.h"
#include "tree.h"

#define true 1
#define false 0

struct _node {
  char data;
  struct _node *left;
  struct _node *right;
};

struct _tree {
  struct _node *root;
};

struct _node* node_init(char c) {
  struct _node *node = malloc(sizeof(struct _node));
  node->data = c;
  node->left = NULL;
  node->right = NULL;
  return node;
}

b_tree tree_init(void) {
  struct _tree *tree = malloc(sizeof(struct _tree));
  tree->root = NULL;
  return tree;
}

static void free_impl(struct _node *node) {

  if (node->left) {
    free_impl(node->left);
  }

  if (node->right) {
    free_impl(node->right);
  }

  free(node);
}

void tree_free(b_tree b) {
  struct _tree *tree = b;
  if (tree->root) {
    free_impl(tree->root);
  }
  free(tree);
}

static void add_impl(struct _node **node, char c) {
  struct _node *this = *node;
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
  struct _tree *tree = b;
  add_impl(&tree->root, c);
}

static int size_impl(struct _node *node) {
  if (node) {
    int left = size_impl(node->left);
    int right = size_impl(node->right);
    return 1 + right + left;
  } else {
    return 0;
  }
}

int tree_size(b_tree b) {
  struct _tree *tree = b;
  return size_impl(tree->root);
}

static int8_t contains_impl(struct _node *node, char c) {
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
  return contains_impl(((struct _tree*)b)->root, c);
}

static void print_impl(struct _node *node, int depth) {
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
  print_impl(((struct _tree*)b)->root, 0);
}

static struct _node* min_impl(struct _node *node) {
  if (!node) {
    return NULL;
  } else if (!node->left) {
    return node; 
  } else {
    return min_impl(node->left);
  }
}

char tree_min(b_tree b) {
  struct _node *min = min_impl(((struct _tree*)b)->root);
  if (min) {
    return min->data;
  } else {
    return ' ';
  }
}

static void remove_impl(struct _node **node, char c) {
  struct _node *this = *node;
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
    struct _node *tmp = this;
    if (this->left) {
      *node = this->left;
    } else {
      *node = this->right;
    }
    free(tmp);
  }
}

void tree_remove(b_tree b, char c) {
  struct _tree *tree = b;
  remove_impl(&tree->root, c);
}

static struct _node* max_impl(struct _node *node) {
  if (!node) {
    return NULL;
  } else if (!node->right) {
    return node;
  } else {
    return max_impl(node->right);
  }
}

char tree_max(b_tree b) {
  struct _node *max = max_impl(((struct _tree*)b)->root);
  if (max) {
    return max->data;
  } else {
    return ' ';
  }
}


