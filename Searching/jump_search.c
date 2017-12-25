#include <stdlib.h>
#include <math.h> /* sqrt */
#include "utils.h"

// Searching algorithm for sorted arrays. 
int jump_search(int *arr, int x, int n) 
{
    int i, block;

    block = (int)sqrt(n);
    
    if (arr[0] == x) {
        return arr[0];
    }
    // check every index i, 2i, 4i, ..., ki
    while (arr[block-1] < x && block < n) {
        if (arr[block-1] == x) {
            return block;
     
       }
       // printf("arr[%d] = %d \n", block, arr[block]); 
        block *= 2;
    }
    // Found element larger than target, or at end of array
    // perform linear search from (block/2)+1 to n
    for (i = (block/2)+1; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    // Target was not found
    return -1;
}

int interloper_search(int *arr, int x, int n)
{
    int lo, hi; // beginning and ending indices of array
    int pos;    // calculated position
    
    lo = 0, hi = n-1;

    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
       
       // Probing position with keeping uniforn distribution in mind
       pos = lo + ((double)(hi-lo)/
             (arr[hi]-arr[lo])*(x-arr[lo]));
  
    // Target is at current position
    if (arr[pos] == x)  
        return pos;
    
    // If x is larger than current position, check upper part of array
    if (arr[pos] < x) 
        lo = pos+1;
    // otherwise check lower
    else 
        hi = pos-1;
    }      
    // Element not found
    return -1;

}


// Driver function
int main()
{
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 16, 21, 55, 89, 144, 223, 317, 610, 720}; 
    int size = sizeof(arr)/sizeof(arr[0]);

    print_array(arr, size);

//    int result = jump_search(arr, 55, size);
    int result = interloper_search(arr, 55, 16);
    (result == -1) ? printf("Element is not in the array\n")
                   : printf("Element was found at index %d\n", result);
                   
    
    
}   