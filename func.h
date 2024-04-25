#ifndef BINARY_TREE
#define BINARY_TREE

typedef struct binary_tree_node {

    int data;
    struct binary_tree_node *left;
    struct binary_tree_node *right;

} binary_tree_node;


/**
 *
 * @param value
 * @return
 */
binary_tree_node *create_node(int value);

/**
 * Insert new node in tree
 * @param BinaryTreeNode *root-pointer to first element
 * @param int data-value of new node
 * @return pointer to new element
 */
binary_tree_node *insert(binary_tree_node *root, int data);

/**
 * Read binary tree from stdin file
 * @return-pointer to first element
 */
binary_tree_node *readTree();

/**
 * Used in function print_tree to print values of tree
 * @param root
 * @param space -space between values of nodes
 */
void _print_tree(binary_tree_node *root, int space);

/**
 * Display elements of binary tree
 * @param root
 */
void print_tree(binary_tree_node *root);

/**
 * Calculate depth of tree
 * @param root
 * @return
 */
int depth(binary_tree_node *root);

/**
 * Search node in tree by it's value recursive
 * @param root
 * @param target
 * @return
 */
int search_key_recursive(binary_tree_node *root, int target);

/**
 * Calculate depth of node
 * @param root
 * @param key -searched value
 * @param current_depth
 * @return
 */
int node_depth(binary_tree_node *root, int key, int current_depth);

/**
 * Calculate max between two int numbers
 * @param a
 * @param b
 * @return
 */
int max(int a, int b);

/**
 * Find node height in tree
 * @param root
 * @param value
 * @param height
 * @return -max value
 */
int _find_node_height(binary_tree_node *root, int value, int *height);

/**
 * Call find_node_height and determine height of node
 * @param root
 * @param value
 * @return
 */
int find_node_height(binary_tree_node *root, int value);

/**
 * Print elements that doesn't have childrens
 * @param root
 */
void print_leaves(binary_tree_node *root);

/**
 * Free memory for allocated binary tree
 * @param root
 * @return
 */
void _free_tree(binary_tree_node *root);

/**
 * Call _free_tree to delete all elements
 * @param root
 */
void free_tree(binary_tree_node *root);

/**
 * Diplay all options that may be used for a binary tree
 */
void switch_options();

#endif
