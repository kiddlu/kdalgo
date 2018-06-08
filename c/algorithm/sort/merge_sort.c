#include <stdio.h>
#include <stdlib.h>

static void _merge(int arr[], int tmp_arr[], int left_start, int right_start, int right_end)
{
  int left_end, arr_len;
  int rpos, lpos, tmppos;

  left_end = right_start - 1;
  arr_len = right_end - left_start + 1;

  lpos = tmppos = left_start;
  rpos = right_start;

  /* main loop */
  while( lpos <= left_end && rpos <= right_end )
    if( arr[ lpos ] <= arr[ rpos ] )
      tmp_arr[ tmppos++ ] = arr[ lpos++ ];
    else
      tmp_arr[ tmppos++ ] = arr[ rpos++ ];

  while( lpos <= left_end )  /* copy rest of first half */
    tmp_arr[ tmppos++ ] = arr[ lpos++ ];
  while( rpos <= right_end ) /* copy rest of second half */
    tmp_arr[ tmppos++ ] = arr[ rpos++ ];

  /* copy tmp_arr back */
  for(int i = 0; i < arr_len; i++, right_end-- )
    arr[ right_end ] = tmp_arr[ right_end ];
}


static void _msort(int arr[], int tmp_arr[], int left, int right)
{
  int center;

  if(left < right) {
    center = (left + right) / 2;
    _msort(arr, tmp_arr, left, center);
    _msort(arr, tmp_arr, center + 1, right);
    _merge(arr, tmp_arr, left, center+1, right);
  }
}

int merge_sort(int array[], int len)
{
    int *tmp_arr;

    int start = 0;
    int end = len - 1;

    tmp_arr = malloc( len * sizeof( int ) );
    if( tmp_arr != NULL ) {
        _msort( array, tmp_arr, start, end );
        free( tmp_arr );
    } else
      printf("No space for tmp array!!!\n");

    return 0;
}
