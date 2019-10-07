typedef struct tree Tree;

Tree * create();
void destroy_tree(Tree * tree);
void add_node(Tree * tree, char name[]);
void remove_node(Tree * tree, char * name);
void remove_node_biggest(Tree * tree, char * name);
void remove_node_smallest(Tree * tree, char * name);
int count_nodes(Tree * tree);
int count_leaf(Tree * tree);
int height(Tree * tree);
int search(Tree * tree, char * name);
void search_node(Tree * tree, char * name);
void print_tree(Tree * tree);
void print_substring(Tree * tree, char * substring);
void load_file(Tree * tree);
void save_file_in_order(Tree * tree, FILE * file);