#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"

int random_array(int array[], int len, unsigned int limit)
{
  //srand(clock());

  if(array == NULL || len == 0) {
    printf("empty array\n");
    return -1;
  }

  if(!limit)
	  for(int i=0; i < len;i++) {
		  array[i] = rand();
    }
  else
	  for(int i=0; i < len;i++) {
		  array[i] = rand() % limit;
    }

  return 0;
}

int display_array(int array[], int len)
{
  //  return 0;

  if(array == NULL || len == 0) {
    printf("empty array\n");
    return -1;
  }

  for(int i=0; i < len; i++) {
      printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

int reverse_array(int array[], int len)
{
  int tmp[len];
  for(int i=0; i<len; i++)
    tmp[i] = array[len -1 -i];

  for(int i=0; i<len; i++)
    array[i] = tmp[i];

  return 0;
}
