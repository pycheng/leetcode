#if 0
Given a string S and a character C, return an array of integers representing the 
shortest distance from the character C in the string
Example 1:Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]        
Note:
1. S string length is in [1, 10000]
2. C is a single character, and guaranteed to be in string S.
3. All letters in S and C are lowercase
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _dump(int* in, int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d, ",in[i]);
    }
    printf("\n");
}

/** 
 * Return an array of size *returnSize
 * Note: The returned array must be malloced, assume caller calls free().
 **/
int* shortestTo_Char(char* S, char C, int* returnSize){
    int *rslt = NULL;
    int len;
    int match,i;
    int dft = -99999; // > stringlen

    len = strlen(S);
    *returnSize=len;
    rslt = (int *)malloc(sizeof(int)*len);
    memset(rslt, 0, sizeof(int)*len);

    match = dft;
    for(i=0; i<len; i++){
        if(S[i]==C){
            match = i;
        }
        rslt[i] = i-match;
    }
    _dump(rslt, len);
    match = -dft;
    for(i=len-1; i>=0; i--){
        if(S[i]==C){
            match = i;
        }
        rslt[i] = (rslt[i]<(match-i))?rslt[i]:(match-i);
    }
    _dump(rslt, len);
    return rslt;
}
int* shortestTo_Char_stupid(char* S, char C, int* returnSize) 
{    
    int *rslt = NULL;
    int rslt_idx = 0;
    int idx1=-1;
    int idx2=-1;
    int i,j,len;
    
    len = strlen(S);
    *returnSize=len;
    rslt = (int *)malloc(sizeof(int)*len);
    memset(rslt, 0, sizeof(int)*len);

    for(i=0; i<len; i++){
        if(S[i]==C){
            idx2 = idx1;   //idx2 prev
            idx1 = i;      //idx1 curr
            printf("[%d](%d,%d,%d)\n", i, rslt_idx, idx1, idx2); 

            for(j=rslt_idx;j<=idx1;j++){
                if(idx2==-1){
                    rslt[j]= (idx1-j);
                }else{
                    rslt[j]= ((j-idx2)<(idx1-j))?(j-idx2):(idx1-j);
                }
            }
            rslt_idx = idx1+1;
        }
    }

    printf("[%d](%d,%d,%d)%d\n", i, rslt_idx, idx1, idx2,len); 
    if(rslt_idx<len){
        for(j=rslt_idx;j<len;j++){
            rslt[j] = rslt[j-1]+1;
        }
    }
    return rslt;
}   
int main(){
//    char s[20]="loveleetcode";
//    char c='e';
//    char s[5]="baab";
//    char s[5]="aaba";
    char s[5]="abba";
    char c='b';
    int* ret;
    int len,i;
    ret = shortestTo_Char(s,c,&len);
    for(i=0; i<len; i++){
        printf("%d, ",ret[i]);
    }
    printf("\n%d\n",len);
    free(ret);
    return 0;
}
