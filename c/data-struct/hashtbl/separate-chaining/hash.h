#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdbool.h>

typedef int item_t;

struct node
{
  item_t item;
  struct node *next;
};

typedef struct
{
  int size;
  struct node **lists;
} Hashtbl;


Hashtbl *init(int size);
void final(Hashtbl *h);

void insert(Hashtbl *h, item_t item);
struct node *find(Hashtbl *h, item_t item);
item_t retrieve(struct node *pos);

void print(Hashtbl *h);
#endif
