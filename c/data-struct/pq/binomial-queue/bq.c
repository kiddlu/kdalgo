#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "bq.h"

bq *init()
{
  int len = MAX_LEN;

  bq *b = malloc(sizeof(bq));

  b->root = malloc(sizeof(struct node) * len);
  b->size = 0;
  b->capacity = MAX_LEN;

  return b;
}

void final(bq *b)
{
  if(p == NULL)
    return;

  while(!empty(b))
    pop(b);

  free(b);
}

static bool less(item_t a, item_t b)
{
  return (a<b);
}

static struct node *pair(struct node *a, struct node *b)
{
  if(less(a->item, b->item)){
    a->sibling = b->left;
    b->left = a;
    return b;
  } else {
    b->sibling = a->left;
    a->left = b;
    return a;
  }
}

void push(bq *b, item_t data)
{
  if(full(b))
    return;

  int i;
  struct node *c, *t;

  t = malloc(sizeof(struct node));
  c = t; c->left = NULL; c->sibling = NULL;c->item = data;

  for(i = 0; i<b->capacity; i++) {
    if(c == NULL)
      break;

    if(b->root[i] == NULL){
      b->root[i] = c;
      break;
    }

    c = pair(c, b->root[i]);
    b->root[i] = NULL;
  }
  return;
}

void pop(bq *p)
{
  item_t *a = p->head;

  //pop first, we need swap first and last node,
  //then fixdown last in array.
  swap(&a[1], &a[p->size--]);
  fixdown(p, 1);
  return;
}

item_t top(bq *p)
{
  return p->head[1];
}

bool empty(bq *b)
{
  return b->size == 0;
}

bool full(bq *b)
{
  return b->size == p->capacity;
}
