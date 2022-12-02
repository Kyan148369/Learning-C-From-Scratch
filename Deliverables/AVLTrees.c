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
int height(NodeAddress Node)
{
    if (Node == NULL)
        return 0;
    return Node->height;
}
void inorder(NodeAddress root)
{ // func for sorting it in order recursively
    if (root != NULL)
    {                               // check to make sure that root is not NULL
        printf("%d \n", root->val); // next prints the val stored in root
        inorder(root->left);        // sorts inorder on the left value recursively
        inorder(root->right);       // sorts inorder on the right value recursively
    }
}

NodeAddress Insertion(NodeAddress root, int val) // Function to insert a new element in a given binary search tree
{
    if (root == NULL)           // If no new elements present in the tree
        return createnode(val); // calls create func to create a node with val

    if (val < root->val)                         // if the val we are trying to insert is lower than the root val then insert on the left
        root->left = Insertion(root->left, val); // insert val at the node address

    else if (val > root->val)                      // if the val we are trying to insert is great than the root val then insert on the right
        root->right = Insertion(root->right, val); // insert val at the node address

    return root; // return the pointer address after finish

    if (height(root->left) > height(root->right)) // calculating height of node is 1+ leaf node height
    {
        height = (1 + height(root->left));
    }
    else
    {
        height = (1 + height(root->right));
    }
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
// 3 cases 1) 1 of 2 child nodes  2) 1 child node 3) parent node with 2 childs

// Get Balance factor of node N
int getBalance(NodeAddressN)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
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
NodeAddress NodeDeletion(NodeAddress root, int val)
{                                                     // function for node deletion
    if (root == NULL)                                 // in case if base node (root) is null
        return root;                                  // return root itself
    if (val < root->val)                              // situation in which value to be deleted is lesser than the val present at root
        root->left = NodeDeletion(root->left, val);   // traverse to the left of the root and call it recursively if condition satisfies
    else if (val > root->val)                         // situation in which value to be deleted is greater than the val present at root
        root->right = NodeDeletion(root->right, val); // traverse to the left of the root and call it recursively if condition satisfies
    else
    {
        if (root->left == NULL)             // if left node of root is null
        {                                   // Parent with 1 child case left node null
            NodeAddress temp = root->right; // take a temp pointer
            free(root);                     // freeing memory of the root over here cause child gets deleted
            return temp;                    // return temp pointer
        }
        else if (root->right == NULL)      // if right node of root is null
        {                                  // parent with 1 child case right node null
            NodeAddress temp = root->left; // take temp pointer assign it to the node left of root
            free(root);                    // free the node space allocation cause it got deleted
            return temp;
        }
        NodeAddress temp = FindMinElement(root->right);     // parent with two childs assign temp of the both to the min val of the right node
        root->val = temp->val;                              // assign root val to temp val
        root->right = NodeDeletion(root->right, temp->val); // delete the node on the right and plug the values
    }
    return root; // updates the treee
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
    } // inserting elements in the array
    printf("Traversal of given tree is \n");
    inorder(root);
    int del; // prints out the values in order of the binary search tree
    printf("enter element you wanna delete: \n");
    scanf("%d", &del);
    printf(" Delete number del %d \n", del);
    root = NodeDeletion(root, del);
    printf("modified inorder traversal of list is : \n");
    inorder(root);

    return 0;
}