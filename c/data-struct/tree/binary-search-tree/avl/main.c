#include <stdio.h>
#include "avl.h"

int main()
{
  AVLTree *at;
  struct avl_node *pos;

  int i;
  int j = 0;

  at = init();

  for( i = 0; i < 50; i++, j = ( j + 7 ) % 50 )
    insert(at, j);
 
  printf("AVL is %s\n", is_avl(at)? "yes" : "no");
  printf( "Min is %d, Max is %d\n", retrieve(find_min(at) ), retrieve(find_max(at) ) );
  printf("Tree size is %d, heigh is %d\n", get_size(at), get_height(at));
/*
  for( i = 0; i < 50; i++ )
    if( ( pos = search(at, i) ) == NULL || retrieve( pos ) != i )
      printf( "Error at %d\n", i );

  for( i = 0; i < 50; i += 2 )
    delete(at, i);

  for( i = 1; i < 50; i += 2 )
    if( ( pos = search(at, i) ) == NULL || retrieve( pos ) != i )
      printf( "Error at %d\n", i );

  for( i = 0; i < 50; i += 2 )
    if( ( pos = search(at, i) ) != NULL )
      printf( "Error at %d\n", i );

  printf( "Min is %d, Max is %d\n", retrieve( find_min(at) ), retrieve( find_max(at) ) );
  printf("Tree size is %d, heigh is %d\n", get_size(at), get_height(at));
  printf("Balance is %s\n", is_balance(at)? "true" : "false");
*/
  print(at);
  final(at);

  return 0;
}