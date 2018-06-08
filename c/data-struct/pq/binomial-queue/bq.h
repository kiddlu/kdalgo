#ifndef _BINOMIAL_QUEQUE_H_
#define _BINOMIAL_QUEQUE_H_

#include <stdbool.h>
typedef int item_t;

#define MAX_LEN 256
//tree
struct node
{
  item_t item;
  struct node *left;
  struct node *sibling;
};

typedef struct
{
  struct node *root;

  int capacity;
  int size;
} bq;

bq *init(void);
void final(bq *p);

void push(bq *p, item_t data);
void pop(bq *p);

item_t top(bq *p);
//void change(bq *p, struct node *n, int data);
//void delete(bq *p, struct node *n);
void join(bq *p, bq *q);

bool empty(bq *p);
bool full(bq *b)
#endif
