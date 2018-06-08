#include <stdio.h>

int bad(unsigned int n)
{
  if(n == 0)
    return 0;
  else
    return bad(n / 3 + 1) + n -1;
}

int main()
{
  printf( "Bad is infinite recursion\n" );
  return 0;
}
