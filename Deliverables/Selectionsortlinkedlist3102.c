#include <stdio.h>
#include <stdlib.h>
// Implementation of a Linked List: Given a set of values (assume int), create a linked list from them
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
                                  //  Head is a pointer to an address which must contain node

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

// Selection sort
// Use two loops traversing and keep comparing it with the ith element when we are traversing the jth loop and if that is the new min
// update that and after its done running through the loop then update its values
//
//  node i, node j, node temp , node min int t,
//

NodeAddress quicksort(int n)
{
    NodeAddress i;
    NodeAddress j;
    NodeAddress min = head;
    int t;

    while (head != NULL && head->link != NULL)
    {             // check
        i = head; // starting from head node
                  // i->val  comparing with this for global min
        j = i;
        while (i->link != NULL && i != NULL)
        {
            while (j->link != NULL && j != NULL)
            {
                if (i->val < j->val)
                {
                    NodeAddress min = j; // assignming min pointer to j
                    int t = j->val;      // temp val
                }
                j = j->link; // updating counter j = j+1
            }
            min->val = i->val;
            i->val = t;
            i = i->link; // updating counter
        }
    }
    return head;
}

int main()
{
    int n;
    printf("Enter no of elements of linked list:");
    scanf("%d", &n);   // entering number of elements in linked list
    ElementsInList(n); // Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is\n");
    displayList(); // Displays the entire list
    quicksort(n);
    displayList();
    return 0;
}
//  ----------------------------------------------------------------------
