#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "avl.h"

static int max(int Lhs, int Rhs)
{
  return Lhs > Rhs ? Lhs : Rhs;
}

AVLTree *init()
{
  AVLTree *at = malloc(sizeof(AVLTree));
  if (!at) {
    printf("no mem!\n");
    return NULL;
  }

  at->root = NULL;
  return at;
}

static void _final(struct avl_node *tn)
{
  if(tn == NULL)
    return;

  _final(tn->left);
  _final(tn->right);
  free(tn);

  return;
}

void final(AVLTree *at)
{
  if(at == NULL || at->root == NULL)
    return;

  _final(at->root);
  free(at);

  return;
}

int get_depth(AVLTree *at)
{
  return 0;
}

int _get_height(struct avl_node *tn)
{
  if(tn == NULL)
    return -1;
  else
    return tn->height;
}

int get_height(AVLTree *at)
{
  return _get_height(at->root);
}

int _get_size(struct avl_node *tn)
{
  int l,r;
  if(tn == NULL)
    return 0;
  l = _get_size(tn->left);
  r = _get_size(tn->right);

  return (l+r+1);
}

int get_size(AVLTree *at)
{
  return _get_size(at->root);
}

static struct avl_node *_search(struct avl_node *tn, item_t key)
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

struct avl_node *search(AVLTree *at, item_t data)
{
  return _search(at->root, data);
}

static struct avl_node *_find_min(struct avl_node *tn)
{
  if(tn == NULL)
    return NULL;
  else if (tn->left == NULL)
    return tn;
  else
    _find_min(tn->left);
}
struct avl_node *find_min(AVLTree *at)
{
    return _find_min(at->root);
}

static struct avl_node *_find_max(struct avl_node *tn)
{
  if(tn == NULL)
    return NULL;
  else if (tn->right == NULL)
    return tn;
  else
    _find_max(tn->right);
}

struct avl_node *find_max(AVLTree *at)
{
    return _find_max(at->root);
}

static struct avl_node *single_totate_with_left(struct avl_node *k2)
{
  struct avl_node *k1;

  k1 = k2->left;
  k2->left = k1->right;
  k1->right = k2;

  k2->height = max(_get_height(k2->left),
                   _get_height(k2->right)) + 1;

  k1->height = max(_get_height(k1->left), _get_height(k2)) + 1;

  return k1;
}

static struct avl_node *single_totate_with_right(struct avl_node *k1)
{
  struct avl_node *k2;

  k2 = k1->right;
  k1->right = k2->left;
  k2->left = k1;

  k1->height = max(_get_height(k1->left),
                   _get_height(k1->right)) + 1;

  k2->height = max(_get_height(k2->right), _get_height(k1)) + 1;

  return k2;
}

static struct avl_node *double_totate_with_left(struct avl_node *k3)
{
  k3->left = single_totate_with_right(k3->left);
  return single_totate_with_left(k3);
}

static struct avl_node *double_totate_with_right(struct avl_node *k1)
{
  k1->right = single_totate_with_left(k1->right);
  return single_totate_with_right(k1);
}

static struct avl_node *_insert(struct avl_node *tn, item_t data)
{
  if(tn == NULL) {
    tn = malloc(sizeof(struct avl_node));
    if(tn == NULL) {
      printf("no mem!\n");
      return NULL;
    } else {
      tn->item = data;
      tn->height = 0;
      tn->left = tn->right = NULL;
    }
  } else if (data < tn->item) {
    //printf("insert %d to %d left child\n", data, tn->item);
    tn->left = _insert(tn->left, data);

    if(_get_height(tn->left) - _get_height(tn->right) == 2) {
      if(data < tn->left->item)
        tn=single_totate_with_left(tn);
      else
        tn=double_totate_with_left(tn);
    }
  } else if(data > tn->item) {
    //printf("insert %d to %d right child\n", data, tn->item);
    tn->right = _insert(tn->right, data);

    if(_get_height(tn->right) - _get_height(tn->left) == 2) {
      if(data > tn->right->item)
        tn=single_totate_with_right(tn);
      else
        tn=double_totate_with_right(tn);
    }
  } else {
    // data us ub the tree already, do nothing
  }

  tn->height = max(_get_height(tn->left), _get_height(tn->right)) + 1;

  return tn;
}

void insert(AVLTree *at, item_t data)
{
  at->root = _insert(at->root, data);
}

void delete(AVLTree *at, item_t data)
{
  //unimplemented
  return;
}

void _traverse(struct avl_node *tn, traverse_mode mode, void (*visit)(struct avl_node *tn))
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

void traverse(AVLTree *at, traverse_mode mode, void (*visit)(struct avl_node *tn))
{
  _traverse(at->root, mode, visit);
}

item_t retrieve(struct avl_node *pos)
{
  return (pos->item);
}

static bool is_bstree(struct avl_node *tn, int low, int high)
{
  if (tn==NULL)
    return true;
  if (low < tn->item && tn->item < high)
    return is_bstree(tn->left, low, tn->item) &&
      is_bstree(tn->right, tn->item, high);
  else
    return false;
}

bool is_bst(AVLTree *at)
{
  return is_bstree(at->root, INT_MIN, INT_MAX);
}

/*=========================================================
balance.c
=========================================================*/
static bool _is_balance(struct avl_node *tn)
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
bool is_balance(AVLTree *at)
{
  return _is_balance(at->root);
}

bool is_avl(AVLTree *at)
{
  return is_balance(at);
}


/*=========================================================
utils.c
=========================================================*/

typedef enum
{
  ROOT_NODE,
  LEFT_NODE,
  RIGHT_NODE,
} tree_node_t;

static void print_tree(struct avl_node *tn, item_t item, tree_node_t type)
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

void print(AVLTree *at)
{
  print_tree(at->root, at->root->item, ROOT_NODE);
}
