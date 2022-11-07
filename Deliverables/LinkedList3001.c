#include <stdio.h>
#include <stdlib.h>
struct node{                                                      // creating struct with vals and nodes
        int val;                                                 //value stored at a node
        struct node *next;                                       //Pointer(points to the address) of the next node 
}*stdnode;                                                      //global node type to the head node

void ElementsInList(int n) {
    struct node *temp;                              // creating pointers in the linked list                                                  // gotta reinitiliaze variables inside func
                                                     
    stdnode = (struct node* ) malloc (sizeof(struct node));    // Allocating memory of nodes based on number of nodes 
                
    
    if(stdnode == NULL)  
     {                               //check whether the standard node is NULL and if so no memory allocation
         printf("Memory wont be allocated");
    }
    else {

        printf("Enter first element of list");               //entering the head element of the linked list
        scanf("%d\n",&stdnode->val);                          // putting the pointer to the value of the node 
        temp = stdnode;                                     // copying the address of stdnode to temp


        for (int i=2;i<=n; i++) 
        {
                temp->next = malloc(sizeof(struct node)); //allocating memory and creating the next node 
                temp = temp->next;                        // traversing to the next node and assigning the value of temp to it
                printf(" Input data for node %d : ", i);   // input data for the ith element
                scanf(" %d", &temp->val);                        //enter input in the address of val        
 
            }                
      }
    }                                   //Creating Function to get all the elemtns of the list

void displayList() // displays Linked list with their elemtn
    {
    struct node *temp;   
    if(stdnode == NULL)  //if no elements in list print null 
    {
        printf(" List is empty.");
    }
    else
    {
        temp = stdnode;     // No of elements in std node
        while(temp != NULL)
        {
            printf(" Data = %d\n", temp->val);       // prints the data of current node
            temp = temp->next;                     // advances the position of current node
        }
    }
} 


                                            // Creating function to display the list we got 
int main(){ 
    int n;                                                      //initializing input
    printf("Enter no of elements of linked list"); 
    scanf("%d\n", &n);                                         //entering number of elements in linked list
    ElementsInList(n);                                         //Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is");
    displayList();                                            //Displays the entire list
    return 0;
    }
  //  ----------------------------------------------------------------------  
    
    
   

