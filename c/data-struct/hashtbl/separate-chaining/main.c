#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define HASH_TABLE_SIZE 13

int main( )
{
  Hashtbl *h;
  struct node *pos;
  int i=0;
  item_t j=0;

  h = init(HASH_TABLE_SIZE);

  for( i = 0; i < 40; i++, j += 1 ) {
    insert(h, j);
  }

  for(i = 0,j = 0; i < 40; i++, j += 1 )
    if((pos = find(h, j)) == NULL || retrieve(pos) != j )
        printf( "Error at %d\n", j );

  print(h);
  return 0;
}
