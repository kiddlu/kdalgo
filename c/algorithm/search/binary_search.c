#include <stdio.h>
#include <stdlib.h>

#if 0
int binary_search(int arr[], int len, int value)
{
  int low, high, mid;
  low = 0;
  high = len - 1;

  for(;low <= high;){
    mid = (low + high) / 2;
    if(arr[mid] == value)
      return mid;
    else if (arr[mid] > value)
      high = mid - 1;
    else if (arr[mid] < value)
      low = mid + 1;
  }

  return -1;
}

//static int _bsearch(int arr[], int value, int low, int high)
//{
//  int mid = low + ((high-low) / 2);
//  if (arr[mid] == value)
//    return mid;
//  else if (arr[mid] > value)
//    return _bsearch(arr, value, low,mid-1);
//  else if (arr[mid] < value)
//    return _bsearch(arr, value, mid+1,high);
//}
//
//int binary_search(int arr[], int len, int value)
//{
//  int low = 0;
//  int high = len -1;
//
//  return _bsearch(arr, value, low, high);
//}

#else
int comp(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int binary_search(int arr[], int len, int value)
{
  int *pos;
  pos = (int *)bsearch(&value, arr, len, sizeof(int), comp);
  if( pos == NULL )
    return -1;
  else
    return (pos - arr); //pointer will count index itself
}

#endif
