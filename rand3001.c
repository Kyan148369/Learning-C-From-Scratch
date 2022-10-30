#include <stdio.h>
#include <stdlib.h>
//Trying to play around with malloc need to fix error  error: expected expression before ‘int’
    //5 |     int* ptr = int(*)malloc (10* sizeof(int)); //Read up on calloc
int main() {
    int var =5;
    int* ptr = int(*)malloc (10* sizeof(int)); //Read up on calloc 
    ptr = realloc(ptr, 30 * sizeof(int));
    return 0;

}