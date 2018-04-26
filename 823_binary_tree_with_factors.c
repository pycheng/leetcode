#if 0
Given an array of unique integers, each integer is strictly greater than 1.

We make a binary tree using these integers and each number may be used for any number of times.

Each non-leaf node's value should be equal to the product of the values of it's children.

How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.
#endif
//fmod build with $gcc file -lm 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sort(int *A, int ASize){
    int i,j;
    int v1=0, v2;

    while(v1 == 0){
        v1 = 1;
        for(i=0; i<ASize-1; i++){
            if (A[i] > A[i+1]){
                v1 = 0;
                v2 = A[i];
                A[i] = A[i+1];
                A[i+1] = v2;
            }
        }
//#        for(j=0; j<ASize; j++){
//#            printf("%d, ", A[j]);
//#        }
//#        printf("\n");
    }
}
int isvinA(int *A, int Asz, int v, int* idx){
    int i;
    for(i =0 ; i<Asz; i++){
        if(A[i] == v){ *idx = i; return 1;}
    }
    return 0;
}


int numFactoredBinaryTrees(int* A, int ASize) {
    double fbtcnt[1000] = {0}; //to prevent overflow error
    int i,j, rslt;
    int root, c1, c2;
    int i_root, i_c1, i_c2;

    sort(A,ASize);
    for (i=0; i < ASize; i++){
        root = A[i];
        i_root = i;
        fbtcnt[i_root]++;
        for(j=0; j < ASize; j++){
            c1 = A[j];
            i_c1 = j;
            if( root % c1 ==0){
                c2 = root/c1;
            }else{
                c2 = 0;
                continue; //to prevent timeout error
            }
            //printf("[%d,%d,%d]-->",root,c1,c2);
            if(1==isvinA(A,ASize,c2,&i_c2)){
                //printf("hit");
                fbtcnt[i_root]+=fbtcnt[i_c1]*fbtcnt[i_c2];
                fbtcnt[i_root]=fmod(fbtcnt[i_root],(double)1000000007);
            }
            //printf("\n");
        }
    }
    rslt = 0;
    for(i=0;i<1000;i++){
        rslt+=fbtcnt[i];
        rslt %= 1000000007;
    }
    return rslt % 1000000007;
}


int main(){
    int ret, i;
    int A[4] = {18,3,6,2};
    int sz = 4;
    for(i=0; i<sz; i++){
        printf("%d, ", A[i]);
    }
    ret = numFactoredBinaryTrees(A, sz);
    printf("%d",ret);
    return 0;
}

