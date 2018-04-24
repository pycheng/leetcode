/*
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *You may assume that each input would have exactly one solution, and you may not use the same element twice.
 *Example:
 *  Given nums = [2, 7, 11, 15], target = 9,
 *  Because nums[0] + nums[1] = 2 + 7 = 9,
 *  return [0, 1].
 */
#if 0
    20180424 the time complexity of thie method is O(n^2).
    Using the hash table can enhance the speed.
#endif


#include "stdio.h"
#include "stdlib.h"

int test_size = 4;
int test_nums[4] = {2, 7, 11, 15};
int test_target = 9;


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int a, b;
    int *rslt = malloc(sizeof(int)*2);
    rslt[0] = 0; rslt[1] = 0;
    if(numsSize < 1) return rslt;    
    for(a=0; a < numsSize; a++){
        //Ian: be careful you cannot use the same element twice
        for(b=a+1;b < numsSize; b++){
            if (nums[a] + nums[b] == target){
                rslt[0] = a;
                rslt[1] = b;
                //printf("match %d, %d \n", rslt[0], rslt[1]);
                return rslt;
            }
        }
    }
    return rslt;
}

void main(){
    int* test;
    test = twoSum(test_nums, test_size, test_target);
    //printf("%d \s", sizeof(test_nums)/sizeof(int));
    printf("%d, %d \n", test[0], test[1]);
    return;
}
