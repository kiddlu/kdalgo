#ifndef _PRIORITY_QUEQUE_H_
#define _PRIORITY_QUEQUE_H_

#include <stdbool.h>

typedef int item_t;

//array
#define MAX_LEN 255
typedef struct
{
  item_t *head;

  int capacity;
  int size;
} PrioQueue;


PrioQueue *init(void);
void final(PrioQueue *p);

void push(PrioQueue *p, item_t data);
void pop(PrioQueue *p);

item_t top(PrioQueue *p);
//void change(PrioQueue *p, struct node *n, int data);
//void delete(PrioQueue *p, struct node *n);
//void join(PrioQueue *p, PrioQueue *q);

bool empty(PrioQueue *p);
bool full(PrioQueue *p);
void print(PrioQueue *p);
#endif
