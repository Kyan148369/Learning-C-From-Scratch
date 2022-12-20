#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MAX_LEVEL = 6;

// Node structure for a skip list node
typedef struct node
{
    int key;               // position of the node
    int value;             // value of the node in that list
    struct node **forward; // array of pointers
} node;

// Skip list structure
typedef struct skip_list
{
    int level;           // Current level of the skip list
    int size;            // size of the skip list
    struct node *header; // Pointer to the head node
} skip_list;

// initalize skip lists
skip_list *init_skip_list()
{
    skip_list *sl = (skip_list *)malloc(sizeof(skip_list)); // allocating memory
    sl->level = 0;
    sl->size = 0;
    sl->header = (node *)malloc(sizeof(node)); // allocate memory for the head node
    sl->header->key = MAX_LEVEL;               // head as max of key
    sl->header->forward = (node **)malloc(sizeof(node *) * (MAX_LEVEL + 1));
    for (int i = 0; i <= MAX_LEVEL; i++) // Initialize the next pointers of the head node to point to itself at each level
    {
        sl->header->forward[i] = NULL; // create space for each linked list
    }
    return sl;
}
// adding levels probabilistically
int random_level()
{
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
    {
        level++;
    }
    return level;
}
// inserting elements in the skipped lists
void insert(skip_list *sl, int key, int value)
{
    node *update[MAX_LEVEL + 1];
    node *x = sl->header;

    for (int i = sl->level; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->key < key)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
}
// function to print skip lists
void print_skip_list(skip_list *sl)
{
    for (int i = 0; i <= sl->level; i++)
    {
        node *x = sl->header;
        printf("Level %d: ", i);
        while (x->forward[i] != NULL)
        {
            printf("%d(%d) ", x->forward[i]->key, x->forward[i]->value);
            x = x->forward[i];
        }
        printf("\n");
    }
}
// driver function
int main()
{
    srand((unsigned int)time(NULL));

    skip_list *sl = init_skip_list();

    insert(sl, 1, 10);
    insert(sl, 2, 20);
    insert(sl, 3, 30);
    insert(sl, 4, 40);
    insert(sl, 5, 50);
    insert(sl, 6, 60);

    print_skip_list(sl);

    return 0;
}