#include <stdio.h>
//program that accepts numbers below a certain range and prints them
int main() { //defining function overhere
    int i = 0; 
    while ( i < 10 ) {
        printf("Enter a number lesser than 10 \n"); //Outputs a number less than 10 
       scanf("%d\n",&i); //Takes input from the user and Stores the value in the address of i 
        printf("The number you inputted is %d\n", i); //Outputs the number printed 
    
    }
    return 0;
} 
