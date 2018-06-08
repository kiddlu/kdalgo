#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "rbt.h"

RBTree *init()
{
  RBTree *rbt = malloc(sizeof(RBTree));
  if (!rbt) {
    printf("no mem!\n");
    return NULL;
  }
  rbt->null_node.left = rbt->null_node.right = &(rbt->null_node);
  rbt->null_node.color = BLACK_NODE;
  rbt->null_node.item = 12345;

  rbt->root = NULL;
  return rbt;
}
