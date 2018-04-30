#if 0
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
Note: Given n will be a positive integer.
#endif
#include <stdio.h>
#include <stdlib.h>


int climbStairs(int n){
    int rslt = 0;
    int rslt_1=0;
    int rslt_2=0;
    int i;
    for(i=1; i<=n; i++){
        if(i==1){
            rslt = 1;
        }else if(i==2){
            rslt = 2;
            rslt_1=2;
            rslt_2=1;
        }else{
           rslt = rslt_1+ rslt_2;
           rslt_2 = rslt_1;
           rslt_1 = rslt;
        }
        //printf("(%d,%d,%d) ", rslt, rslt_1, rslt_2);
    }
    return rslt;
}
int climbStairs_rec(int n){
    int rslt = 0;
    if (n<=0){
        rslt = 0;
    }else if(n==1){
        rslt = 1;
    }else if(n==2){
        rslt = 2;
    }else{
        rslt += climbStairs(n-1);
        rslt += climbStairs(n-2);
    }
    return rslt;
}

int main(){
    int ret = climbStairs(4);
    printf("%d", ret);
    return 0;
}

