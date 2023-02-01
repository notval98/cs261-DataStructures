#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char* argv[]) {
    int i;

    // save command line arguments (keys) in an array
    int* A = malloc(argc * sizeof(int));
    for (i=1; i<argc; i++) {
        A[i] = atoi(argv[i]);
    }

    // create BST
    struct BST* b = createBST();

    // insert keys
    for (i=1; i<argc; i++) {
        insert(b, A[i]);
    }

    // do inorder traversal of BST
    inorderTraversal(b);

    // print BST height
    printf("BST height: %d\n\n", height(b));

    // print the depth of all BST nodes
    for (i=1; i<argc; i++) {
        printf("Depth of %4d: %4d\n", A[i], depth(b, A[i]));
    }

    // cleanup BST nodes and BST
    deleteBST(b);

    free(A);
    return 0;
}