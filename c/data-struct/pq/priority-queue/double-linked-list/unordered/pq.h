#ifndef _PRIORITY_QUEQUE_H_
#define _PRIORITY_QUEQUE_H_

#include <stdbool.h>

typedef int item_t;

//double linked list
struct node
{
  item_t item;
  struct node *prev;
  struct node *next;
};

typedef struct {
  struct node *head;
  struct node *tail;
} pq;

pq *init(void);
void final(pq *p);

void push(pq *p, item_t data);
void pop(pq *p);

item_t top(pq *p);

void change(pq *p, struct node *n, item_t data);
void delete(pq *p, struct node *n);
void join(pq *p, pq *q);

bool empty(pq *p);
#endif
