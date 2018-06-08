#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hash.h"

static int next_prime(int nb)
{
  int i;

  if( nb % 2 == 0 )
    nb++;
  for( ; ; nb += 2) {
    for( i = 3; i * i <= nb; i += 2 )
      if( nb % i == 0 )
        goto cont_outer;  /* Sorry about this! */
    return nb;
  cont_outer: ;
  }
}

static unsigned int hash(item_t item, int size)
{
  return item % size;
}

Hashtbl *init(int size)
{
  Hashtbl *h;
  int i;

  h = malloc(sizeof(Hashtbl));
  if(h == NULL) {
    printf("No Mem\n");
    return NULL;
  }

  h->size = next_prime(size);

  h->lists = malloc(sizeof(struct node) * h->size );
  if(h->lists == NULL ){
    printf("No Mem\n");
    return NULL;
  }


  for(i=0; i<h->size; i++ ) {
    h->lists[i] = malloc(sizeof(struct node));
    if( h->lists[i] == NULL ){
      printf("No Mem\n");
      return NULL;
    } else {
      h->lists[i]->item = INT_MIN;
      h->lists[i]->next = NULL;
    }
  }

  return h;
}

void final(Hashtbl *h)
{
  int i;

  for( i = 0; i < h->size; i++ ) {
    struct node *pos = h->lists[i];
    struct node *tmp;

    for( ;pos != NULL; ) {
          tmp = pos->next;
          free(pos);
          pos = tmp;
    }
  }

  free(h->lists);
  free(h);
}


struct node *find(Hashtbl *h, item_t item)
{
  struct node *pos;
  struct node *l;

  l = h->lists[hash(item, h->size)];
  pos = l->next;

  while( pos != NULL && pos->item != item )
    pos = pos->next;

  return pos;
}

void insert(Hashtbl *h, item_t item)
{
  struct node *pos, *new;
  struct node *l;

  pos = find(h, item);
  if(pos == NULL) {
    new = malloc(sizeof(struct node));
    if(new == NULL) {
      printf("NO Mem\n");
      return;
    } else {
      l = h->lists[hash(item, h->size)];
      new->next = l->next;
      new->item = item;
      l->next = new;
    }
  }
}

item_t retrieve(struct node *pos)
{
  return pos->item;
}

void print(Hashtbl *h)
{
  int i;

  for( i = 0; i < h->size; i++ ) {
    struct node *pos = h->lists[i]->next; //lists[i] is head

    printf("list[%d]: ", i);
    for( ;pos != NULL; ) {
      printf("%d ", retrieve(pos));
      pos = pos->next;
    }
    printf("\n");
  }
}
