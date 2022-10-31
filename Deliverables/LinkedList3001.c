#include <stdio.h>
#include <stdlib.h>
struct node{ // creating struct with 
        int val;
        struct node* next;
};
int main(){ 
    struct node n_1, n_2; //defining variables in the struct type
    //struct node* ptr = malloc(sizeof(struct node));
    //scanf("n1_val = %d\n", n_1.val);
     n_1.val = 1; //assigning values to the variables
     n_2.val = 4; // ""
    n_1.next = &n_2; // Assigning the node part of a linked list as a pointer to the address of the n_2 variable over here
    n_2.next = NULL; // Assigning null to the pointer here 
    printf("node n_1 is: %d\n",n_1.val); 
    printf("node n_2 is: %d\n",n_2.val);
    printf("node n_2 is: %p\n", n_1.next);
    printf("node n_1 address is: %p\n",&n_1.val ); //printing out the address of n_1.val just to see 
    return 0;
}