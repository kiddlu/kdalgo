#if 1
int sequential_search(int arr[], int len, int key)
{
  int i;
  for(i=0; i<len; i++){
    if(arr[i] == key)
      return i;
  }

  return -1;
}
#else
int sequential_search(int arr[], int len, int key)
{
  int i;
  int tmp = arr[0];
  arr[0] = key;
  for(i=len-1; arr[i] != arr[0]; i--)

  arr[0] = tmp;
  return i;
}
#endif
