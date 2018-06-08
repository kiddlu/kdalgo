#ifndef _DLIST_H_
#define _DLIST_H_
struct node
{
  int item;
  struct node *next;
  struct node *prev;
};

typedef struct {
  struct node *head;
} dlist;

dlist *init(void);
void final(dlist *l);

int get_length(dlist *l);
int get_max(dlist *l);

void reverse(dlist *l);
void insert(dlist *l, int index, int data);
void delete(dlist *l, int index);
void search(dlist *l, int data);

//merge_sort.c
void merge_sort(dlist *l);

//utils.c
dlist *create(int len);
void print(dlist *l);
#endif
