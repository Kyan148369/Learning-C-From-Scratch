#include <stdio.h>
#include <stdlib.h>
 struct node
{                                                                      // creating struct with vals and nodes, typedef helps with having 
                                                                       //to not redeclare struct each time 
        int val;                                                       //value stored at a node
        struct node *link;                                             //Pointer(points to the address) of the next node 
};      
typedef struct node* NodeAddress;                                      //global node type to the head node
NodeAddress stdnode;


struct node* reverse(struct node *stdnode)                              // reverse function over here 
    {
    struct node *prev = NULL;                                           // pointer to keep track of the previous node
    struct node *next = NULL;                                           // pointer to keep track of next element 
     while(stdnode != NULL)                                             // while head node is not null cause if it is we have effectively reversed 
    {                                                                   // the list after going through the below loop
        next = stdnode->link;                                           // We are assigning the next address value one thats linking stdnode to link
        stdnode->link = prev;                                           // Now we are assigning the head link to the prev element value
        prev = stdnode;                                                 // Now we take prev pointer and assign it to head value
        stdnode = next;                                                 // Finally we move onto the next node address by assigning stdnode
    }
    stdnode = prev;                                                     //post the loop its basically just assigning it back 
    return stdnode;                                                     // returns the head of the linked list
}
   

//First we need to assign a slow and fast pointer
//After that we keep them traversing 
// slow pointer 1 node at a time fast node two nodes at a time
//When we reach the last element in the list for the fast pointer (NULL)
// element we return the position of the slow pointer which is half of the size of a list without knowing its size
struct node* FindingHalofLinkedList(struct node *stdnode)
    {
    struct node *slow = stdnode;
    struct node *next = stdnode;
    }
    
void ElementsInList(int n) {
    struct node *temp;                                                  // creating pointers in the linked list        
                                                     
    stdnode = (struct node* ) malloc (sizeof(struct node));            // Allocating memory of nodes based on number of nodes 
                
    
    if(stdnode == NULL)  
     {                                                                 //check whether the standard node is NULL and if so no memory allocation
         printf("Memory wont be allocated");
    }
    else {

        printf("Enter first element of list");                         //entering the head element of the linked list
        scanf("%d",&stdnode->val);                                   // putting the pointer to the value of the node 
        temp = stdnode;                                                // copying the address of stdnode to temp pointer 


        for (int i=2;i<=n; i++) 
        {
                temp->link = malloc(sizeof(struct node));             //allocating memory and creating the next node 
                temp = temp->link;                                    // traversing to the next node and assigning the value of temp to it
                printf(" Input data for node %d : ", i);              // input data for the ith element
                scanf(" %d", &temp->val);                             //enter input in the address of val        
 
            }                
      }
    }                                                                
 

void displayList()                                                    //Creating Function to get all the elemtns of the list
    {
    struct node *temp;   
    if(stdnode == NULL)                                              //if no elements in list print null 
    {
        printf(" List is empty.");
    }
    else
    {
        temp = stdnode;                                             // Pointer temp address as head node 
        while(temp != NULL)
        {
            printf(" Data = %d\n", temp->val);                      // prints the data of current node
            temp = temp->link;                                      // advances the position of current node
        }
    }
} 


int main(){ 
    int n;                                                          //initializing input
    printf("Enter no of elements of linked list"); 
    scanf("%d", &n);                                               //entering number of elements in linked list
    ElementsInList(n);                                             //Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is\n");
    displayList();                                                //Displays the entire list
    stdnode = reverse(stdnode);
    printf("Reversed linked list is \n");
    displayList();                                               

    return 0;
    }
  //  ----------------------------------------------------------------------  
    
    
   

