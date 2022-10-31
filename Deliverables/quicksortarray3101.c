#include <stdlib.h>
#include<stdio.h>
quicksort (a,0,n-1) // for array
void quicksort(int *a, int start, int stop) // couple of ifs for prection if a is null and so on
//make sure that we're not getting negative indexes as start and stop
{ if (!a || start > stop) return;
    int p = partition (a,start, stop);     // partition function written by someoene else for us to split and put everything at left of a of p is less then and right of a of p
    quicksort (a, start, p-1); // starting element to 1 element less than pivot
    quicksort(a, p+1, stop ); //element 1 more than pivot to stop
    // if this works this works recursively p-1 at some might be greater than start so we wanna make sure that doesnt happen

    
    
    
    
    
    
    
    
    
    
    
    
    // return 0;
}
//3,4 ways for partition available online look them up 
// r = rand(start,stop)
//swap (a,start,r)
int partition (int *a, inst start, int stop) {
    pivot = a[start]; 
    i = start+1;
    j = stop;
    // 14| i (index) | | | | | |  |           | j (index) |
    while (   i<= j  ) {
        if ( a[i]> pivot) {
            swap (a,i,j); // swap the last element and the element we checked for
            j = j-1; // now move the j one lower since we dont wanna mess with the sorted element
        
        }
        else { i =i+1;} //basically go to the next element
        // either j moves left or i moves right when i =j after its done 
    }
    swap (a, start, j)
    return j;
    //wall and scout method another one is there 
    // heap allows us to modify selection sort to be efficient

   
}