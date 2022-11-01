#include <stdio.h>
#include <stdlib.h>
struct node{ // creating struct with vals and nodes
        int val; //value stored at a node
        struct node* next; //Pointer(points to the address) of the next node 
}*stdnode; //global node type to reference any randomn node
void ElementsinList(int n); //Creating Function to get all the elemtns of the list
void Displaylist(); // Creating function to display the list we got 
int main(){ 
    int n; // initializing input
    printf("Enter no of elements of linked list"); 
    scanf("%d\n", &n); //entering number of elements in linked list
    ElementsinList(n); //Taking the function that takes all the elements we want in the list with their values
    printf("Data entered in the list is");
    Displaylist(); //Displays the entire list
    return 0;}
  //  ----------------------------------------------------------------------  
   void ElementsInList(int n) {
    while(n > 1){  //Taking the value for each element of the linked list
        int i = 1; // counter over here to take the variables
        int j = 0; // using this to store the ith value entered in the list
             if (n>i){
                printf("Enter value of the %d variable ",i ); //
                 scanf ("%d", &j); 
                 struct node n_i; // Defining the struct type
                 n_i.val = j; //assigning value to the node
                n_i.next = &n_(i+1); //adding the address of the next node to it
                 i++;
            }
            else if (n = i) {
                printf("Enter value of the %d variable "i );
                scanf ("%d", &j); 
                struct node n_i;
                n_i.val = j;   
                n_i.next = NULL;
            }
            if (i< n; i =0, i++) {
             printf("node n_i is: %d\n",n_i.val); 
             printf("node n_2 is: %p\n", n_i.next);
            }
        }
   }
        
//  ---------------------------------------------------------------------- 
void DisplayList() {
}





