#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// void swap(int *a, int *b) {}

int partition(int a[], int start, int stop)
{
    // int t = rand();
    // int rand_actual = (t % n); // Number thats in between 0 and n-1
    int pivot = a[stop];
    int i = (start - 1); // all the numbers lesser than pivot
                         // all the numbers greater than pivot
                         // Over here first assign pointers to i, j (start elements) actually i and j would just be counters in loops tbh start and stop would be diff
                         // Items on left which are greater on left should be flagged since we would want to switch them with lesser than pivot elements on the right
    // to switch both of them
    for (int j = start; j <= stop - 1; j++) // loop looking at from the end of the array
    {
        if (a[j] < pivot) // Items on right which are lesser than right should be flagged since we would want these values swapped to the left
        {
            i++;                // We increment i val
            int swapper = a[i]; // take the value at a[i] and swap it with that value
            a[i] = a[j];        // just switching it
            a[j] = swapper;     // swapped the other variable in place;
        }
    }
    int swapper = a[i + 1]; // incrementing a
    a[i + 1] = a[stop];
    a[stop] = swapper;
    return (i + 1);
}
void quicksort(int a[], int start, int stop)
{
    if (start < stop)
    {
        int p = partition(a, start, stop);
        quicksort(a, start, p - 1);
        quicksort(a, p + 1, stop);
    }
}

void PrintArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{

    int a[] = {32, 2342, 424, 2, 482, 424, 42, 51, 24, 13, 4, 41, 31, 3441};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Array to quicksort is");
    PrintArr(a, n);
    quicksort(a, 0, n - 1);
    printf("\nsorted array is");
    PrintArr(a, n);
    return 0;
}

// essentially we are splitting it into two partitions/arrays each time and taking pivots at middle

// 1)A divide and conquer algorithm that sorts an unsorted list using the following algorithm:
// Pick a random element from the list and swap it with the 0’th element (first position). We call this element the pivot element
// 2)Generate two new lists - lesser and greater
// 3)Compare every element in the list with the pivot element and push it into the corresponding list (if greater than pivot, add to greater list and so on)
// 4)We now combine the lists in the following way lesser - pivot - greater. Now, we have obtained the correct, sorted rank of the pivot element! (everything in lesser list is lower than the pivot value and everything in the greater list is larger than the pivot value)
// Now we can sort the lesser list and greater list individually using the same algorithm as above. i.e. repeat steps 1-4 for the lesser list and greater list simultaneously

// rand func

//     swap(*a, start, end){

//}
// {
// #quick sort

//     // swap func?
//     temp = arr[0];
//     arr[0] = arr[rand]     // where 0<=rand< n-1
//         arr[rand] = arr[0] // swapped
//         pivot = arr[0]     // pivot element

//         for (int i = 0, i < n, i++)
//     {
//         malloc(size of(arr(i) / arr(0))) if (pivot < arr[i])
//         {
//             malloc(arr);         // allocate memory for greater than list
//             greater[i] = arr[i]; // correct way to append?
//         }
//         else(pivot > arr[i])
//         {
//             malloc(arr); // allocate memory for greater list
//             lesser[i] = arr[i];
//             ''
//         }
//         func for (i = 0; i < lessersize; i++)
//             arrjoint = arr[i];

//         arrjoint = arr[lessersize];

//         for (j = lessrsize + 1; j < n; j++)
//             arrjoint = arr[j]

//         // recurse lesser and greater now?
//     }
