#include <stdio.h>
#include <math.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
//int min(int a, int b) {
//	return a < b ? a : b;
//}

int jump_search(int arr[], int len, int key)
{
  int jump = (int)sqrt(len);
  int left = 0;
  int right = 0;

  while (left < len && arr[left] <= key) {
    right = min(len - 1, left + jump);

    if (arr[left] <= key && arr[right] >= key) {
      break;
    }

    left += jump;
  }

  if (left >= len || arr[left] > key) {
    return -1;
  }

  right = min(len - 1, right);

	int i;

  for (i = left; i <= right && arr[i] <= key; ++i) {
    if (arr[i] == key) {
      return i;
    }
  }

  return -1;
}
