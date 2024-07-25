/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].

Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    // select the bigger and smaller array size
    int maxSize, minSize, *maxArray, *minArray;
    if (nums1Size > nums2Size) {
        maxSize = nums1Size;
        minSize = nums2Size;
        maxArray = nums1;
        minArray = nums2;
    } else {
        maxSize = n;
        minSize = m;
    }

    // check values
    printf("maxSize: %d, minSize: %d\n");
    printf("maxArray:");
    for (int i = 0; i < maxSize; i++)
    {
        printf(" %d,", maxArray[i]);
    }
    printf("\nminArray:");
    for (int i = 0; i < minSize; i++)
    {
        printf(" %d,", minArray[i]);
    }

    // allocate result array
    int *result = (int*)malloc((maxSize + minSize) * sizeof(int));

    // start sorting until we reach smaller size
    int j = 0, i = 0, k = 0;
    while (j < minSize && i < maxSize)
    {
        if (minArray[j] < maxArray[i]) {
            result[k] = minArray[j];
            j++;
            k++;
        }
        else {
            result[k] = maxArray[i];
            i++;
            k++;
        }
    }
    
    // put in the remaining numbers
    if (j == minSize - 1) {
        for (int x = i; x < maxSize; x++)
        {
            result[k] = maxArray[x];
        }
    }
    else {
        for (int x = j; x < minSize; x++)
        {
            result[k] = minArray[x];
        }
    }

    printf("result: ");
    for (int i = 0; i < minSize + maxSize; i++)
    {
        printf("%d, ", result[i]);
    }
    
}

int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    return 0;
}