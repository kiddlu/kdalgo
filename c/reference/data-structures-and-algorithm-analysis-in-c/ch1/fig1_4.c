#include <stdio.h>

#define print_digit(ch)      ( putchar( (ch) + '0' ) )

void print_out( unsigned int n )
{
  if( n >= 10 )
    print_out( n / 10 );
  //print_digit( n % 10 );
  print_digit( n - (n/10)*10 );
}

int main()
{
  print_out ( 1368 );
  putchar( '\n' );
  return 0;
}
