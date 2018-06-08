#include <stdio.h>
#include "bst.h"

int main()
{
  BSTree *b;
  struct node *pos;

  int i;
  int j = 0;

  b = init();

  for( i = 0; i < 50; i++, j = ( j + 7 ) % 50 )
    insert(b, j);

  printf("BST is %s\n", is_bst(b)? "yes" : "no");
  printf( "Min is %d, Max is %d\n", retrieve( find_min(b) ), retrieve( find_max(b) ) );
  printf("Tree size is %d, heigh is %d\n", get_size(b), get_height(b));
  printf("Balance is %s\n", is_balance(b)? "true" : "false");

  balance(b);
  printf("Tree size is %d, heigh is %d\n", get_size(b), get_height(b));
  printf("Balance is %s\n", is_balance(b)? "true" : "false");

  for( i = 0; i < 50; i++ )
    if( ( pos = search(b, i) ) == NULL || retrieve(pos) != i )
      printf( "Error at %d\n", i );

  for( i = 0; i < 50; i += 2 )
    delete(b, i);

  for( i = 1; i < 50; i += 2 )
    if( ( pos = search(b, i) ) == NULL || retrieve( pos ) != i )
      printf( "Error at %d\n", i );

  for( i = 0; i < 50; i += 2 )
    if( ( pos = search(b, i) ) != NULL )
      printf( "Error at %d\n", i );

  printf( "Min is %d, Max is %d\n", retrieve( find_min(b) ), retrieve( find_max(b) ) );
  printf("Tree size is %d, heigh is %d\n", get_size(b), get_height(b));
  printf("Balance is %s\n", is_balance(b)? "true" : "false");

  print(b);
  final(b);

  return 0;
}
