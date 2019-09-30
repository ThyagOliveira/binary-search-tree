typedef struct tree Tree;

Tree * create();
void destroy_tree(Tree * tree);
void add_node(Tree * tree, char * name);
void remove_node(Tree * tree, char * name);
int count_nodes(Tree * tree);
int count_leaf(Tree * tree);
int height(Tree * tree);
int search(Tree * tree, char * name);
void print_tree(Tree * tree);
