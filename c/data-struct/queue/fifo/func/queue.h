#ifndef _QUEQUE_H_
#define _QUEQUE_H_
#include <stdbool.h>

#define QUEUE_LEN 256

typedef int item_t;

typedef struct {
  item_t array[QUEUE_LEN];
  unsigned int front;
  unsigned int rear;

  unsigned int capacity;
  unsigned int size;
} Queue;

void init(Queue *q);
void final(Queue *q);
void enqueue(Queue *q, item_t data);
void dequeue(Queue *q);

item_t front(Queue *q);
item_t back(Queue *q);

int size(Queue *q);

bool empty(Queue *q);
bool full(Queue *q);
#endif
