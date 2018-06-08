#ifndef _QUEQUE_H_
#define _QUEQUE_H_
#include <stdbool.h>

typedef int item_t;

struct queue_node
{
  item_t item;
  struct queue_node *next;
};

typedef struct {
  struct queue_node *front;
  struct queue_node *rear;
} Queue;

Queue *init(void);
void final(Queue *q);
void enqueue(Queue *q, item_t data);
void dequeue(Queue *q);

item_t front(Queue *q);
item_t back(Queue *q);

int size(Queue *q);

bool empty(Queue *q);
#endif