#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(Stack *s)
{
  s->cap = STACK_LEN;
  make_empty(s);
}

void final(Stack *s)
{
  s->cap = 0;
  make_empty(s);
}

bool empty(Stack *s)
{
  return s->tos == EMPTY_TOS;
}

bool full(Stack *s)
{
  return s->tos == s->cap - 1;
}

void make_empty(Stack *s)
{
  s->tos = EMPTY_TOS;
}

void push(Stack *s, item_t data)
{
  if(full(s)) {
    printf("full stack");
    return;
  } else {
    s->array[++s->tos] = data;
  }
}

void pop(Stack *s)
{
  if(!empty(s))
    s->tos--;
  else {
    printf("empty stack");
  }
}

item_t top(Stack *s)
{
  if(!empty(s))
    return s->array[s->tos];
  else {
    printf("empty stack");
    return 0;
  }
}

