int shell_sort(int array[], int len)
{
  int i,j;
  int temp;

  for(int i=0; i<len; i++)
  {
     for(int j=1; i<len-1; j++)
	 {
		 if(array[j]<array[j-1])
		 {

			 temp = array[j];
			 a[j] = a[j-1];
			 a[j-1] = temp;
		 }
	 }
  }

  return 0;
}
