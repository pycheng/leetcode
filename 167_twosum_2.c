#if 0
Given an array of integers that is already sorted in ascending order, 
find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
#endif

#include "stdio.h"
#include "stdlib.h"

int test_size = 3;
int test_nums[3] = {2, 3, 4};
int test_target = 6;
int test_ret_size = 0;


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int* rslt = malloc(sizeof(int)*2);
    *returnSize = 2;
    rslt[0] = 1; rslt[1] = 1;
    if(numbersSize < 1) return rslt;

    //watch out the index traisition
    for (rslt[0]=1; rslt[0] <= numbersSize; rslt[0]++){
        for(rslt[1]=rslt[0]+1; rslt[1] <= numbersSize; rslt[1]++){
            //printf("(%d,%d)=%d\n", rslt[0], rslt[1], numbers[rslt[0]-1] + numbers[rslt[1]-1]);
            if (numbers[rslt[0]-1] + numbers[rslt[1]-1] == target){
                //printf("hit\n");
                return rslt;
            }
        }
    }
    rslt[0] = 1; rslt[1] = 1;
    return rslt;
}


void main(){
    int* test;
    test=twoSum(test_nums, 4, test_target, &test_ret_size);
    printf("%d, %d\n", test[0], test[1]);
    free(test);
    return;
}

