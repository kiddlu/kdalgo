#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <stdbool.h>

typedef int item_t;

typedef enum
{
  Legitimate,
  Empty,
  Deleted,
} entry_t;

struct node
{
  item_t item;
  entry_t info;
};

typedef struct
{
  int size;
  struct node *cells;
} Hashtbl;


Hashtbl *init(int size);
void final(Hashtbl *h);

void insert(Hashtbl *h, item_t item);
unsigned int find(Hashtbl *h, item_t item);
item_t retrieve(Hashtbl *h, unsigned int pos);

void rehash(Hashtbl *h);
void print(Hashtbl *h);
#endif
