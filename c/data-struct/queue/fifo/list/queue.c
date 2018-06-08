#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *init(void)
{
  Queue *q = malloc(sizeof(Queue));
  if (!q) {
    printf("No Mem！\n");
    return NULL;
  }

  q->front = NULL;
  q->rear = NULL;
  return q;
}

void final(Queue *q)
{
  if(q == NULL || q->front == NULL)
    return;

  while(!empty(q))
    dequeue(q);
  free(q);
}

void enqueue(Queue *q, item_t data)
{
  struct queue_node *new;

  new = malloc(sizeof(struct queue_node));
  if(new == NULL){
    printf("no mem\n");
  } else {
    new->item = data;
    new->next = NULL;
    if(q->front == NULL) {
      q->front = new;
    }

    if(q->rear == NULL) {
      q->rear = new;
    } else {
      q->rear->next = new;
      q->rear = new;
    }
    return;
  }
}

void dequeue(Queue *q)
{
  struct queue_node *tmp = NULL;

  if(empty(q)) {
    printf("empty queue");
    return;
  }

  if (q->front == q->rear) { //only one node in queue
    tmp = q->front;
    q->front = NULL;
    q->rear = NULL;
  } else {
    tmp = q->front;
    q->front = q->front->next;
  }

  free(tmp);

  return;
}

item_t front(Queue *q)
{
  return q->front->item;
}

item_t back(Queue *q)
{
  return q->rear->item;
}

bool empty(Queue *q)
{
  return q->front == NULL;
}