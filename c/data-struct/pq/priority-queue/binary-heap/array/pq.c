#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "pq.h"

PrioQueue *init()
{
  int len = MAX_LEN;

  PrioQueue *p = malloc(sizeof(PrioQueue));
  p->head = malloc(sizeof(item_t) * (len+1));
  memset(p->head, 0, sizeof(item_t) * (len+1));

  p->size = 0;
  p->capacity = len;
  p->head[0] = INT_MIN;
  return p;
}

void final(PrioQueue *p)
{
  if(p == NULL)
    return;
  free(p->head);
  free(p);
}

void swap(item_t *a, item_t *b)
{
  item_t tmp = *a;
  *a = *b;
  *b = tmp;
}

static void fixup(PrioQueue *p, int i)
{
  item_t *a = p->head;

  //parent  a[i/2]
  //child   a[i]
  //insert as a child and comp with parent,
  //if parent < child then swap
  for(; i>1 && (a[i/2] < a[i]); i /= 2) {
    swap(&a[i/2], &a[i]);
  }
}

static void fixdown(PrioQueue *p, int i)
{
  item_t *a = p->head;
  int size = p->size;

  //parent   a[i];
  //l_child  a[j];
  //r_child  a[j+1];
  for(int j = i*2; j <= size; i=j, j=2*i) {
    if(j < size && a[j] < a[j+1])
      j++;

    if(a[i] < a[j])
      swap(&a[i], &a[j]);
  }
}

void push(PrioQueue *p, item_t data)
{
  if(full(p))
    return;

  item_t *a = p->head;
  a[++p->size] = data;
  fixup(p, p->size);

  return;
}

void pop(PrioQueue *p)
{
  item_t *a = p->head;

  //pop first, we need swap first and last node,
  //then fixdown last in array.
  swap(&a[1], &a[p->size--]);
  fixdown(p, 1);
  return;
}

item_t top(PrioQueue *p)
{
  return p->head[1];
}

bool empty(PrioQueue *p)
{
  return p->size == 0;
}

bool full(PrioQueue *p)
{
  return p->size == p->capacity;
}

void print(PrioQueue *p)
{
  for(int i=1; i<=p->size;i++)
    printf("%d ", p->head[i]);
  printf("\n");
}
