#include <stdio.h>
#include "slist.h"

int main()
{
  slist *l;
  int len = 25;

  l = create(len);
  print(l);

  printf("\nnow insert 50 before 2\n");
  insert(l, 2, 50);
  print(l);

  printf("\nnow reverse this list\n");
  reverse(l);
  print(l);

  printf("\nnow delete last node\n");
  delete(l, get_length(l));
  print(l);

  printf("\nnow get max is %d\n", get_max(l));

  printf("\nuse secletion sort\n");
  selection_sort(l);
  print(l);

//  printf("\nuse insertion sort\n");
//  random(list);
//  print(list);
//  list = insertion_sort(list);
//  print(list);
//
//  printf("\nuse bubble sort\n");
//  random(list);
//  print(list);
//  list = bubble_sort(list);
//  print(list);

  final(l);
}
