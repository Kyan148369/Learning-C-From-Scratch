#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;                                                    // val is the value we will be searching for in this binary search tree 
    struct node * left;                                     // Everything to the left of val is smaller to it and we are creating a pointer to traverse it
    struct node * right;                                    // Everything to the right of val is larget than it and we are creating a pointer to traverse i
};
typedef struct node* nodeAddress;                            // Basically shortcut for writing struct node all the time as node address

nodeAddress newnode(int val) {

nodeAddress node  = (nodeAddress)malloc(sizeof(nodeAddress));            // allocating memory for node 
 node->val = val;                                          // storing val of the node
 node-> left = NULL;                                        // intializing pointer of the left pointer to NULL
 node-> right = NULL;                                       // intializing pointer of the right pointer to NULL
 
 return (node);
}

int main() {
    return 0;
}