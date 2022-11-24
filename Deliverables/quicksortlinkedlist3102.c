#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
struct node
{                      // creating struct with vals and nodes, typedef helps with having
                       // to not redeclare struct each time
    int val;           // value stored at a node
    struct node *link; // Pointer(points to the address) of the next node
};
typedef struct node *NodeAddress; // Renaming reference(pointer) to struct node as node address
NodeAddress head;                 // Nodeaddress accepts pointer to a node (Nodeaddress is a data type sorta like int* x)
// Head is a pointer to an address which must contain node
void ElementsInList(int n)
{
    NodeAddress temp; // creating temp pointer to a node

    head = (NodeAddress)malloc(sizeof(struct node)); // Allocating memory for 1 node

    if (head == NULL)
    { // When theres no val and no link we will not allocate mcmory
        printf("Memory wont be allocated");
    }
    else
    {

        printf("Input data for node 1:"); // entering the head element of the linked list
        scanf("%d", &head->val);          // putting the pointer to the value of the node
        temp = head;                      // copying the address of head to temp pointer

        for (int i = 2; i <= n; i++)
        {
            temp->link = malloc(sizeof(struct node)); // allocating memory and creating the next node
            temp = temp->link;                        // Over here we shifting temp pointer to the next node
            printf("Input data for node %d : ", i);   // input data for the ith element
            scanf("%d", &temp->val);                  // enter input in the address of val
        }
    }
}

void displayList() // Creating Function to get all the elements of the linked list
{
    NodeAddress temp; // Temp pointer to traverse the nodes and prints the next address
    if (head == NULL) // if no elements in list print null
    {
        printf(" List is empty.");
    }
    else
    {
        temp = head;         // Pointer temp address to point to head node
        while (temp != NULL) // Go to the node and make sure its not empty then we go on to print below
        {
            printf(" Data = %d\n", temp->val); // prints the val of current node which is pointed to by the pointer(which can see val and address)
            temp = temp->link;                 // advances the position of current node and checks the next node
        }
    }
}

NodeAddress lastnode(NodeAddress head)
{
    NodeAddress temp = head;
    while (temp != NULL & temp->link != NULL)
    {
        temp = temp->link; // Keep traversing the list while neither temp is null or temp-> next address is null
    }
    return temp;
}

// We are Setting the given last node position to its proper
// position
// Over here we are making sure that the element in the first half of the pivot list is lesser than the last element(2nd half technically)
// While the condition satisfies we keep switching the vals of the pointers then advance forward and once the condition doesnt hold true
// We end up switching the values of the last node which we got from lastnode func and switch it with the node which is greater
// than the last element in the first half of the list and we continue this till the partition is achieved

//
NodeAddress partition(NodeAddress first, NodeAddress pivot)
{
    NodeAddress prev = first;           // We are using the start element of the linkedlist as prev over here
    NodeAddress traverse_ahead = first; // Another pointer to help us in swapping assigning it to the starting point of the node
    int temp = 0;                       // Another temp int variable to help us in swapping
    while (traverse_ahead != NULL && traverse_ahead != pivot)
    { // checks in place
        if (traverse_ahead->val < pivot->val)
        {                 // if the pivot val is greater than the first val
            prev = first; // assign prev to start

            temp = first->val;                // Swapping  node values of the pointers
            first->val = traverse_ahead->val; // switching the vals of the pointers
            traverse_ahead->val = temp;       // switching the traverse_ahead val to (start->val technically)

            first = first->next; // this is us advancing forward essentially
        }

        traverse_ahead = traverse_ahead->next; // Traversing to the next node
    }

    temp = first->val; // Change pivot node value to the current node
    first->val = pivot->val;
    pivot->val = temp;
    return prev;
}

int main()
{
    int n; // initializing input
    printf("Enter no of elements of linked list:");
    scanf("%d", &n);   // entering number of elements in linked list
    ElementsInList(n); // Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is\n");
    displayList(); // Displays the entire list
    head = reverse(head);
    printf("Reversed linked list is \n");
    displayList();
    return 0;

    return 0;
}
