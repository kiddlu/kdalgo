//all tree method can be solved by recursion

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"

BSTree *init()
{
  BSTree *b = malloc(sizeof(BSTree));
  if (!b) {
    printf("no mem!\n");
    return NULL;
  }

  b->root = NULL;
  return b;
}

static void _final(struct node *tn)
{
  if(tn == NULL)
    return;

  _final(tn->left);
  _final(tn->right);
  free(tn);

  return;
}

void final(BSTree *b)
{
  if(b == NULL || b->root == NULL)
    return;

  _final(b->root);
  free(b);

  return;
}

int get_depth(BSTree *b)
{
  return 0;
}

static int _get_height(struct node *tn)
{
  int l,r;
  if(tn == NULL)
    return -1;

  l = _get_height(tn->left);
  r = _get_height(tn->right);

  if(l > r)
    return l+1;
  else
    return r+1;
}

int get_height(BSTree *b)
{
  return _get_height(b->root);
}

static int _get_size(struct node *tn)
{
  int l,r;
  if(tn == NULL)
    return 0;
  l = _get_size(tn->left);
  r = _get_size(tn->right);

  return (l+r+1);
}

int get_size(BSTree *b)
{
  return _get_size(b->root);
}

static struct node *_search(struct node *tn, item_t key)
{
  if(tn == NULL)
    return NULL;

  if(key < tn->item)
    return _search(tn->left, key);
  else if(key > tn->item)
    return _search(tn->right, key);
  else
    return tn;
}
struct node *search(BSTree *b, item_t data)
{
  return _search(b->root, data);
}

static struct node *_find_min(struct node *tn)
{
  if(tn == NULL)
    return NULL;
  else if (tn->left == NULL)
    return tn;
  else
    _find_min(tn->left);
}
struct node *find_min(BSTree *b)
{
    return _find_min(b->root);
}

static struct node *_find_max(struct node *tn)
{
  if(tn == NULL)
    return NULL;
  else if (tn->right == NULL)
    return tn;
  else
    _find_max(tn->right);
}
struct node *find_max(BSTree *b)
{
    return _find_max(b->root);
}

static struct node *_insert(struct node *tn, int data)
{
  if (tn == NULL) {
    tn = malloc(sizeof(struct node));
    if(tn == NULL) {
      printf("No Memory\n");
      return NULL;
    } else {
      tn->item = data;
      tn->left = tn->right = NULL;
    }
  } else if (data < tn->item) {
    tn->left = _insert(tn->left, data);
  } else if (data > tn->item) {
    tn->right = _insert(tn->right, data);
  } else {
    //data is in bst already, do nothing.
  }

  return tn;
}

void insert(BSTree *b, item_t data)
{
  b->root = _insert(b->root, data);
}

static struct node *_delete(struct node *tn, item_t data)
{
  struct node *tmp;

  if(tn == NULL) {
    printf("Not Found");
    return NULL;
  } else if (data < tn->item){
    tn->left = _delete(tn->left, data);
  } else if (data > tn->item) {
    tn->right = _delete(tn->right, data);
  } else { //found node
    if(tn->left && tn->right) { //2 children
      //replace with smallest in right subtree
      tmp = _find_min(tn->right);
      tn->item = tmp->item;
      tn->right = _delete(tn->right, tn->item);
    } else { //one or zero child
      tmp = tn;
      if(tn->left == NULL)
        tn = tn->right;
      else if(tn->right == NULL)
        tn = tn->left;
      free(tmp);
    }
  }

  return tn;
}
void delete(BSTree *b, item_t data)
{
  _delete(b->root, data);
}

void _traverse(struct node *tn, traverse_mode mode, void (*visit)(struct node *tn))
{
  if(tn == NULL)
    return;

  switch(mode) {
  case PRE_ORDER:
    (*visit)(tn);
    _traverse(tn->left,  mode, visit);
    _traverse(tn->right, mode, visit);
    break;
  case IN_ORDER:
    _traverse(tn->left,  mode, visit);
    (*visit)(tn);
    _traverse(tn->right, mode, visit);
    break;
  case LAST_ORDER:
    _traverse(tn->left,  mode, visit);
    _traverse(tn->right, mode, visit);
    (*visit)(tn);
    break;
  default: return;
  }
}

void traverse(BSTree *b, traverse_mode mode, void (*visit)(struct node *tn))
{
  _traverse(b->root, mode, visit);
}

item_t retrieve(struct node *pos)
{
  return (pos->item);
}

static bool is_bstree(struct node *tn, int low, int high)
{
  if (tn==NULL)
    return true;
  if (low < tn->item && tn->item < high)
    return is_bstree(tn->left, low, tn->item) &&
      is_bstree(tn->right, tn->item, high);
  else
    return false;
}

bool is_bst(BSTree *b)
{
  return is_bstree(b->root, INT_MIN, INT_MAX);
}

/*=========================================================
balance.c
=========================================================*/

//standard bst do not have member "size" in struct node{},
//if we want balance, we need weight-balanced tree
//https://en.wikipedia.org/wiki/Weight-balanced_tree
//but, we can also use get_size() to get weight...

static bool _is_balance(struct node *tn)
{
  int l,r;
  if (tn==NULL)
    return 1;

  l=_get_height(tn->left);
  r=_get_height(tn->right);

  if (abs(l-r)>1)
    return 0;
  else
    return _is_balance(tn->left) && _is_balance(tn->right);
}
bool is_balance(BSTree *b)
{
  return _is_balance(b->root);
}

static struct node *rotate_right(struct node *n)
{
  struct node *tmp = n->left;
  n->left = tmp->right;
  tmp->right = n;
  return tmp;
}

static struct node *rotate_left(struct node *n)
{
  struct node *tmp = n->right;
  n->right = tmp->left;
  tmp->left = n;
  return tmp;
}

static struct node *part(struct node *tn, int k)
{
  if(tn == NULL)
    return NULL;

  int size = _get_size(tn->left);

  if (k < size) {
    tn->left = part(tn->left, k);
    tn = rotate_right(tn);
  } else if (k > size) {
    tn->right = part(tn->right, k - size - 1);
    tn = rotate_left(tn);
  }

  return tn;
}

static struct node *_balance(struct node *tn)
{
  if(_get_size(tn) < 2)
    return tn;

  tn = part(tn, _get_size(tn)/2);
  tn->left = _balance(tn->left);
  tn->right = _balance(tn->right);

  return tn;
}

void balance(BSTree *b)
{
  b->root = _balance(b->root);
  return;
}


/*=========================================================
utils.c
=========================================================*/
/*
static void display(BSTree *tree)
{
  printf("size:%d item:%d\n", get_size(tree), tree->item);
}

void display_preorder(BSTree *tree)
{
  traverse(tree, PRE_ORDER, display);
}

void display_inorder(BSTree *tree)
{
  traverse(tree, IN_ORDER, display);
}

void display_lastorder(BSTree *tree)
{
  traverse(tree, LAST_ORDER, display);
}
*/

typedef enum
{
  ROOT_NODE,
  LEFT_NODE,
  RIGHT_NODE,
} tree_node_t;

static void print_tree(struct node *tn, item_t item, tree_node_t type)
{
  if(tn == NULL)
    return;

  if(type==ROOT_NODE)    // tree is root
    printf("%2d is root\n", tn->item);
  else                // tree is sub
    printf("%2d is %2d's %6s child\n", tn->item, item, type==RIGHT_NODE?"right" : "left");

    print_tree(tn->left,  tn->item, LEFT_NODE);
    print_tree(tn->right, tn->item, RIGHT_NODE);
}

void print(BSTree *b)
{
  print_tree(b->root, b->root->item, ROOT_NODE);
}