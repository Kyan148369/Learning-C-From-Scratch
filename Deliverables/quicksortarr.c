#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *a, int *b) {}

quicksort int partition(pivot, start, stop, n)
{
    int *p;
    int *q;
    int t = rand();
    int rand_actual = (t % n); // Number thats in between 0 and n-1
    pivot = a[rand_actual];
    start = a[0];    // all the numbers lesser than pivot
    stop = a[n - 1]; // all the numbers greater than pivot
    // Over here first assign pointers to i, j (start elements) actually i and j would just be counters in loops tbh start and stop would be diff
    // Items on left which are greater on left should be flagged since we would want to switch them with lesser than pivot elements on the right
    // Items on right which are lesser than right should be flagged for the same reason and once they both are found swap function is called
    // to switch both of them
    for (int i = 0, i < n, i++)
    {
        for (int j = n - 1, j > 0, j--)
        {
            if (a[j] < pivot && a[i] > pivot)
            {
                swap(p, q);
            }

            if (a[i] > pivot)
            {
                p = a[i];
            }
            pivot = a[]
        }
    }
    return (i + 1)
    // printf("rand we will use is %d", rand_actual);
}

int quicksort() {}

void PrintArr(a, n)
{
    for (int i; i < n, i++)
    {
        printf("Element number %d is %d", i, a[i]);
    }
}

int main()
{

    int a[] = [ 32, 2342, 424, 2, 482, 424, 42, 51, 24, 13, 4, 41, 31, 3441 ];
    int n = sizeof(a) / size of(a[0]);
    printf("Array to quicksort is");
    PrintArr(a, n);
    quicksort(a, 0, n - 1);
    printf("sorted array is");
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
