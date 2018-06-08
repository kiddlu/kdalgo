#include <stdio.h>
#include "stack.h"

int main( )
{
  Stack *s;
  int i;

  s = init( );
  for( i = 0; i < 100; i++ )
    push(s, i*2);

  while(!empty(s)) {
    printf( "%d ", top(s));
    pop(s);
  }

  final(s);

  return 0;
}
