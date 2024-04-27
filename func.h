#ifndef SEARCHING_BINARY_TREE
#define SEARCHING_BINARY_TREE

typedef struct Binary_Search_Tree{
    int key;
    char *name;
    int wealth;
    char *country;
    struct Binary_Search_Tree *left;
    struct Binary_Search_Tree *right;
}Binary_Search_Tree;

typedef struct Queue_Node {
    Binary_Search_Tree *data;
    struct Queue_Node *next;
} Queue_Node;
typedef struct Queue{
    Queue_Node *front;
    Queue_Node *back;
} Queue;
/**
 * Allocate memory for name in struct Binary_Search_Tree
 * @return
 */
char *memory_for_name();
/**
 * Allocate memory for country in struct Binary_Search_Tree
 * @return
 */
char *memory_for_country();
/**
 * Create a new node using struct Binary_Search_Tree
 * @param key
 * @param name
 * @param wealth
 * @param country
 * @return new node
 */
Binary_Search_Tree *create_node(int key, char *name, int wealth, char *country);
/**
 * Insert new node in binary tree
 * @param root
 * @param key
 * @param name
 * @param wealth
 * @param country
 * @return new element
 */
Binary_Search_Tree *insert(Binary_Search_Tree *root, int key, char *name, int wealth, char *country);
/**
 * Read data of binary tree from input stream
 * @return
 */
Binary_Search_Tree * read_tree();
/**
 * Called in function print_tree() to print entire binary tree
 * @param root
 */
void _print_tree(Binary_Search_Tree * root);
/**
 * Print entire binary tree with all elements
 * @param root
 */
void print_tree(Binary_Search_Tree *root);
/**
 * Search a node in binary tree
 * @param root
 * @param target- searched key in binary tree
 * return all information about the node
 */
int search_key_recursive(Binary_Search_Tree *root,int target);
/**
 * Inorder traversal of binary tree
 * @param root
 */
void inorder_traversal(Binary_Search_Tree *root);
/**
 * Preoorder traversal of binary tree
 * @param root
 */
void preorder_traversal(Binary_Search_Tree *root);
/**
 * Postorder traversal of binary tree
 * @param root
 */
void postorder_traversal(Binary_Search_Tree *root);
/**
 * Create new node and put it in queue
 * @param data
 * @return queue_node
 */
Queue_Node *create_queue_node(Binary_Search_Tree *data);
/**
 * Create empty queue
 * @param queue
 * @param data
 * return pointer to queue
 */
Queue *create_queue();
/**
 * Put node in queue
 * @param queue
 * @param data
 */
void put_in_queue(Queue *queue, Binary_Search_Tree *data);
/**
 * Get node from queue
 * @param queue
 * @return data from queue
 */
Binary_Search_Tree *get_from_queue(Queue *queue);
/**
 * Breadth-first search for all nodes in Binary_Search_Tree
 * @param root
 */
void BFS(Binary_Search_Tree *root);
/**
 * Depth-first search for all nodes in Binary_Search_Tree
 * @param node
 */
void DFS(Binary_Search_Tree *node);
/**
 * Switch between options
 */
void switch_options();
/**
 * Calculate maximum number between two numbers
 * @param a
 * @param b
 * @return maximum number between two numbers
 */
int max(int a, int b);
/**
 * Calculate height of binary tree
 * @param node
 * @return height of binary tree
 */
int height(Binary_Search_Tree* node);
/**
 * Check if binary tree is balanced
 * @param root
 * @return 1 if binary tree is balanced, 0 if not
 */
int is_balanced(Binary_Search_Tree* root);
/**
 * Rotate binary tree right
 * @param y
 * @return rotated binary tree
 */
Binary_Search_Tree* rotate_right(Binary_Search_Tree* parent);
/**
 * Rotate binary tree left
 * @param x
 * @return rotated binary tree
 */
Binary_Search_Tree *rotate_left(Binary_Search_Tree* parent);
/**
 * Balance binary tree
 * @param root
 * @return balanced binary tree
 */
Binary_Search_Tree* balance_AVL(Binary_Search_Tree* root);
/**
 * Calculate balance factor of binary tree
 * @param node
 * @return balance factor of binary tree
 */
void print_spaces(int n);
/**
 * Print balanced binary tree
 * @param root
 * @param level
 */
void print_balanced_tree(Binary_Search_Tree *root, int level);
/**
 * Mirror binary tree
 * @param root
 */
void mirror_tree(Binary_Search_Tree *root);


#endif SEARCHING_BINARY_TREE
