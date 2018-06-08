#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "slist.h"

slist *create(int len)
{
  int i;
  slist *l = init();

  for(i=1; i<=len; i++) {
    insert(l, i, rand()%100);
  }
  return l;
}

void print(slist *l)
{
  if(l == NULL || l->head ==NULL) {
    return;
  }

  struct node *curr = l->head;
  for(;curr != NULL;) {
    printf("%d ", curr->item);
    curr=curr->next;
  }
  printf("\n");
}


struct node *find_max_prev(slist *l)
{
  if(l->head->next == NULL)
    return NULL;

  int max = l->head->item;
  struct node *prev = l->head;
  struct node *curr = l->head->next;
  struct node *max_prev = NULL;

  for (; curr != NULL;) {
    if (max < curr->item) {
      max = curr->item;
      max_prev = prev;
    }
    prev = curr;
    curr = curr->next;
  }

  return max_prev;
}

struct node *find_max(slist *l)
{
  struct node *prev = find_max_prev(l);

  if(prev == NULL) {//one node
    return l->head;
  } else {
    return prev->next;
  }
}
