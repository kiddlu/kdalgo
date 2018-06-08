#ifndef _STACK_H_
#define _STACK_H_
#include <stdbool.h>

typedef int item_t;

struct stack_node
{
  item_t item;
  struct stack_node *next;
};

typedef struct {
  struct stack_node *head;
} Stack;

Stack *init(void);
void final(Stack *s);
void push(Stack *s, item_t data);
void pop(Stack *s);

item_t top(Stack *s);

bool empty(Stack *s);
#endif