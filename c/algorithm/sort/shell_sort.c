/* src from Data Structures and Algorithm Analysis in C (Second Edition) */

int shell_sort(int array[], int len)
{
  int i,j;
  int tmp;

  for(int step = len / 2; step > 0; step /= 2){
    for(i = step; i < len; i++){
      tmp = array[i];

      for(j = i; j>=step; j -= step){
        if(tmp < array[j - step]){
          array[j] = array[j - step];
        } else {
          break;
        }
      }

      array[j] = tmp;
    }
  }
  return 0;
}
