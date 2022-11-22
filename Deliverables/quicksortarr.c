#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// essentially we are splitting it into two partitions/arrays each time and taking pivots at middle

// 1)A divide and conquer algorithm that sorts an unsorted list using the following algorithm:
// Pick a random element from the list and swap it with the 0’th element (first position). We call this element the pivot element
// 2)Generate two new lists - lesser and greater
// 3)Compare every element in the list with the pivot element and push it into the corresponding list (if greater than pivot, add to greater list and so on)
// 4)We now combine the lists in the following way lesser - pivot - greater. Now, we have obtained the correct, sorted rank of the pivot element! (everything in lesser list is lower than the pivot value and everything in the greater list is larger than the pivot value)
// Now we can sort the lesser list and greater list individually using the same algorithm as above. i.e. repeat steps 1-4 for the lesser list and greater list simultaneously

// rand func

//     swap(*a, n)
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

int main()
{
    int n = 11;
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("element number %d:", i + 1);
        scanf("%d", &a[i]);
    }

    int t = rand();
    printf("rand number is %d", t);
    int rand_actual = (t % 11);
    printf("rand we will use is %d", rand_actual);
    return 0;
}