#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;                                                     // val is the value we will be searching for in this binary search tree 
    struct node * left;                                          // Everything to the left of val is smaller to it and we are creating a pointer to traverse it
    struct node * right;                                         // Everything to the right of val is larget than it and we are creating a pointer to traverse i
};
typedef struct node* nodeAddress;                                // Basically shortcut for writing struct node all the time as node address



nodeAddress createnode(int val) {                                // allocating a new node foran  element in the binary search tree 

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
    inorder (root -> right);                                       // sorts inorder on the right value recursively
    }                                                                                              
}
 

nodeAddress Insertion(int val, nodeAddress root) {              // Function to insert a new element in a given binary search tree
if (root == NULL){                                              // If no new elements present in the tree
    return createnode(val, root);                               // calls create func to create a node address roogt and val
}
if  (val < root-> val) {                                        // if the val we are trying to insert is lower than the root val then insert on the left
    root -> left = insert(val, root-> left);                    // insert val at the node address 
    }
elif (val > root-> val) {                                        // if the val we are trying to insert is great than the root val then insert on the right
    root -> right = insert(val, root-> right);                   // insert val at the node address   
    }   
     return root;                                                // reurn the pointer address after finish
  
}                                                         


int main() {
    int n
    int inputarr[];
    int i;

    for (i =0; i<n; i++){
        printf (" Enter value for array position" , i);
        scanf (%d, &n);
    }
    scanf("%d", )
    return 0;
}