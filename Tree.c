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


int count_nodes_rec(Node * node) {
    if(node != NULL) {
        return count_nodes_rec(node->left) + count_nodes_rec(node->right) + 1;
    }
    return 0;
}

int count_nodes(Tree * tree) {
    return count_nodes_rec(tree->root);
}

int count_leaf_rec(Node * node) {
    if(node != NULL) {
        if(node->left == NULL && node->right) {
            return 1;
        }
        return count_leaf_rec(node->left) + count_leaf_rec(node->right);
    }
    return 0;
}

int count_leaf(Tree * tree) {
    return count_leaf_rec(tree->root);
}

int height_rec(Node * node) {
    if(node != NULL) {
        int heightLeft = height_rec(node->left);
        int heightRight = height_rec(node->right);
        return(heightLeft > heightRight ? heightLeft : heightRight) + 1;
    }
    return 0;
}

int height(Tree * tree) {
    return height_rec(tree->root);
}
