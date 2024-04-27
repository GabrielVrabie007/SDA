#include <stdio.h>
#include "func.h"
#include <stdlib.h>
#include <string.h>

char *memory_for_name(){
    char*name;
    char static_name[50];
    printf("Enter name: ");
    scanf("%s",static_name);
    name=strdup(static_name);
    return name;
}

char *memory_for_country(){
    char *country;
    char static_country[50];
    printf("Enter country: ");
    scanf("%s",static_country);
    country=strdup(static_country);
    return country;
}

Binary_Search_Tree *create_node(int key,char *name,int wealth,char *country){
    Binary_Search_Tree *node = (Binary_Search_Tree *)malloc(sizeof(Binary_Search_Tree));
    if (node == NULL){
        printf("Memory allocation error\n");
        exit(1);
    }
    node->key = key;
    node->name=strdup(name);
    node->country=strdup(country);
    node->wealth = wealth;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Binary_Search_Tree * insert(Binary_Search_Tree * root, int key, char *name, int wealth, char *country) {
    if (root == NULL)
        return create_node(key, name, wealth, country);

    if (key < root->key)
        root->left = insert(root->left, key, name, wealth, country);
    else if (key > root->key)
        root->right = insert(root->right, key, name, wealth, country);

    return root;
}
Binary_Search_Tree * read_tree() {
    Binary_Search_Tree * root = NULL;
    int key;

    while (1) {
        printf("\nEnter key (to STOP, enter -1): ");
        scanf_s("%d", &key);

        if (key == -1) {
            break;
        }
        char *name = memory_for_name();
        char *country = memory_for_country();
        int wealth;

        printf("Enter wealth: ");
        scanf_s("%d", &wealth);

        root = insert(root, key, name, wealth, country);
    }

    return root;
}


void _print_tree(Binary_Search_Tree * root) {
    if (root == NULL)
        return;
    _print_tree(root->left);
    printf("Key: %d\nName: %s\nWealth: %d\nCountry: %s\n", root->key, root->name, root->wealth, root->country);
    _print_tree(root->right);

}

void print_tree(Binary_Search_Tree *root) {
    _print_tree(root);
}

int search_key_recursive(Binary_Search_Tree *root,int target){
    if(root==NULL){
        printf("Arborele este vid!");
    }
    if(root->key==target){
        printf("Valorea este prezenta in arbore\n");
        printf("Key: %d\n Name: %s\n Wealth: %d\n Country: %s\n", root->key, root->name, root->wealth, root->country);
        return 1;
    }
    else if(root->key>target){
        return search_key_recursive(root->left,target);
    }else{
        return search_key_recursive(root->right,target);
    }
}

void inorder_traversal(Binary_Search_Tree *root) {
    if (root == NULL)
        return;

    inorder_traversal(root->left);
    printf("Key: %d\n", root->key);
    inorder_traversal(root->right);
}

void preorder_traversal(Binary_Search_Tree *root) {
    if (root == NULL)
        return;

    printf("Key: %d\n", root->key);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


void postorder_traversal(Binary_Search_Tree *root) {
    if (root == NULL)
        return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("Key: %d\n", root->key);
}

Queue_Node *create_queue_node(Binary_Search_Tree *data) {
    Queue_Node *newNode = (Queue_Node *)malloc(sizeof(Queue_Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->back = NULL;
    return queue;
}

int is_empty(Queue *queue) {
    return (queue->front == NULL);
}

void put_in_queue(Queue *queue, Binary_Search_Tree *data) {
    Queue_Node *newNode = create_queue_node(data);
    if (is_empty(queue)) {
        queue->front = queue->back = newNode;
    } else {
        queue->back->next = newNode;
        queue->back = newNode;
    }
}

// Function to dequeue a node from the queue
Binary_Search_Tree *get_from_queue(Queue *queue) {
    if (is_empty(queue)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Queue_Node *temp = queue->front;
    Binary_Search_Tree *data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void BFS(Binary_Search_Tree *root) {
    if (root == NULL)
        return;

    Queue *queue = create_queue();
    put_in_queue(queue, root);

    while (!is_empty(queue)) {
        Binary_Search_Tree *current = get_from_queue(queue);
        printf("Key: %d, Name: %s, Wealth: %d, Country: %s\n", current->key, current->name, current->wealth,
               current->country);
        if (current->left != NULL)
            put_in_queue(queue, current->left);
        if (current->right != NULL)
            put_in_queue(queue, current->right);
    }
}

void DFS(Binary_Search_Tree *node){
    preorder_traversal(node);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Binary_Search_Tree* node) {
    if (node == NULL)
        return 0;
    return 1 + max(height(node->left), height(node->right));
}

int is_balanced(Binary_Search_Tree* root) {
    if (root == NULL)
        return 1;
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) <= 1 && is_balanced(root->left) && is_balanced(root->right))
        return 1;
    return 0;
}


Binary_Search_Tree* rotate_right(Binary_Search_Tree* parent) {
    Binary_Search_Tree* pivot = parent->left;
    Binary_Search_Tree* right_subtree = pivot->right;

    pivot->right = parent;
    parent->left = right_subtree;

    return pivot;
}

Binary_Search_Tree* rotate_left(Binary_Search_Tree* parent) {
    Binary_Search_Tree* pivot = parent->right;
    Binary_Search_Tree* left_subtree = pivot->left;

    pivot->left = parent;
    parent->right = left_subtree;

    return pivot;
}


Binary_Search_Tree* balance_AVL(Binary_Search_Tree* root) {
    if (root == NULL)
        return root;

    int balance = height(root->left) - height(root->right);

    if (balance > 1) {
        if (height(root->left->left) >= height(root->left->right))
            return rotate_right(root);
        else {
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }
    }
    if (balance < -1) {
        if (height(root->right->right) >= height(root->right->left))
            return rotate_left(root);
        else {
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }
    }
    return root;
}


void print_spaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

// Function to print binary tree
void print_balanced_tree(Binary_Search_Tree *root, int level) {
    if (root == NULL) {
        return;
    }
    int space = 4;
    print_balanced_tree(root->right, level + 1);

    print_spaces(space * level);

    printf("%d\n", root->key);

    print_balanced_tree(root->left, level + 1);
}

void mirror_tree(Binary_Search_Tree *root){
    if(root==NULL) {
        return;
    }
    Binary_Search_Tree *temp=root;

    mirror_tree(root->left);
    mirror_tree(root->right);

    temp=root->left;
    root->left=root->right;
    root->right=temp;


}
void switch_options(){
    Binary_Search_Tree *root=NULL;

    int choice;
    do {
        printf("\n\n1.Read data from input\n");
        printf("2.Display binary tree\n");
        printf("3.Find node using key \n");
        printf("4.Inorder traversal\n");
        printf("5.Preorder traversal\n");
        printf("6.Postorder traversal\n");
        printf("7.BFS\n");
        printf("8.DFS\n");
        printf("9.Print balanced tree:\n");
        printf("10.Mirror tree\n");
        printf("Introduce your option:");
        scanf_s("%d", &choice);

        switch (choice) {


            case 1: {
                printf("Introduce values of tree:\n");
                root=read_tree();
                break;
            }
            case 2: {
                print_tree(root);
                break;
            }
            case 3:{
                int target;
                printf("Introduce key of searched element: ");
                scanf_s("%d", &target);
                search_key_recursive(root,target);
                break;
            }
            case 4:{
                printf("Inorder traversal:\n");
                inorder_traversal(root);
                break;
            }
            case 5:{
                printf("Preorder traversal:\n");
                preorder_traversal(root);
                break;
            }
            case 6:{
                printf("Postorder traversal:\n");
                postorder_traversal(root);
                break;
            }
            case 7:{
                printf("BFS traversal:\n");
                BFS(root);
                break;
            }
            case 8:{
                printf("DFS traversal:\n");
                DFS(root);
                break;
            }
            case 9:{
                root= balance_AVL(root);
                print_balanced_tree(root,0);
                break;
            }

            case 10: {
                mirror_tree(root);
                print_balanced_tree(root,0);
                break;
            }
            default: {
                printf("Invalid option!\n");
                break;
            }



        }
    }while(choice!=0);
}