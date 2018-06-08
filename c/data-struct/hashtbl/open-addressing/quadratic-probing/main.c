#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

#define HASH_TABLE_SIZE 13
#define NumItems 60

int main( )
{
  Hashtbl *h;
  unsigned int pos;
  int i=0;
  item_t j=2;
  int cur_size = HASH_TABLE_SIZE;

  h = init(cur_size);

  for( i = 0; i < NumItems; i++, j += 2 ) {
    if( i > cur_size / 2 ) {
        rehash(h);
        printf("rehashing...\n" );
        cur_size *= 2;
    }
    insert(h, j);
  }

  for(i = 0,j = 0; i < NumItems; i++, j += 2 )
    if(retrieve(h, ( pos = find(h, j)) != j ))
      printf( "Error at %d\n", j );

  print(h);
  return 0;
}
