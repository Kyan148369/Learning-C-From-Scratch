#include <stdio.h>
#include <stdlib.h>
struct node{                                                      // creating struct with vals and nodes
        int val;                                                 //value stored at a node
        struct node *next;                                       //Pointer(points to the address) of the next node 
}*stdnode;                                                      //global node type to reference any randomn node
void ElementsinList(int n);                                     //Creating Function to get all the elemtns of the list
void displaylist();                                             // Creating function to display the list we got 
int main(){ 
    int n;                                                      //initializing input
    printf("Enter no of elements of linked list"); 
    scanf("%d\n", &n);                                         //entering number of elements in linked list
    ElementsinList(n);                                         //Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is");
    displaylist();                                            //Displays the entire list
    return 0;
    }
  //  ----------------------------------------------------------------------  
    void ElementsInList(int n) {
    struct node *funcnode,*temp;                              // creating pointers in the linked list
    int val, i;                                                      // gotta reinitiliaze variables inside func
                                                     
    stdnode = (struct node* ) malloc (sizeof(struct node));    // Allocating memory of nodes based on number of nodes 
                
    
    if(stdnode == NULL )  
     {                               //check whether the standard node is NULL and if so no memory allocation
         print ("Memory wont be allocated");
    }
    else {

        printf("Enter first element of list");               //entering the head element of the linked list
        scanf("%d\n",&val) ; 
        stdnode->val = val;                                 // assigning the pointer of the val to the val entered at address of n 
                                                            // equivalent of saying head.val = val;
        stdnode->next = NULL;                               // assigning the value of this node to NULL;
        temp = stdnode;                                     // Creating temp as the stdnode for the head now


        for (i=2;i<=n; i++) 
        {
                funcnode = (struct node*) malloc (sizeof(struct node)); //Defining node type for remaining nodes
            
            if (funcnode = NULL) 
            {
 
                printf(" Memory wont be allocated.");    // No memory allocated here and list stops here 
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);   // input data for the ith element
                scanf(" %d", &val);                        //enter input in the address of val
                funcnode->val = val;                       // Enter value of that node
                funcnode->next = NULL;                     // Update address of node with null 

                temp-> next = funcnode;                    // Updates temp to func node and links list 
                temp = temp->next;                         
 
            }
         }

            
        
      }
    }
    
   

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


