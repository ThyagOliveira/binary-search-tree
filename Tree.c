#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

typedef struct node Node;

struct tree {
	Node * root;
};

struct node {
	int info;
    char * name;
	Node * dad;
	Node * left;
	Node * right;
};

Tree * create() {
    Tree * t = malloc(sizeof(Tree));
    t->root = NULL;
    return t;
}

void destroyNode(Node * n) {
    if(n != NULL) {
        destroyNode(n->left);
        destroyNode(n->right);
        free(n);
    }
}

void destroyTree(Tree * t) {
    destroyNode(t->root);
    free(t);
}

Node * add_rec(Node * root, int value, char * name) {
    if(root != NULL) {
        if(root->info > value) {
            root->left = add_rec(root->left, value, name);
        }
        if(root->info < value) {
            root->right = add_rec(root->right, value, name);
        }
    } else {
        root = malloc(sizeof(Node));
        root->info = value;
        root->name = name;
        root->left = NULL;
        root->right = NULL;
    }
}

void add(Tree * tree, int value, char * name) {
    tree->root = add_rec(tree->root, value, name);
}
