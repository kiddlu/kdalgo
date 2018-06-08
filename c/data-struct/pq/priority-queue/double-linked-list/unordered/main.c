#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int main( )
{
  pq *p;
  int i;

  p = init( );
  for( i = 0; i < 100; i++ )
    push(p, rand() % 1000 );

  while(!empty(p)) {
      printf( "%d ", top(p) );
      pop(p);
  }

  final(p);

  return 0;
}
