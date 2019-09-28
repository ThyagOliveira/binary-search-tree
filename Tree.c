#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

typedef struct node Node;

struct tree {
	Node * root;
};

struct node {
    char * name;
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

Node * add_rec(Node * node, char * name) {
    if(node != NULL) {
        if(strcmp(name, node->name) < 0)
            node->left = add_rec(node->left, name);                        
        else
            if(strcmp(name, node->name) > 0)
                node->right = add_rec(node->right, name);
    } else {
        node = malloc(sizeof(Node));
        node->name = name;
        node->left = NULL;
        node->right = NULL;
    }
}

void add(Tree * tree, char * name) {
    tree->root = add_rec(tree->root, name);
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
        if(node->left == NULL || node->right == NULL) {
            return count_leaf_rec(node->left) + count_leaf_rec(node->right);
        }
        return 1;
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
    return -1;
}

int height(Tree * tree) {
    return height_rec(tree->root);
}
