#include <stdio.h>
#include <stdlib.h>

 struct node
{                                                                      // creating struct with vals and nodes, typedef helps with having 
                                                                       //to not redeclare struct each time 
        int val;                                                       //value stored at a node
        struct node *link;                                             //Pointer(points to the address) of the next node 
};      
typedef struct node* NodeAddress;                                      //Renaming reference(pointer) to struct node as node address
NodeAddress head;                                                      //Nodeaddress accepts pointer to a node (Nodeaddress is a data type sorta like int* x)
                                                                      // Head is a pointer to an address which must contain node 

NodeAddress reverse(NodeAddress head)                                // reverse function over here using nodeaddress because we're returning data type
                                                                     // of a pointer which contains node and it takes head as an arg
    {
    NodeAddress prev = NULL;                                         // pointer to keep track of the previous node
    NodeAddress next = NULL;                                         // pointer to keep track of next element 
     while(head != NULL)                                              // while head node is not null cause if it is we have effectively reversed 
    {                                                                 // the list after going through the below loop
        next = head->link;                                           // We are assigning the next address value one thats linking head to link
        head->link = prev;                                           // Now we are assigning the head link to the prev element value
        prev = head;                                                 // Now we take prev pointer and assign it to head value
        head = next;                                                 // Finally we move onto the next node address by assigning head
    }
    head = prev;                                                     //post the loop its basically just assigning it back 
    return head;                                                     //returns the head of the linked list
}
   

//First we need to assign a slow and fast pointer
//After that we keep them traversing 
// slow pointer 1 node at a time fast node two nodes at a time
//When we reach the last element in the list for the fast pointer (NULL)
// element we return the position of the slow pointer which is half of the size of a list without knowing its size
NodeAddress Printingfirsthalf(NodeAddress head)                    // Over here we declare the data type of the argument here
   { 
    NodeAddress slow = head;                                        // Assigning and intiliazing a pointer separate from the data structure in head?
    NodeAddress fast = head;  
    printf("The first half elements are: ");  
    while (fast != NULL && fast->link != NULL){
        printf("%d ", slow->val);
        fast = fast->link->link;
        slow = slow-> link;
        }
    printf("\n");
    return head;
    }
    
    
void ElementsInList(int n) {
    NodeAddress temp;                                                 // creating temp pointer to a node         
                                                     
    head = (NodeAddress) malloc (sizeof(struct node));               // Allocating memory for 1 node
                
    
    if(head == NULL)  
     {                                                                //When theres no val and no link we will not allocate memory
         printf("Memory wont be allocated");
    }
    else {

        printf("Input data for node 1:");                            //entering the head element of the linked list
        scanf("%d",&head->val);                                      // putting the pointer to the value of the node 
        temp = head;                                                 // copying the address of head to temp pointer 


        for (int i=2;i<=n; i++) 
        {
                temp->link = malloc(sizeof(struct node));             //allocating memory and creating the next node 
                temp = temp->link;                                    // Over here we shifting temp pointer to the next node
                printf("Input data for node %d : ", i);              // input data for the ith element
                scanf("%d", &temp->val);                             //enter input in the address of val        
 
            }                
      }
    }                                                                
 

void displayList()                                                  //Creating Function to get all the elements of the linked list
    {
    NodeAddress temp;                                               // Temp pointer to traverse the nodes and prints the next address  
    if(head == NULL)                                                //if no elements in list print null 
    {
        printf(" List is empty.");
    }
    else
    {
        temp = head;                                                 // Pointer temp address to point to head node
        while(temp != NULL)                                          // Go to the node and make sure its not empty then we go on to print below
        {
            printf(" Data = %d\n", temp->val);                      // prints the val of current node which is pointed to by the pointer(which can see val and address)
            temp = temp->link;                                      // advances the position of current node and checks the next node
        }
    }
} 


int main(){ 
    int n;                                                          //initializing input
    printf("Enter no of elements of linked list:"); 
    scanf("%d", &n);                                               //entering number of elements in linked list
    ElementsInList(n);                                             //Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is\n");
    displayList();                                                //Displays the entire list
    head = reverse(head);
    printf("Reversed linked list is \n");
    displayList();  
    Printingfirsthalf(head);                                     

    return 0;
    }
  //  ----------------------------------------------------------------------  
    
    
   

