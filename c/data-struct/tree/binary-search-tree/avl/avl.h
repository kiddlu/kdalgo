#ifndef _AVL_H_
#define _AVL_H_

#include <stdbool.h>

typedef int item_t;

struct avl_node
{
  item_t item;
  struct avl_node *left;
  struct avl_node *right;
  int height;
};

typedef struct
{
  struct avl_node *root;
} AVLTree;

AVLTree *init(void);
void final(AVLTree *at);

void insert(AVLTree *at, item_t data);
void delete(AVLTree *at, item_t data);
struct avl_node *search(AVLTree *at, item_t data);

int get_depth(AVLTree *at);
int get_height(AVLTree *at);
int get_size(AVLTree *at);

struct avl_node *find_max(AVLTree *at);
struct avl_node *find_min(AVLTree *at);

typedef enum {
	PRE_ORDER,
	IN_ORDER,
	LAST_ORDER,
} traverse_mode;
void traverse(AVLTree *at, traverse_mode mode, void (*visit)(struct avl_node *tn));

item_t retrieve(struct avl_node *pos);
bool is_avl(AVLTree *at);

//balance.c
bool is_balance(AVLTree *at);

//utils.c
void print(AVLTree *at);
#endif