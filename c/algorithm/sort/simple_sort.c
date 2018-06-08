
/* make sure that there is no function call when sorting */

#if 1
int bubble_sort(int array[], int len)
{
  int i, j;
  int tmp;

  //position
  int start=0;
  int end=len - 1;


//  if (array==NULL || len < 1) {
//    printf("error\n");
//    return -1;
//  } else if (len == 1) {
//    return 0;
//  }


  for(i=start; i<end; i++) {
    for(j=start; j<end-i; j++) {
      if(array[j] > array[j+1]) {
        tmp = array[j];
        array[j] = array[j+1];
        array[j+1]= tmp;
      }
    }
  }
  return 0;
}

int selection_sort(int array[], int len)
{
  int i, j;
  int tmp;

  //position
  int start=0;
  int end=len - 1;

  for(i=start; i<=end; i++)
    for(j=i+1; j<=end; j++)
    {
      if(array[i] > array[j]) {
        tmp = array[i];
        array[i] = array[j];
        array[j]= tmp;
      }
    }
  return 0;
}


int insertion_sort(int array[], int len)
{
  int i, j;
  int tmp;

  //position
  int start=0;
  int end=len - 1;

  //every time insert one member to a sorted array
  for(i=start + 1; i<=end; i++) {
    for(j=i; j > start;j--) {
      if(array[j] < array[j-1]) {
        tmp = array[j];
        array[j] = array[j-1];
        array[j-1] = tmp;
      } else {
        break;
      }
    }
  }
  return 0;
}

#else
int bubble_sort(int array[], int len)
{}

int selection_sort(int array[], int len)
{}

int insertion_sort(int array[], int len)
{}
#endif
