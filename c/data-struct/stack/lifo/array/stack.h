#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

#define STACK_LEN 256
#define EMPTY_TOS (-1)

typedef int item_t;

typedef struct {
  unsigned int cap;
  unsigned int tos; //Top of Stack
  item_t array[STACK_LEN];
} Stack;

void init(Stack *s);
void final(Stack *s);
void push(Stack *s, item_t data);
void pop(Stack *s);

item_t top(Stack *s);

bool empty(Stack *s);
bool full(Stack *s);
void make_empty(Stack *s);
#endif
