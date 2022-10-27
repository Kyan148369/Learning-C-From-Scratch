#include<stdio.h>
#include<stdlib.h>
//Playing around with consts over here 
int main(){
const int var = 10;

int *ptr = &var; // initializing pointer as the value stored in address of var
*ptr = 12; //assign 12 in pointer

printf("var = %d\n", var);
printf("*ptr = %d\n", *ptr);
return 0;  
}