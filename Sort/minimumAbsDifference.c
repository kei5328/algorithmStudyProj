#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


void swap(int * A, int i, int j)
{
    int temp= A[i];
    A[i] = A[j];
    A[j] = temp;
}

void quicksort(int * arr, int p, int r)
{
    if (p<r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }
}

int partition(int* A, int p, int r)
{
    int x=A[r];  // pivot vlaue(right most)
    int i=p-1;
    for (int j=p; j<r; j++)
    {

        if (A[j]<x)
        {
            i++;
            swap(A, i, j);
        }
    }
    swap(A, ++i, r);
    return i;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){

    // sort the array with quicksort.
    quicksort(arr, 0, arrSize-1);
    uint32_t min_diff = UINT32_MAX; // minimum difference between two numbers. ( initialize as max value)
    uint16_t min_cnt = 0; // # of minimum difference pairs

    uint32_t pair_log[arrSize-1];

    for (int ii = 0; ii<arrSize-1; ii++) // loop through the array
    {
        uint32_t diff = arr[ii+1]-arr[ii]; // current difference:
        if (diff<min_diff)
        {// the current difference is smaller than the current mininmum
            min_diff = diff; // update the minimum.
            min_cnt = 1; // reset the number to 1;
            pair_log[min_cnt-1] = ii;
        }
        else if (diff==min_diff) // current difference is the same as the minimum.
        {
            min_cnt++; // we have one more pair to generate the minimum difference.
            pair_log[min_cnt-1] = ii;
        }
    }

    // generate an array of ptr to int_arr
    int ** result_arr = (int **)malloc(sizeof(int*)*min_cnt); // use minimum count to construct the array.


    for (int ii = 0; ii<min_cnt; ii++)
    {
        int * pair_arr = (int *)malloc(sizeof(int)*2); // a pair number;
        *(pair_arr) = arr[pair_log[ii]];
        *(pair_arr+1) = arr[pair_log[ii]+1];
        *(result_arr+ii) = pair_arr;
    }

    /*
    uint16_t cnt = 0;
    for (int ii = 0; ii<arrSize; ii++)
    {// loop thru the array and find the one
        int diff = arr[ii+1]-arr[ii];
        if (diff==min_diff)
        {
            int * pair_arr = (int **)malloc(sizeof(int)*2); // a pair number;
            *(pair_arr) = arr[ii];
            *(pair_arr+1) = arr[ii+1];
            *(result_arr+cnt) = pair_arr;
            cnt++;
        }
        // once we have cnt, we don't need to continue this anymore.
        if (cnt==min_cnt) break;
    }
    */

    // handle the returnColumnSizes
    *returnColumnSizes = (int *)malloc(sizeof(int)*min_cnt);
    for (int ii = 0; ii<min_cnt; ii++)
    {
        *((*returnColumnSizes)+ii) = 2;
    }
    *returnSize = min_cnt;
    return result_arr;
}
