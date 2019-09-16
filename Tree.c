#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

typedef struct node Node;

struct tree {
	Node * root;
};

struct node {
	char info;
	Node * dad;
	Node * left;
	Node * right;
};