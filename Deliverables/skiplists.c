#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 6
int INT_MAX = 6;
typedef struct node // Node structure for a skip list node

{
    int key;               // Key value of the node
    int value;             // Value associated with the key
    struct node **forward; // Array of pointers to the next node at each level
} node;

typedef struct skip_list
{
    int level;           // Current level of the skip list
    int size;            // size of the skip list node
    struct node *header; // Pointer to the head node
} skip_list;

skip_list *init_skip_list() // initalize skip lists
{
    skip_list *sl = (skip_list *)malloc(sizeof(skip_list)); // allocating memory
    sl->level = 0;
    sl->size = 0;
    sl->header = (node *)malloc(sizeof(node)); // allocate memory for the head node
    sl->header->key = INT_MAX;                 // head as max of key
    sl->header->forward = (node **)malloc(sizeof(node *) * (MAX_LEVEL + 1));
    for (int i = 0; i <= MAX_LEVEL; i++) // Initialize the next pointers of the head node to point to itself at each level
    {
        sl->header->forward[i] = NULL;
    }
    return sl; // Return a pointer to the newly initialized skip list
}
int main()
{
    return 0;
}