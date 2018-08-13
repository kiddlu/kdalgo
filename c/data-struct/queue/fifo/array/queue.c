#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init(Queue *q)
{
  if (!q) {
    printf("Error Queue\n");
    return;
  }

  q->front = 1;
  q->rear = 0;
  q->size = 0;
  q->capacity = QUEUE_LEN;

  //memset(q->array, 0, sizeof(item_t) * QUEUE_LEN);

  return;
}

void final(Queue *q)
{
  if (!q) {
    printf("Error Queue\n");
    return;
  }

  q->front = 1;
  q->rear = 0;
  q->size = 0;
  q->capacity = 0;
  return;
}

static unsigned int succ(Queue *q, unsigned int value)
{
  if( ++value == q->capacity )
    value = 0;
  return value;
}

void enqueue(Queue *q, item_t data)
{
  if(full(q)) {
    printf("queue full\n");
    return;
  } else {
    q->size++;
    q->rear = succ(q, q->rear);
    q->array[q->rear] = data; 
  }
}

void dequeue(Queue *q)
{
  if(empty(q)) {
    printf("empty queue\n");
    return;
  } else {
    q->size--;
    q->front = succ(q, q->front); 
  }
}

item_t front(Queue *q)
{
  return q->array[q->front];
}

item_t back(Queue *q)
{
  return q->array[q->rear];
}

int size(Queue *q)
{
  return q->size;
}

bool empty(Queue *q)
{
  return q->size == 0;
}

bool full(Queue *q)
{
  return q->size == q->capacity;
}
