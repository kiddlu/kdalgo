#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

pq *init(void)
{
  pq *p = malloc(sizeof(pq));
  struct node *h = malloc(sizeof(struct node));
  struct node *t = malloc(sizeof(struct node));
  if (!p || !h || !t) {
    printf("No Mem！\n");
    return NULL;
  }

  h->prev = t; h->next = t;
  t->prev = h; t->next = h;

  p->head = h; p->tail = t;
  return p;
}

void final(pq *p)
{
  if(p == NULL || p->head == NULL)
    return;

  while(!empty(p))
    pop(p);

  free(p);
}

void push(pq *p, item_t data)
{
  struct node *new;

  new = malloc(sizeof(struct node));
  if(new == NULL){
    printf("No Mem\n");
    return;
  } else {
    new->item = data;
    new->next = p->head->next; new->next->prev = new;
    new->prev = p->head; p->head->next = new;
    return;
  }
}

static struct node *find_max(pq *p)
{
  struct node *max = p->head->next;
  struct node *curr = max;

  for(; curr->next != p->head;) {
    if(curr->item > max->item)
      max = curr;
    curr = curr->next;
  }

  return max;
}

void pop(pq *p)
{
  struct node *max = find_max(p);

  max->next->prev = max->prev;
  max->prev->next = max->next;

  free(max);

  return;
}

item_t top(pq *p)
{
  struct node *max = find_max(p);

  return max->item;
}

bool empty(pq *p)
{
  return (p->head->next->next == p->head); //loop
}
