#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

int main( )
{
  PrioQueue *p;
  int i;

  p = init();

  for( i = 0; i < 20; i++ )
    push(p, rand() % 100);

  while( !empty(p)) {
    printf("%d ",top(p));
    pop(p);
  }

  final(p);

  return 0;
}
