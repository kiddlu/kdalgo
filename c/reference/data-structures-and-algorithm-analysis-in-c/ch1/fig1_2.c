#include <stdio.h>

int func(int x)
{
  if(x == 0)
    return 0;
  else
    return 2 * func(x-1) + x * x;
}

int main()
{
  printf("func(5) = %d\n", func(5));
  return 0;
}
