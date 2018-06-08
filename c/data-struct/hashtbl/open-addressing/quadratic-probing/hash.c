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

  h->cells = malloc(sizeof(struct node) * h->size );
  if(h->cells == NULL ){
    printf("No Mem\n");
    return NULL;
  }

  for(i=0; i<h->size; i++ ) {
    h->cells[i].info = Empty;
  }

  return h;
}

void final(Hashtbl *h)
{
  free(h->cells);
  free(h);
}


unsigned int find(Hashtbl *h, item_t item)
{
  unsigned int pos;
  int collision_nr = 0;

  pos = hash(item, h->size);
  while(h->cells[pos].info != Empty &&
        h->cells[pos].item != item) {
    pos += 2 * ++collision_nr - 1;
    if(pos >= h->size)
      pos -= h->size;
  }

  return pos;
}

void insert(Hashtbl *h, item_t item)
{
  unsigned int pos;

  pos = find(h, item);
  if(h->cells[pos].info != Legitimate) {
    h->cells[pos].info = Legitimate;
    h->cells[pos].item = item;
  }
}

void rehash(Hashtbl *h)
{
  int i, old_size;
  struct node *old_cells;

  old_cells = h->cells;
  old_size = h->size;

  h->size = next_prime(2 * h->size);
  h->cells = malloc(sizeof(struct node) * h->size );
  if(h->cells == NULL ){
    printf("No Mem\n");
    return;
  }

  for(i=0; i<h->size; i++ ) {
    h->cells[i].info = Empty;
  }

  for(i = 0; i<old_size; i++)
    if(old_cells[i].info == Legitimate)
      insert(h, old_cells[i].item);

  free(old_cells);

  return;
}

item_t retrieve(Hashtbl *h, unsigned int pos)
{
  return h->cells[pos].item;
}

void print(Hashtbl *h)
{
  printf("size is %d\n", h->size);
  for(int i = 0; i<h->size; i++)
    printf("%d ", h->cells[i].item);
}
