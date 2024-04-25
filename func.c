#include <stdio.h>
#include <stdlib.h>
#include "func.h"


 binary_tree_node* create_node(int value){

    binary_tree_node *newNode=malloc(sizeof(binary_tree_node));
    if(newNode==NULL){
        printf("Memoria nu s-a alocat!");
        exit(1);
    }
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

 binary_tree_node * insert(binary_tree_node * root, int data) {
    if (root == NULL)
        return create_node(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

binary_tree_node * read_tree() {
    binary_tree_node * root = NULL;
    int data;
    printf("Introduceti elemente in arbore (introducerea se termina cu -1): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1)
            break;
        root = insert(root, data);
    }
    return root;
}
/*
 *
 */
void _print_tree(binary_tree_node * root, int space) {
    if (root == NULL)
        return;
    int count=5;

    space += count;

    _print_tree(root->right, space);

    printf("\n");
    for (int i = count; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    _print_tree(root->left, space);
}

void print_tree(binary_tree_node *root) {
    _print_tree(root,0);
}


int depth(binary_tree_node * root) {
    if (root == NULL)
        return 0;
    else {
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        if (leftDepth > rightDepth)
            return (leftDepth + 1);
        else
            return (rightDepth + 1);
    }
}

int search_key_recursive(binary_tree_node *root,int target){
    if(root==NULL){
        printf("Arborele este vid!");
    }
    if(root->data==target){
        printf("Valorea este prezenta in arbore\n");
        return 1;
    }
    else if(root->data>target){
        return search_key_recursive(root->left,target);
    }else{
        return search_key_recursive(root->right,target);
    }
}

int node_depth(binary_tree_node *root,int key,int current_depth){
    if(root==NULL){
        return -1;
    }
    if(root->data==key){
        return current_depth;
    }
    int left_depth= node_depth(root->left,key,current_depth+1);
    int right_depth= node_depth(root->right,key,current_depth+1);

    if(left_depth==-1 && right_depth==-1){
        return -1;
    }
    return (left_depth!=-1)?left_depth : right_depth;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

 int _find_node_height(binary_tree_node *root,int value,int *height){

    if(root==NULL){
        return -1;
    }
    int leftHeight= _find_node_height(root->left,value,height);
    int rightHeight= _find_node_height(root->right,value,height);
    int result=max(leftHeight,rightHeight)+1;

    if(root->data==value){
        *height=result;
    }
     return result;
}

int find_node_height(binary_tree_node *root,int value){
    int height=-1;
    _find_node_height(root,value,&height);
    return height;
}

void print_leaves(binary_tree_node *root){
    if(root==NULL){
        return;
    }

    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
    }
    if (root->left != NULL)
        print_leaves(root->left);

    if (root->right != NULL)
        print_leaves(root->right);
}

void _free_tree(binary_tree_node *root) {
    if (root == NULL) {
        return;
    }
    _free_tree(root->left);
    _free_tree(root->right);

    free(root);
}

void free_tree(binary_tree_node *root) {
    _free_tree(root);
}

void switch_options(){
    binary_tree_node *root=NULL;

    int choice;
    do {
        printf("\n\n1.Citirea de la tastatura a elementelor arborelui\n");
        printf("2.Afisarea arborelui\n");
        printf("3.Calcularea adancimii arborelui \n");
        printf("4.Cautarea unui nod in baza unei chei de cautare \n");
        printf("5.Calcularea adancimii unui nod \n");
        printf("6.Calcularea inaltimii unui nod \n");
        printf("7.Afisarea tuturor frunzelor \n");
        printf("8.Curatirea elementelor arborelui \n");
    printf("Introduceti optiunea:");
    scanf_s("%d", &choice);

    switch (choice) {


        case 1: {
            printf("Introduceti elementele arborelui binar:\n");
            root=read_tree();
            break;
        }
        case 2:{
                printf("Afisarea arborelui:\n ");
                print_tree(root);
                printf("\n");

            break;
        }

        case 3:{
            int max_depth= depth(root);
            printf("\n\nAdancimea arborelui introdus este :%d\n",max_depth);
            break;
        }
        case 4:{
            int target;
            printf("\n\nScrie valoarea de cautat:");
            scanf("%d",&target);
            int result= search_key_recursive(root,target);
            if (result == 1)
            {
                printf ("Target=%d a fost gasit in arborele binar\n", target);
            }
            else
            {
                printf ("Target=%d nu a fost gasit in arborele binar\n", target);
            }
            break;
        }
        case 5:{
            int key;
            printf("\n\nScrie valorea nodului pentru care vrei sa afli adancimea:");
            scanf("%d",&key);
            int nodeDepth=node_depth(root,key,0);

            if(nodeDepth!=-1){
                printf("Adancimea nodului %d este %d",key,nodeDepth);
            }
            else{
                printf("Nodul nu a fost gasit in arbore!");
            }
            break;
        }

        case 6:{
            int key;
            printf("\n\nScrie valorea nodului pentru care vrei sa afli inaltimea:");
            scanf_s("%d",&key);

            int node_height= find_node_height(root,key);

            printf("Inaltimea nodului este %d",node_height);
            break;
        }
        case 7:{
            printf("\n\nFrunzele arborelui binar sunt: ");
            print_leaves(root);
            break;
        }

        case 8:{
            free_tree(root);

            break;
        }
        default:{
            printf("Invalid choice!!!");
        }
    }
}while(choice!=0);
}

