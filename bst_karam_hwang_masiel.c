/*
Binary Search Tree Program
Joseph Karam, karamj@oregonstate.edu, 933968313
Ethan Masiel, masiele@oregonstate.edu, 933289111
Michael Hwang, hwangmic@oregonstate.edu, 932724947
*/

//libraries included
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//files included
#include "bst.h"

//function prototypes for functions not inclouded in bst.h

struct Node* createNode(int);
void recursiveTraversal(struct Node*);
int recursiveHeight(struct Node*);
int recursiveDepth(struct Node*, int);
void recursivedeleteBST(struct Node*);

//dynamically allocates memory for BST
struct BST* createBST() {

    struct BST* tree = (struct BST*)malloc(sizeof(struct BST));
    tree->root = NULL;

    return tree;

}

//dynamically allocates memory for Node
struct Node* createNode(int data) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}

//base case for traversal and calls recursive traversal function
void inorderTraversal(struct BST* tree) {

    puts("In-order Traversal");
    if(tree->root == NULL) { //if tree is emptpy return
        return;
    }
    else {
        recursiveTraversal(tree->root);
    }
    printf("\n\n");

}

void recursiveTraversal(struct Node* temp) {

    if(temp->left != NULL) { //if left child exists, pass into recursive traversal function
        recursiveTraversal(temp->left);
    }
    printf("%d ", temp->key); //print current node key
    if(temp->right != NULL) { //if right child exists, pass into recursive traversal function
        recursiveTraversal(temp->right);
    }

}

//inserts new node with key into tree
void insert(struct BST* tree, int node_key) {

    struct Node* temp = createNode(node_key); //creates new node

    //if tree is empty, sets new node as root node
    if (tree->root == NULL) {
        tree->root = temp;
        return;
    }
    else { //cycles through tree to find appropriate position for new node, following BST rules
        struct Node* current = tree->root;
        struct Node* parent = NULL;
        while(true) {
            parent = current;
            if (node_key < current->key) {
                current = current->left;
                if(current == NULL) {
                    parent->left = temp;
                    return;
                }
            }
            else{
                current = current->right;
                if(current == NULL) {
                    parent->right = temp;
                    return;
                }
            }
        }
    }

}

//base case for height and calls recursive height function
int height(struct BST* tree) {

    int height = 0;
    if (tree->root == NULL) { //if tree is empty, returns height is -1
        return -1;
    }
    else {
        height = recursiveHeight(tree->root);
    }

    return height - 1;

}

int recursiveHeight(struct Node* temp) {

    if (temp == NULL) {
        return 0;
    }
    else {
        //cycles through all possible paths recursively to find the greatest height
        int left_height = recursiveHeight(temp->left);
        int right_height = recursiveHeight(temp->right);
        //choose greater height to return to height function
        if (left_height > right_height) return (left_height + 1);
        else return (right_height + 1);
    }

}

//calls recursive depth function
int depth(struct BST* tree, int node_key) {

    recursiveDepth(tree->root, node_key);

}

int recursiveDepth(struct Node* temp, int x) {

    if (temp == NULL) { //if node doesn't exist, return -1
        return -1;
    }
    int depth = -1;
    //next three lines are one statement, split up for readability
    if ((temp->key == x) //if current node's key equals key of node being searched for
        || (depth = recursiveDepth(temp->left, x)) >= 0 //OR cycle through left children recursively
        || (depth = recursiveDepth(temp->right, x)) >= 0) //OR cycle through right children recursively
        return depth + 1;

    return depth;

}

//calls recursive delete BST function and frees BST
void deleteBST(struct BST* tree) {
    
    printf("\n");
    recursivedeleteBST(tree->root);
    puts("Free the  BST\n");
    free(tree);

}

void recursivedeleteBST(struct Node* temp) {

    if(temp) { //if node exists
        recursivedeleteBST(temp->left); //recursively cycle through left children
        recursivedeleteBST(temp->right); //recursively cycle through right chilrden
        printf("Free: %4d\n", temp->key); //print key of node being deleted
        free(temp); //free current node
    }

}