#include <stdio.h>
#include <stdlib.h>

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
NodeAddress sorted = NULL;        //  Head is a pointer to an address which must contain node

void ElementsInList(int n)
{
    NodeAddress temp; // creating temp pointer to a node

    head = (NodeAddress)malloc(sizeof(struct node)); // Allocating memory for 1 node

    if (head == NULL)
    { // When theres no val and no link we will not allocate memory
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

void sortedInsert(NodeAddress newnode)
{
    if (sorted == NULL || (sorted->val) >= (newnode->val))
    {                           // if sorted element is null or sorted val is greater than new node val
        newnode->link = sorted; // newnode val is equal to sorted node
        sorted = newnode;       // sorted = newnode
    }
    else
    {
        NodeAddress current = sorted;
        /* Locate the node before the point of insertion
         */
        while (current->link != NULL && current->link->val < newnode->val)
        {
            current = current->link;
        }
        newnode->link = current->link;
        current->link = newnode;
    }
}

void insertionsort()
{

    NodeAddress current = head;

    // Traverse the given linked list and insert every
    // node to sorted
    while (current != NULL)
    {

        // Store next for next iteration
        NodeAddress next = current->link;

        // insert current in sorted linked list
        sortedInsert(current);

        // Update current
        current = next;
    }
    // Update head to point to sorted linked list
    head = sorted;
}

int main()
{
    int n;
    printf("Enter no of elements of linked list:");
    scanf("%d", &n);   // entering number of elements in linked list
    ElementsInList(n); // Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is\n");
    displayList(); // Displays the entire list
    printf("Linked List before sorting:\n");
    displayList(head);
    printf("\n");

    insertionsort(head);

    printf("Linked List after sorting:\n");
    displayList(head);

    return 0;
}
//  ----------------------------------------------------------------------
