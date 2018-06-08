#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "search.h"

#define ARRAY_LEN 500
#define KEY_VALUE 4056
#define LOOP_TIME 500000

/*
  array qsort time comp O(nlogn),
  linear search time comp O(n),
  binary search or jump search time comp O(logn),
  so most time spend on sorting not searching.
*/

static int comp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);//up
  //return (*(int *)a - *(int *)b);//down
}

static int quick_sort(int array[], int len)
{
  int start = 0;
  int end = len - 1;

  qsort(&array[start], end + 1, sizeof(int), comp);
  return 0;
}

static int empty_search(int arr[], int len, int key)
{
  return -1;
}

static int search_profiler(int arr[], int len, int key,
                         int (*func_search)(int arr[], int len, int key))
{

  int loop = LOOP_TIME;
  time_t begin;
  time_t end ;

  int pos;
  int time = 0;

  for(int i=0; i<loop; i++) {
    random_array(arr, len, len*10);
    quick_sort(arr, len);

    begin = clock();
    pos = func_search(arr, len, key);
    end = clock();
    time += (int)difftime(end, begin);
  }
  printf("search time is %d ms, pos is %d\n\n", time, pos);
}


int main()
{
  int len = ARRAY_LEN;
  int my_array[ARRAY_LEN];

  int key = KEY_VALUE;

  int pos;

  printf("random array\n");
  random_array(my_array, len, len *10);
  display_array(my_array, len);

  pos = sequential_search(my_array, len, key);
  printf("pos is %d\n", pos);

  printf("sorted array\n");
  quick_sort(my_array, len);
  pos = binary_search(my_array, len, key);
  printf("pos is %d\n", pos);

  printf("empty search\n");
  search_profiler(my_array, len, key, empty_search);

  printf("binary search\n");
  search_profiler(my_array, len, key, binary_search);

  printf("jump search\n");
  search_profiler(my_array, len, key, jump_search);
}
