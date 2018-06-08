/* All linked list quiz can be solved by struct list *prev, *curr, *post; */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "slist.h"

slist *init(void)
{
  slist *l = malloc(sizeof(slist));
  if (!l) {
    printf("No Mem！\n");
    return NULL;
  }
  l->head = NULL;
  return l;
}

void final(slist *l)
{
  struct node *curr = l->head;
  struct node *post;

  for(;curr != NULL; ) {
    post = curr->next;
    free(curr);
    curr = post;
  }

  free(l);
  return;
}


void reverse(slist *l)
{
  struct node *prev = NULL;
  struct node *curr = l->head;
  struct node *post = curr->next;

  for(; curr != NULL; ){
    post = curr->next; //save curr->next pointer to post
    curr->next = prev; //set curr->next back to prev
    prev = curr; //linked list forward
    curr = post; //forward
  }

  l->head = prev;//head must be prev not curr，since curr==NULL now
  return;
}

int get_length(slist *l)
{
  struct node *curr = l->head;
  int len = 0;
  for(;curr != NULL;){
    len++;
    curr=curr->next;
  }
  return len;
}

int get_max(slist *l)
{
  struct node *max = find_max(l);
  return (max->item);
}

//insert befor which position
void insert(slist *l, int index, int data)
{
  struct node *curr=l->head;
  struct node *prev=NULL;
  struct node *new=NULL;

  if(index < 1 || index-1 > get_length(l)) {
    printf("pos not exist\n");
    return;
  }

  new = malloc(sizeof(struct node));
  if(!new){
    printf("no memory\n");
    return;
  }

  if(index == 1) {
    new->item = data;
    new->next = l->head;
    l->head = new;
  } else {
    for (int i=1; i<index; i++) {
      prev=curr;
      curr=curr->next;
    }
    new->item = data;
    new->next = prev->next;
    prev->next = new;
  }
}

/*
int change(slist *head, int index, int data)
{
  struct list *curr = *head;
  if(head == NULL || index < 1 || index > get_length(head)) {
    printf("pos not exist\n");
    return -1;
  }

  if(index==1) {
    curr->item = data;
  } else {
    for (int i=1;i<index;i++){
      curr=curr->next;
    }
    curr->item=data;
  }
  return 0;
}
*/

void delete(slist *l, int index)
{
  struct node *curr=l->head;
  struct node *prev;

  if(l->head == NULL || index < 1 || index > get_length(l)) {
    printf("pos not exist\n");
    return;
  }

  if(index == 1){//first node
    l->head=curr->next;
    free(curr);
  } else {
    for (int i=1; i<index; i++){
      prev=curr;
      curr=curr->next;
    }
    prev->next=curr->next;
    free(curr);
  }

  return;
}
