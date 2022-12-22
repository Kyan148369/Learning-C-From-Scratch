#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMUM_LEVEL 4 // Defining the maximum level of the skip list you can increase it and decrease it as you like between 1 and n
                        // Good rule of thumb is number of elements should be square root of n elements for it to be O(log n) time with high probability

// Node structure for a skip list node
typedef struct node // typedef to make it just write node
{
    int value;                     // value of the node in that list
    struct node **arrayofpointers; // array of pointers for each level
} node;

// Skip list structure
typedef struct skip_list
{
    node *head; // Pointer to the head node
    int level;  // Current level of the skip list
    int size;   // size of the skip list (numbers of nodes)
} skip_list;
// helper function for adding levels probabilistically trying to simulate a coin flip by splitting the max of
// the randomn into greater than or equal to half of its max so its technically the same as a coin flip incrementing of each level
int random_level()
{
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAXIMUM_LEVEL)
    {
        level++;
    }
    return level;
}
// initalize skip lists
skip_list *init_skip_list()
{
    skip_list *skiplist = (skip_list *)malloc(sizeof(skip_list));                            // allocating memory
    skiplist->level = MAXIMUM_LEVEL;                                                         // initializing level as max level for the head node
    skiplist->size = 0;                                                                      // Initialize size as 0
    skiplist->head = (node *)malloc(sizeof(node));                                           // allocae memory for the head node
    skiplist->head->value = 0;                                                               // initialize head value as 0
    skiplist->head->arrayofpointers = (node **)malloc(sizeof(node *) * (MAXIMUM_LEVEL + 1)); // Allocate memory for the pointersarray (MAX LEVEL+1 since we are starting from 0)
    // Initialize all pointers in the head node's pointers array to point to NULL
    for (int i = 0; i <= MAXIMUM_LEVEL; i++)
    {
        skiplist->head->arrayofpointers[i] = NULL;
    }
    return skiplist;
}

void insert(skip_list *sl, int value)
{
    // Array to hold pointers to nodes at each level that need to be updated after inserting the new node
    node *update[MAXIMUM_LEVEL + 1];
    node *temp = sl->head; // Set the current node to the head node

    // Check if the value is of type int
    if (value == (int)value)
    {
        // Run a for loop going through each level in the skip list, starting from the highest level
        for (int i = sl->level; i >= 0; i--)
        {
            // While the current node's forward pointer at the current level is not null and the value of the node
            // it points to is less than the value to be inserted, move to the next node at the current level
            while (temp->arrayofpointers[i] != NULL && temp->arrayofpointers[i]->value < value)
            {
                temp = temp->arrayofpointers[i];
            }
            // Update the node to be updated at the current level

            update[i] = temp;
        }
        // Set the current node to the node at the lowest level (level 0)
        temp = temp->arrayofpointers[0];
        // If the current node is null or its value is not equal to the value to be inserted, insert a new node
        if (temp == NULL || temp->value != value)
        { // Generate a random level for the new node

            int level = (sl->size == 0) ? MAXIMUM_LEVEL : random_level();
            // If the level of the new node is higher than the current level of the skip list,
            // update the update array to point to the head node at the higher levels
            if (level > sl->level)
            {
                for (int i = sl->level + 1; i <= level; i++)
                {
                    update[i] = sl->head;
                }
                // Update the level of the skip list to the level of the new node

                sl->level = level;
            }
            // Allocate memory for the new node

            temp = (node *)malloc(sizeof(node));
            temp->value = value; // Set the value of the new node to the value to be inserted
            temp->arrayofpointers = (node **)malloc(sizeof(node *) * (level + 1));
            // Allocate memory for the array of pointers of the new node
            // Update the pointers of the nodes at each level to point to the new node
            for (int i = 0; i <= level; i++)
            {
                temp->arrayofpointers[i] = update[i]->arrayofpointers[i];
                update[i]->arrayofpointers[i] = temp;
            }
            sl->size++;
        }
        else
        {
            // If the current node is not null and its value is equal to the value to be inserted, update the value of the current node
            temp->value = value;
        }
    }
    else
    {
        // If the value is not of type int, throw an error

        printf("Error: Value must be of type int.\n");
    }
}

node *search(skip_list *skiplist, int value)
{
    // Set the current node to the head node

    node *temp = skiplist->head;
    // run a for loop through the skip list from the top level to the bottom level

    for (int i = skiplist->level; i >= 0; i--)
    {
        // While the current node's forward pointer at the current level is not null and the value of the node
        // it points to is less than the value to be searched for, move to the next node at the current level

        while (temp->arrayofpointers[i] != NULL && temp->arrayofpointers[i]->value < value)
        {
            temp = temp->arrayofpointers[i];
        }
    }
    // Set the current node to the node at the lowest level (level 0)
    temp = temp->arrayofpointers[0];
    // If the current node is not null and its value is equal to the value to be searched for, return the current node
    if (temp != NULL && temp->value == value)
    {
        return temp;
    }
    // otherwise return NULL
    else
    {
        return NULL;
    }
}

void delete (skip_list *sl, int value)
{
    // Create an update array to store the nodes that need to be updated when a node is deleted
    node *update[MAXIMUM_LEVEL + 1];
    // Set the current node to the head node
    node *temp = sl->head;
    // Check if the value is present in the skip list
    node *node = search(sl, value);
    if (node == NULL)
    {
        printf("Error: value not present in the skip list, invalid operation\n");
        return;
    }

    for (int i = sl->level; i >= 0; i--)
    {
        // While the current node's forward pointer at the current level is not null and the value of the node it points to
        // is less than the value to be deleted, move to the next node at the current level

        while (temp->arrayofpointers[i] != NULL && temp->arrayofpointers[i]->value < value)
        {
            temp = temp->arrayofpointers[i];
        }
        // Add the current node to the update array at the current level

        update[i] = temp;
    }
    // Set the current node to the node at the lowest level (level 0)

    temp = temp->arrayofpointers[0];
    // If the current node is not null and its value is equal to the value to be deleted, proceed with the deletion

    if (temp != NULL && temp->value == value)
    {
        // Check if the current head node is being deleted
        if (temp == sl->head)
        {
            // Update the head node's pointers array
            for (int i = 0; i <= sl->level; i++)
            {
                sl->head->arrayofpointers[i] = temp->arrayofpointers[i];
            }
        }
        else
        {
            for (int i = 0; i <= sl->level; i++)
            {
                if (update[i]->arrayofpointers[i] != temp)
                {
                    break;
                }
                update[i]->arrayofpointers[i] = temp->arrayofpointers[i];
            }
        }
        // Free the memory allocated for the node to be deleted

        free(temp->arrayofpointers);
        free(temp);
        // Decrement the level of the skip list if the head node has a forward pointer at the current level that is null
        while (sl->level > 0 && sl->head->arrayofpointers[sl->level] == sl->head)
        {
            sl->level--;
        }
        // Decrement the size of the skip list

        sl->size--;
    }
}

void print_skip_list(skip_list *skiplist)
{
    for (int i = 0; i <= skiplist->level; i++)
    {
        node *temp = skiplist->head;
        printf("Level %d: ", i);
        while (temp->arrayofpointers[i] != NULL)
        {
            printf("%d ", temp->arrayofpointers[i]->value);
            temp = temp->arrayofpointers[i];
        }
        printf("\n");
    }
}
// driver function code is self explanatory with the test cases
int main()
{
    srand((unsigned int)time(NULL));
    skip_list *skiplist = init_skip_list();

    insert(skiplist, 10);
    insert(skiplist, 20);
    insert(skiplist, 30);
    insert(skiplist, 40);
    insert(skiplist, 50);
    print_skip_list(skiplist);

    node *node = search(skiplist, 39);
    if (node != NULL)
    {
        printf("Found node with value %d\n", node->value);
    }
    else
    {
        printf("Node not found\n");
    }

    delete (skiplist, 10);
    print_skip_list(skiplist);

    node = search(skiplist, 40);
    if (node != NULL)
    {
        printf("Found node with value %d\n", node->value);
    }
    else
    {
        printf("Node not found\n");
    }
    insert(skiplist, 17);
    print_skip_list(skiplist);

    return 0;
}
