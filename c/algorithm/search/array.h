#ifndef _ARRAY_H_
#define _ARRAY_H_

/* since array is often in stack not heap, we do not need 'create func' by malloc */
/* array must give its length */

//array.c
int random_array(int array[], int len, unsigned int limit);
int display_array(int array[], int len);
int reverse_array(int array[], int len);
#endif
