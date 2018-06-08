#include <stdio.h>
#include <time.h>
#include "array.h"
#include "sort.h"

#define ARRAY_LEN 100000

#define LOOP_TIME 1
static void sort_profiler(int array[], int len, int (*func_sort)(int array[], int len))
{

  int loop = LOOP_TIME;
  time_t begin;
  time_t end ;

  begin = clock();
  for(int i=0; i<loop; i++) {
    random_array(array, len, len*10);
    func_sort(array, len);
  }
  end = clock();
  printf("sort time is %.2f \n\n", difftime(end,begin));
}

int main()
{
  int len = ARRAY_LEN;
  int my_array[ARRAY_LEN];

  printf("bubble sort\n");
  sort_profiler(my_array, len, bubble_sort);

  printf("selection sort\n");
  sort_profiler(my_array, len, selection_sort);

  printf("insertion sort\n");
  sort_profiler(my_array, len, insertion_sort);

  printf("shell sort\n");
  sort_profiler(my_array, len, shell_sort);

  printf("heap sort\n");
  sort_profiler(my_array, len, heap_sort);

  printf("merge sort\n");
  sort_profiler(my_array, len, merge_sort);

  printf("quick sort\n");
  sort_profiler(my_array, len, quick_sort);

  //display_array(my_array, len);
  return 0;
}
