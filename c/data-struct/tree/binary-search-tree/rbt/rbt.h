#ifndef _RBT_H_
#define _RBT_H_

#include <stdbool.h>

typedef int item_t;

typedef enum 
{
  RED_NODE,
  BLACK_NODE,
} color_t;

struct rb_node
{
  item_t item;
  struct rb_node *left;
  struct rb_node *right;
  color_t color;
};

typedef struct
{
  struct rb_node *root;
  struct rb_node null_node;
} RBTree;

RBTree *init(void);
void final(RBTree *at);

void insert(RBTree *at, item_t data);
void delete(RBTree *at, item_t data);

int get_depth(RBTree *at);
int get_height(RBTree *at);
int get_size(RBTree *at);

struct rb_node *find_max(RBTree *at);
struct rb_node *find_min(RBTree *at);
struct rb_node *search(RBTree *at, item_t data);
item_t retrieve(struct rb_node *pos);
//utils.c
void print(RBTree *at);
#endif