#include <stdlib.h>
#include <stdio.h>

struct node
{                      // creating struct with vals and nodes, typedef helps with having
                       // to not redeclare struct each time
    int val;           // value stored at a node
    struct node *link; // Pointer(points to the address) of the next node
};
typedef struct node *NodeAddress; // Renaming reference(pointer) to struct node as node address
NodeAddress head;

int main()
{
    return 0;
}