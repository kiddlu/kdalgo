#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

/*
bubble sort
selection sort
insertion sort
*/

void bubble_sort(slist *l)
{

  if (l->head == NULL || l->head->next == NULL) {
    return;
  }

  struct node *prev, *curr, *post;

  int len = get_length(l);

  for (int i=0; i < len; i++) {
    prev = NULL;
    curr = l->head;
    post = curr->next;

    for(; post != NULL;) {
      if(curr->item > post->item) {
        if(curr == l->head)
          l->head = post;
        else
          prev->next = post;

        curr->next = post->next;
        post->next = curr;
        prev = post;
        post = curr->next;
      } else {
        prev = curr;
        curr = post;
        post = post ->next;
      }
    }
  }
  return;
}

void selection_sort(slist *l)
{
  if (l->head == NULL || l->head->next == NULL) {
    return;
  }

  struct node *max, *max_prev, *sorted = NULL;

  for(;l->head != NULL;) {
    max_prev = find_max_prev(l);
    if(max_prev == NULL) {
      max = l->head; //max is head node
      l->head = max->next;
    } else {
      max = max_prev->next;
      max_prev->next = max->next;
    }
    max->next = sorted;
    sorted = max;
  }

  l->head = sorted;
}

void insertion_sort(slist *l)
{
  if (l->head == NULL || l->head->next == NULL) {
    return;
  }

  struct node *first = NULL;
  struct node *curr = NULL;
  struct node *prev = NULL;
  struct node *post = NULL;

  first = l->head->next;
  l->head->next = NULL;
  for(;first != NULL;) {
    curr = first;
    post = l->head;
    while(post != NULL && post->item < curr->item){
      prev = post;
      post = post->next;
    }
    first = first->next;
    if(post == l->head){
      l->head = curr;
    } else {
      prev->next = curr;
    }
    curr->next = post;
  }

  return;
}
