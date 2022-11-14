#include <stdio.h>
#include<stdlib.h>
 
 
void swap(int* x, int* y)
{
 
    int temp = *x;
 
    *x = *y;
 
    *y = temp;
}
 

void heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < n && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
 
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
 
        heapify(arr, n, i);
 
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}
 
void printArray(int arr[], int n)
{
     int n = sizeof(arr) / sizeof(arr[0]);

    printf("Enter number of elements desired in array:");       // self explanatory

    scanf ("%d", &n);                                           // takes n number of elements in array as input
    for (int i =0; i<n; i++){                                   //takes user input for array from 1 till n
        printf ("Enter value for array position %d: " , i);
        scanf ("%d", &arr[i]);
    }
}
 
int main()
{
    printArray(arr, n);
 
    heapSort(arr, n);
    printf("Sorted array is\n");
   
}
 
// This code is contributed by _i_plus_plus_