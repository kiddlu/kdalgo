/* http://blog.csdn.net/u010155023/article/details/43951129 */

#include <stdlib.h>

#if 0
static int partition_rowe(int array[], int low, int high)
{
  //采用Glenn W. Rowe划分算法
  //根据一个基准数，将数组分为基准数左边小于基准数，基准数右边大于或等于基准数的两部分
  //返回值是基准数在数组中的下标
  //这里选取数组元素的第0位作为基准数
  //low为最低下标，high为最高下标
  int pivot = array[low];//选取基准数
  int low_index = low;
  for (int i = low + 1; i <= high; i++) {
    if (array[i] < pivot) {
      //在序列中找到一个比pivot小的，就递增low_index
      low_index++;
      if (i!=low_index) {//如果i和low_index相等，则在i之前都不存在需要交换的比pivot大的数
        int tmp = array[i];
        array[i] = array[low_index];
        array[low_index] = tmp;
      }
    }
  }
  //low_index的位置就是pivot应处在的位置，low_index指向的总是比pivot小的数
  array[low] = array[low_index];
  array[low_index] = pivot;
  return low_index;
}

static int _qsort(int array[], int start, int end)
{
  if (end > start) {
    int pivot_index = partition_rowe(array, start, end);
    _qsort(array, start, pivot_index - 1);
    _qsort(array, pivot_index + 1, end);
  }
}

int quick_sort(int array[], int len)
{
  //position
  int start=0;
  int end=len - 1;

  _qsort(array, start, end);
}

#else //use c stdlib qsort

static int comp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);//up
  //return (*(int *)a - *(int *)b);//down
}

int quick_sort(int array[], int len)
{
  int start = 0;
  int end = len - 1;

  qsort(&array[start], end + 1, sizeof(int), comp);
  return 0;
}

#endif
