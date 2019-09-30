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
    Tree * tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

void destroy_tree_rec(Node * node) {
    if(node != NULL) {
        destroy_tree_rec(node->left);
        destroy_tree_rec(node->right);
        free(node);
    }
}

void destroy_tree(Tree * tree) {
    destroy_tree_rec(tree->root);
    free(tree);
}

Node * add_node_rec(Node * node, char * name) {
    if(node != NULL) {
        if(strcmp(name, node->name) < 0)
            node->left = add_node_rec(node->left, name);                        
        else
            if(strcmp(name, node->name) > 0)
                node->right = add_node_rec(node->right, name);
    } else {
        node = malloc(sizeof(Node));
        node->name = name;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void add_node(Tree * tree, char * name) {
    tree->root = add_node_rec(tree->root, name);
}

Node * remove_node_rec(Node * node, char * name) {
    if(node != NULL) {
        if(strcmp(name, node->name) < 0)
            node->left = remove_node_rec(node->left, name);
        else 
            if(strcmp(name, node->name) > 0)
                node->right = remove_node_rec(node->right, name);
            else {
                Node * help = node;
                if(node->left == NULL && node->right == NULL) {
                    node = NULL;
                    free(help);
                } else {
                    if(node->left == NULL || node->right == NULL) {
                        node = node->left != NULL ? node->left : node->right;
                        free(help);
                    } else {
                        // Nó com 2 filhos
                    }
                }                
            }
    }
    return node;
}

void remove_node(Tree * tree, char * name) {
    remove_node_rec(tree->root, name);
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

int search_rec(Node * node, char * name) {
    if(node != NULL) {
        if(strcmp(name, node->name) < 0)
            return search_rec(node->left, name);
        else
            if(strcmp(name, node->name) > 0)
                return search_rec(node->right, name);
        return 1;
    }
    return 0;
}

int search(Tree * tree, char * name) {
    return search_rec(tree->root, name);
}

void pre_order(Node * node) {
    if(node != NULL) {
        printf("%s ", node->name);
        pre_order(node->left);
        pre_order(node->right);
    }
}

void in_order(Node * node) {
    if(node != NULL) {
        in_order(node->left);
        printf("%s ", node->name);
        in_order(node->right);
    }
}

void post_order(Node * node) {
    if(node != NULL) {
        post_order(node->left);
        post_order(node->right);
        printf("%s ", node->name);
    }
}

void print_tree(Tree * tree) {
    if(tree->root == NULL)
        printf("\t Primeiro carregue a árvore");
    else {
        in_order(tree->root);
        printf("\n");
    }               
}