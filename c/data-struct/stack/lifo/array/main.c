#include <stdio.h>
#include "stack.h"

int main( )
{
  Stack stack;
  Stack *s = &stack;
  int i;

  init(s);
  for( i = 0; i < 100; i++ )
    push(s, i*2);

  while(!empty(s)) {
    printf( "%d ", top(s));
    pop(s);
  }

  final(s);

  return 0;
}
