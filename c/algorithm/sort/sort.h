#ifndef _SORT_H_
#define _SORT_H_

//simple_sort.c
//time:  O(n^2)
//space: O(1)
int bubble_sort(int array[], int len);
int selection_sort(int array[], int len);
int insertion_sort(int array[], int len);

//shell_sort.c
//time:  O(nlog2n)
//space: O(1)
int shell_sort(int array[], int len);

//heap_sort.c
//time:  O(nlogn)
//space: O(1)
int heap_sort(int array[], int len);

//merge_sort.c
//time:  O(nlogn)
//space: O(n)
int merge_sort(int array[], int len);

//quick_sort.c
//time:  O(nlogn)
//space: O(logn)
int quick_sort(int array[], int len);
#endif
