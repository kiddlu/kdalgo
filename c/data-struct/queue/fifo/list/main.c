#include <stdio.h>
#include "queue.h"

int main( )
{
  Queue *q;
  int i;

  q = init( );
  for( i = 0; i < 100; i++ )
    enqueue(q, 100 - i);

  while( !empty(q) ) {
    printf( "%d ", front(q));
    dequeue(q);
  }

  final(q);

  return 0;
}
