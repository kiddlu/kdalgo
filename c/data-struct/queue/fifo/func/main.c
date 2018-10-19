#include <stdio.h>
#include "queue.h"

int main( )
{
  Queue queue;
  Queue *q = &queue;
  int i;

  init(q);
  for( i = 0; i < 100; i++ )
    enqueue(q, 100 - i);

  while(!empty(q)) {
    printf( "%d ", front(q));
    dequeue(q);
  }

  final(q);

  return 0;
}
