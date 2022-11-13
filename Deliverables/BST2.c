#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;                                                     // val is the value we will be searching for in this binary search tree 
    struct node * left;                                          // Everything to the left of val is smaller to it and we are creating a pointer to traverse it
    struct node * right;                                         // Everything to the right of val is larget than it and we are creating a pointer to traverse i
};
typedef struct node* nodeAddress;                                // Basically shortcut for writing struct node all the time as node address

nodeAddress createnode(int val) {                                // allocating a new node for each element in the binary search tree 

nodeAddress node  = (nodeAddress)malloc(sizeof(nodeAddress));    // allocating memory for node 
 node->val = val;                                                // initializing val of the node
 node-> left = NULL;                                             // intializing pointer of the left pointer to NULL
 node-> right = NULL;                                            // intializing pointer of the right pointer to NULL
 
 return (node);                                                  // return val of node
}
void inorder (nodeAddress root ) {                               // func for sorting it in order recursively
    if (root != NULL ) {                                          // check to make sure that root is not NULL 
    inorder (root -> left);                                      // sorts inorder on the left value recursively
    printf( "%d", root->val);                                    // next prints the val stored in root  
    inorder node -> right;                                       // sorts inorder on the right value recursively
    }                                  
                                                                
                                                                

}


int main() {
    scanf("%d", )
    return 0;
}