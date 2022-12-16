#include <stdlib.h>
#include <stdio.h>
// over here we basically have more than 1 look ahead in the struct node and its a pointer of a pointer

struct node
{                      // creating struct with vals and nodes, typedef helps with having
                       // to not redeclare struct each time
    int val;           // value stored at a node
    struct node *link; // Pointer(points to the address) of the next node
    struct node *lookahead1;
    struct node *lookahead2;
};
typedef struct node *NodeAddress; // Renaming reference(pointer) to struct node as node address
NodeAddress temp;
head = (NodeAddress)malloc(sizeof(struct node));
if (head == NULL)
{
    printf('no memory allocated');
}
else
{
    int val = 0;
    printf('Enter data for node 1');
    scanf("%d", &val);
    head->val = val;
    look
        temp = head;
}

int main()
{
    return 0;
}