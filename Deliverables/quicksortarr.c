#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

//essentially we are splitting it into two partitions/arrays each time and taking pivots at middle 

// 1)A divide and conquer algorithm that sorts an unsorted list using the following algorithm:
// Pick a random element from the list and swap it with the 0’th element (first position). We call this element the pivot element
// 2)Generate two new lists - lesser and greater
// 3)Compare every element in the list with the pivot element and push it into the corresponding list (if greater than pivot, add to greater list and so on)
// 4)We now combine the lists in the following way lesser - pivot - greater. Now, we have obtained the correct, sorted rank of the pivot element! (everything in lesser list is lower than the pivot value and everything in the greater list is larger than the pivot value)
// Now we can sort the lesser list and greater list individually using the same algorithm as above. i.e. repeat steps 1-4 for the lesser list and greater list simultaneously


#quick sort 
int main (
    return 0;
)