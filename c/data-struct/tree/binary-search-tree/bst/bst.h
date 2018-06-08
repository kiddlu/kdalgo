#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef int item_t;

struct node
{
  item_t item;
  struct node *left;
  struct node *right;
};

typedef struct {
  struct node *root;
} BSTree;

BSTree *init(void);
void final(BSTree *b);

void insert(BSTree *b, item_t data);
void delete(BSTree *b, item_t data);
struct node *search(BSTree *b, item_t data);

int get_depth(BSTree *b);
int get_height(BSTree *b);
int get_size(BSTree *b);

struct node *find_max(BSTree *b);
struct node *find_min(BSTree *b);

typedef enum {
	PRE_ORDER,
	IN_ORDER,
	LAST_ORDER,
} traverse_mode;
void traverse(BSTree *b, traverse_mode mode, void (*visit)(struct node *tn));

item_t retrieve(struct node *pos);
bool is_bst(BSTree *b);

//balance.c
bool is_balance(BSTree *b);
void balance(BSTree *b);

//utils.c
void print(BSTree *b);
#endif
