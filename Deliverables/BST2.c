#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int val;                                                    // val is the value we will be searching for in this binary search tree 
    struct node *left;                                          // Everything to the left of val is smaller to it and we are creating a pointer to traverse it
    struct node *right;                                         // Everything to the right of val is larget than it and we are creating a pointer to traverse i
};
typedef struct node* nodeAddress;                                // Basically shortcut for writing struct node all the time as node address



nodeAddress createnode(int val) {                                // allocating a new node foran  element in the binary search tree 

nodeAddress temp  = (nodeAddress)malloc(sizeof(nodeAddress));    // allocating memory for node 
 temp->val = val;                                                // initializing val of the node
 temp-> left = NULL;                                             // intializing pointer of the left pointer to NULL
 temp-> right = NULL;                                            // intializing pointer of the right pointer to NULL
 
 return temp;                                                    // return val of node
}
void inorder (nodeAddress root ) {                               // func for sorting it in order recursively
    if (root != NULL ) {                                         // check to make sure that root is not NULL 
    inorder (root -> left);                                      // sorts inorder on the left value recursively
    printf( "%d \n" , root->val);                                // next prints the val stored in root  
    inorder (root -> right);                                     // sorts inorder on the right value recursively
    }                                                                                              
}
 

nodeAddress Insertion(nodeAddress root, int val)                // Function to insert a new element in a given binary search tree
{             
    if (root == NULL)                                           // If no new elements present in the tree
         return createnode(val);                                // calls create func to create a node with val

    if  (val < root-> val)                                      // if the val we are trying to insert is lower than the root val then insert on the left
        root -> left = Insertion(root-> left, val);             // insert val at the node address 
    
    else if (val > root-> val)                                   // if the val we are trying to insert is great than the root val then insert on the right
        root -> right = Insertion(root-> right, val);            // insert val at the node address   
       
     return root;                                                // return the pointer address after finish
  
}         

nodeAddress FindMinElement(nodeAddress root){                     // Function to find the min element of a node
nodeAddress present = root;                                       // basically creating a pointer of the current location we are in the bst              
while (present && present->left != NULL) {                        // making sure that the pointer itself is not null and the the next element isnt null either
    present = present -> left;                                    // present pointer is equal to the pointer of the node to the left of present
    
}
    printf("present is %d", present);
    return present;                                               // return the node position of present as this would be the last element of the tree
}

nodeAddress NodeDeletion(nodeAddress root, int val){            

}

int main() {
    int n;                                                      // initialize n data type
    printf("Enter number of elements desired in array:");       // self explanatory
    scanf ("%d", &n);                                           // takes n number of elements in array as input
    int arr[n];                                                 // initializing array
    for (int i =0; i<n; i++){                                   //takes user input for array from 1 till n
        printf ("Enter value for array position %d: " , i);
        scanf ("%d", &arr[i]);
    }
    nodeAddress root = NULL;                                    // initializing root address to null to empty garbage values
    for (int i =0; i<n; i++){                          
     root = Insertion(root, arr[i]);       
     }                                                          // inserting elements in the array 
	
    inorder(root);                                              // prints out the values in order of the binary search tree 
    FindMinElement(root);
    return 0;

}