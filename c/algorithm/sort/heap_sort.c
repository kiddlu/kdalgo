/* src from Data Structures and Algorithm Analysis in C (Second Edition) */

//define faster than static inline
#define left_child( i )  ( 2 * ( i ) + 1 )
/*
static inline int left_child(int i)
{
  return (2 * i + 1);
}
*/

void perc_down(int array[], int i, int len)
{
  int child;
  int tmp;

  for(tmp=array[i]; left_child(i) < len; i = child){
    child = left_child(i);
    if(child != len -1 && array[child + 1] > array[child])
      child++;
    if(tmp < array[child])
      array[i] = array[child];
    else
      break;
  }
  array[i] = tmp;
}

int heap_sort(int array[], int len)
{
  int i;
  for(i = len / 2; i>=0; i--)
    perc_down(array, i, len);

  for(i = len - 1; i>0; i--) {
    int tmp = array[0];
    array[0] = array[i];
    array[i] = tmp;

    perc_down(array, 0, i);
  }
  return 0;
}
