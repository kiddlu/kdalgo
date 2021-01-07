#include "list.h"
#include <stdio.h>

static list_declare(tq);

struct fdevent
{
	int fd;
	struct listnode queue;
};

void init(void)
{
	struct fdevent *fde;
	
	for(int i=0; i<500; i++) {
		fde = malloc(sizeof(struct fdevent));
		fde->fd = i;
		list_enqueue(&tq, &(fde->queue));
	}
}

void print()
{
	struct fdevent *fde;
	struct listnode *ln;

	list_for_each(ln, &tq) {
		fde = node_to_item(ln, struct fdevent, queue);
		printf("fd is %d\n", fde->fd);
	}
}

void fini(void)
{
	struct fdevent  *fde;
	struct listnode *ln;
	
	for(; (0 != (ln = list_dequeue(&tq))); ) {
		fde = node_to_item(ln, struct fdevent, queue);
		printf("fd is %d\n", fde->fd);
		free(fde);
	}
}

int main()
{
	init();
	//print();
	fini();
}