#include <stdio.h>
#include <stdlib.h>
int main() {
    int i;
    int arr1[] = {0,1,2,3,4,5}; //The array values get assigned over here in ther respective indexes 
    for (i =0; i <10; i++) // this for loop deteremines the no of elements printed out in the array, also is it just the no of elements we print out or is it infinite but how does mmemory alloc work or is it what prof told us abt powers of 2 storage
    {
     // int *arr1 = (int*) malloc (5*sizeof(int)); //over here allocating 5 spafigire out why this aint workingces in the memory  for the array but how does comp know how much is the size of 1 int since technically they can be much bigger 
        printf("arr1[%d]= %d\n", i, arr1[i]); //over here we just print out the values of the index of the array i 
    }                                         // and its a dynamic array that when values arent defined  we get randomn values stored in the stack
                                              //nvm it works figure out how to basically loop instances of the values for the array for a mathematical func
    return 0;
}