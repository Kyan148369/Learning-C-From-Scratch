#include <stdio.h>
#include <stdlib.h>

// balanced BSTtree essentially
// heigt is logn  for AVL Trees
// height factor = (height of left subtree - height of right subtree)  = -1,0,1    (longest distance on the left/right sub tree ) for each node
// we go for rotations to balance
// if its +ve the height its imbalanced on the left if its negative its on the right

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};
typedef struct Node *NodeAddress;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

NodeAddress createnode(int val)
{ // allocating a new node for an  element in the AVL tree

    NodeAddress temp = (NodeAddress)malloc(sizeof(NodeAddress)); // allocating memory for node
    temp->val = val;                                             // initializing val of the node
    temp->left = NULL;                                           // intializing pointer of the left pointer to NULL
    temp->right = NULL;                                          // intializing pointer of the right pointer to NULL
    temp->height = 1;                                            // defining height variable for a node
    return temp;                                                 // return temp of type NodeAddress
}
int height(NodeAddress N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Get Balance factor of node N
int getBalance(NodeAddress N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

NodeAddress rightrotate(NodeAddress r)
{
    NodeAddress l = r->left;
    NodeAddress T2 = l->right;

    l->right = r; // Performing necessary rotation
    r->left = T2;

    r->height = max(height(r->left), // Update r heights
                    height(r->right)) +
                1;
    l->height = max(height(l->left), // Update l height
                    height(l->right)) +
                1;

    return l; // Return new root
}

NodeAddress leftrotate(NodeAddress l)
{

    NodeAddress r = l->right;
    NodeAddress T2 = r->left;

    r->left = l; // Performing necessary rotation
    l->right = T2;

    l->height = max(height(l->left),
                    height(l->right)) +
                1;
    r->height = max(height(r->left),
                    height(r->right)) +
                1;

    return r; // Return new root
}

NodeAddress Insertion(NodeAddress root, int val) // Function to insert a new element in a given binary search tree
{
    if (root == NULL)           // If no new elements present in the tree
        return createnode(val); // calls create func to create a node with val

    if (val < root->val)                         // if the val we are trying to insert is lower than the root val then insert on the left
        root->left = Insertion(root->left, val); // insert val at the node address

    else if (val > root->val)                      // if the val we are trying to insert is great than the root val then insert on the right
        root->right = Insertion(root->right, val); // insert val at the node address
    else
        return root; // return the pointer address after finish

    if (height(root->left) > height(root->right)) // calculating height of node is 1+ leaf node height
    {
        root->height = (1 + height(root->left));
    }
    else
    {
        root->height = (1 + height(root->right));
    }

    int balance = getBalance(root);           // For unbalanced nodes we have 4 cases
    if (balance > 1 && val < root->left->val) // Left Left Imbalanced case
        return rightrotate(root);

    if (balance < -1 && val > root->right->val) // Right Right Imbalanced Case
        return leftrotate(root);

    if (balance > 1 && val > root->left->val) // Left Right Imbalanced Case
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance < -1 && val < root->right->val) // Right Left Imbalanced Case
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root; // return root pointer
}

NodeAddress FindMinElement(NodeAddress root)
{                               // Function to find the min element of a node
    NodeAddress present = root; // basically creating a pointer of the current location we are in the bst
    while (present && present->left != NULL)
    {                            // making sure that the pointer itself is not null and the the next element isnt null either
        present = present->left; // present pointer is equal to the pointer of the node to the left of present
    }
    return present; // return the node position of present as this would be the last element of the tree
}

void preOrder(NodeAddress root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    int n;                                                // initialize n data type
    printf("Enter number of elements desired in array:"); // self explanatory
    scanf("%d", &n);                                      // takes n number of elements in array as input
    int arr[n];                                           // initializing array
    for (int i = 0; i < n; i++)
    { // takes user input for array from 1 till n
        printf("Enter value for array position %d: ", i);
        scanf("%d", &arr[i]);
    }
    NodeAddress root = NULL; // initializing root address to null to empty garbage values
    for (int i = 0; i < n; i++)
    {
        root = Insertion(root, arr[i]);
    }

    printf("Preorder traversal of the constructed AVL"
           " tree is \n");
    preOrder(root);

    return 0;
}
