#if 0
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number 
and for the multiples of five output “Buzz”. 
For numbers which are multiples of both three and five output “FizzBuzz”.
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** rslt;
    char buf[10];
    int i;

    rslt = (char **)malloc(sizeof(char*)*n);
    *returnSize = n;

    for(i=0; i<n; i++){
        memset(buf, 0, sizeof(buf));
        if((i+1)%3 == 0){
           strcat(buf, "Fizz"); 
        }
        if((i+1)%5 ==0){
           strcat(buf, "Buzz"); 
        }
        if((i+1)%3!=0 && (i+1)%5!=0){
            sprintf(buf,"%d",i+1);
        }
        rslt[i] = (char*)malloc(sizeof(char)*(strlen(buf)+1));
        memset(rslt[i], 0, sizeof(char)*(strlen(buf)+1));
        memcpy(rslt[i], buf, sizeof(char)*(strlen(buf)));
    }
    return rslt;
}


int main(){
    
    char** ret;
    int rtsize, i;

    ret = fizzBuzz(15, &rtsize);
    for(i=0; i<rtsize; i++){
        printf("%s, ",ret[i]);
        free(ret[i]);
    }
    printf("\n");
    return 0;
}

