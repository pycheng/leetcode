#if 0
On a table are N cards, with a positive integer printed on the front and back of each card (possibly different)
We flip any number of cards, and after we choose one card.
If the number X on the back of the chosen card is not on the front of any card, then this number X is good.
What is the smallest number that is good?  If no number is good, output 0
Here, fronts[i] and backs[i] represent the number on the front and back of card i.       
A flip swaps the front and back numbers, so the value on the front is now on the back and vice versa

Example:Input: fronts = [1,2,4,4,7], backs = [1,3,4,1,3] Output: 2
Explanation: If we flip the second card, the fronts are [1,3,4,4,7] and the backs are [1,2,4,1,3]
[We choose the second card, which has number 2 on the back, 
and it isn't on the front of any card, so 2 is good.]       
Note:
1 <= fronts.length == backs.length <= 1000
1 <= fronts[i] <= 2000.
1 <= backs[i] <= 2000.
If a card has the same value x on the front and back, it is impossible to win with x. 
Otherwise, it has two different values, and if we win with x, we can put x face down on the rest of the cards.
#endif
#include <stdio.h>
#include <stdlib.h>
#if 0
void swap(int *src, int *dst){
    int tmp;
    tmp = *src;
    *src = *dst;
    *dst = tmp;
}

void _dump(int *a, int *b, int s, int e){
    int i;
    for(i=s; i<e; i++){
        printf("(%d,%d),", a[i], b[i]);
    }
    printf("\n\n");
}

int _part(int *a, int *b, int s, int e){
    int pvt = e;
    int i = s;
    int j = e-1;

    //printf("(%d,%d)\n ",s,e);
    while(i<j){
        //printf("\t-(%d,%d,%d)\n ",i,j,pvt);
        //printf("\t--(%d,%d,%d)\n ",a[i],a[j],a[pvt]);
        if(a[i] <= a[pvt]){
            i++;
        }else if(a[i] > a[pvt]){
            swap(&a[i], &a[j]);
            swap(&b[i], &b[j]);
            j--;
        }
    }
    swap(&a[i], &a[pvt]);
    swap(&b[i], &b[pvt]);
    pvt = i;
    //printf("(%d,%d,%d)\n ",s,pvt,e);
    return i;
}

void _qs(int *a, int *b, int s, int e){
    int pvt;

    if(s==e-1){
        if(a[s] > a[e]){
            swap(&a[s], &a[e]);
            swap(&b[s], &b[e]);
        }
        return;
    }
    if(s<e) {
        pvt = _part(a,b,s,e);
        _qs(a,b,s,pvt-1);
        _qs(a,b,pvt,e);
    }
    return;
}
int flipgame(int* fronts, int frontsSize, int* backs, int backsSize) {
    int rslt = 0;
    int rslt_val = 9999;
    int i;

    //_qs(backs,fronts,0,backsSize-1);

    for(i=0; i<backsSize; i++){
        if(0 == isbina(backs[i], fronts, frontsSize) &&
           backs[i]<rslt_val){
            rslt_val = backs[i];
            rslt = i;
        }
    }

    //return (rslt_val==9999)?0:fronts[rslt];
    return (rslt_val==9999)?0:backs[rslt];
}   

void quick_sort(int *a, int *b, int sz){
    _qs(a,b,0,sz-1);
    return;
}   
#endif

int isbina(int b, int *a, int sz_a){
    int i;

    for(i=0;i<sz_a;i++){
        if(b == a[i]){
            return 1;
        }
    }
    return 0;
}
int flipgame(int* fronts, int frontsSize, int* backs, int backsSize) {
    int rslt = 9999;
    int i;
    int same[1000]={0};
    int samelen = 0;

    for(i=0;i<frontsSize;i++){
        if(fronts[i] == backs[i]){
            same[samelen] = fronts[i];
            samelen++;
        }
    }
    
    for(i=0;i<frontsSize;i++){
        if(fronts[i] < rslt && 0==isbina(fronts[i], &same[0], samelen)){
            rslt = fronts[i];
        }
    }

    for(i=0;i<backsSize;i++){
        if(backs[i] < rslt && 0==isbina(backs[i], &same[0], samelen)){
            rslt = backs[i];
        }
    }

    return (rslt==9999)?0:rslt;
}
#define SZ 2

int main(){
    int fc[SZ] = {2,1};
    int bc[SZ] = {1,2};
    //int fc[SZ] = {9,4,14,4,7};
    //int bc[SZ] = {9,4,14,4,7};
    //int fc[SZ] = {1,2,4,4,7};
    //int bc[SZ] = {1,3,4,1,3};

    int ret = 0;
    ret = flipgame(&fc[0], SZ, &bc[0], SZ);
    printf("%d",ret);

    //quick_sort(&fc[0], &bc[0], SZ);


    return 0;
}
