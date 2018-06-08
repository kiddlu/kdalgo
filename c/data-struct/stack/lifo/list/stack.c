#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *init(void)
{
  Stack *s = malloc(sizeof(Stack));
  if (!s) {
    printf("no mem！\n");
    return NULL;
  }

  s->head = NULL;
  return s;
}

void final(Stack *s)
{
  if(s == NULL || s->head == NULL)
    return;

  while(!empty(s))
    pop(s);

  free(s);
}

void push(Stack *s, item_t data)
{
  struct stack_node *new;

  new = malloc(sizeof(struct stack_node));
  if(new == NULL){
    printf("no mem\n");
  } else {
    new->item = data;
    new->next = s->head;
    s->head = new;
  }
  return;
}

void pop(Stack *s)
{
  struct stack_node *tmp = NULL;

  if(empty(s)) {
    printf("empty stack");
  } else {
    tmp = s->head;
    s->head = s->head->next;
    free(tmp);
  }
  return;
}

item_t top(Stack *s)
{
  return s->head->item;
}

bool empty(Stack *s)
{
  return s->head == NULL;
}