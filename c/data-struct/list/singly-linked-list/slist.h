#ifndef _SLIST_H_
#define _SLIST_H_

struct node
{
  int item;
  struct node *next;
};

typedef struct {
  struct node *head;
} slist;

slist *init(void);
void final(slist *l);

int get_length(slist *l);
int get_max(slist *l);

void reverse(slist *l);
void insert(slist *l, int index, int data);
void delete(slist *l, int index);
struct node *search(slist *l, int data);

void selection_sort(slist *l);
void insertion_sort(slist *l);
void bubble_sort(slist *l);

//merge_sort.c
void merge_sort(slist *l);

// hard to write
//链表很难实现希尔排序，堆排序和快速排序
//因为这几种排序需要大量的非连续访问
void shell_sort(slist *l);
void heap_sort(slist *l);
void quick_sort(slist *l);

//utils.c
slist *create(int len);
void print(slist *l);
struct node *find_max(slist *l);
struct node *find_max_prev(slist *l);
#endif
