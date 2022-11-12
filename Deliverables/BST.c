#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct nodeType {
    int val;                                                    // val is the value we will be searching for in this binary search tree 
    struct nodeType * left;                                     // Everything to the left of val is smaller to it and we are creating a pointer to traverse it
    struct nodeType * right;                                     // Everything to the right of val is larget than it and we are creating a pointer to traverse i
};
typedef struct nodeType nodeAddress;                             // Basically shortcut for writing struct nodeType all the time as node address

nodeAddress binarysearch(nodeAddress root, int val) {
int n 
printf('Enter the element that you want to find in the list');
for (int i = 0; i<n; i++) {                                        // would take i<logn but it would give an error when the tree is unbalanced and on 1 edge
scanf(%d, &val); 
if (val≠&root && val<root) {                                    // over here checking if val is not equal to root val and val

        root = root→ left                                       // traverse left cause smaller 
}

else {

        root→right                                                      // traverse right cause right side bigger 

    }
  }   
if (root-> left = NULL && root -> right= NULl) {
    printf ('element is not found in the list')
}
}


                                                                // (left→ right or right→ left is NULL traverse back? have some check

int main () {


binarysearch(root,val);

return 0;
}