#if 0
Given n non-negative integers representing the histogram's bar height 
where the width of each bar is 1, find the area of largest rectangle 
in the histogram.
Input: [2,1,5,6,2,3]
Output: 10  
cannot solved by sort e.g., [2,0,2]
#endif
#ifdef __README__
Linear with stack O(n):  largestRectangleArea
Brute Force O(n^2):  largestRectangleArea_BF
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

struct _stack_entry{
    void * ent;
    struct _stack_entry * prv;
    struct _stack_entry * nxt;
};
struct _stack{
    struct _stack_entry * tail;
    int cnt;
};
void _stackpush(struct _stack* s, void* in){
    struct _stack_entry *tmp = malloc(sizeof(struct _stack_entry));
    tmp->ent = in;
    tmp->nxt = NULL;
    tmp->prv = s->tail;
    if(s->tail == NULL){
        s->tail = tmp;
    }else{
        s->tail->nxt = tmp;
        s->tail = tmp;
    }
    s->cnt ++;
}
void * _stackpop(struct _stack* s){
    struct _stack_entry *tmp;
    void* ret;
    if(s->tail == NULL){
        return NULL;
    }
    tmp = s->tail;
    s->tail = s->tail->prv;
    if(s->tail)
        s->tail->nxt = NULL;
    s->cnt --;
    tmp->prv = NULL;
    ret = tmp->ent;
    free(tmp);
    return ret;
}
int _stackempty(struct _stack *s){
    return s->cnt;
}
struct _stack* _stackinit(){
    struct _stack *my_stack = malloc(sizeof(struct _stack));
    my_stack->tail = NULL;
    my_stack->cnt = 0;
    return my_stack;
}
void _stackdel(struct _stack* s){
    struct _stack_entry *tmp;
    if(s==NULL){ return;}
    while(s->tail != NULL){
        tmp = s->tail;
        s->tail = s->tail->prv;
        free(tmp->ent);
        free(tmp);
    }
    free(s); 
}

struct _h {
    int v;
};

int largestRectangleArea(int* heights, int heightsSize) {       
    int rslt = 0;
    int* in = malloc(sizeof(int)*(heightsSize+1));
    struct _stack* stk = _stackinit();
    int i, len, height, stk_top;
    struct _h *entry;

    //set up boundary with padding 0
    memcpy(in, heights, sizeof(int)*heightsSize);
    in[heightsSize] = 0;

    //loop each heights with padding
    for(i=0; i<(heightsSize+1); i++){
        if(stk->tail) 
            stk_top = ((struct _h *)(stk->tail->ent))->v; 
        //printf("%d, \n", stk_top);
        if((stk->tail == NULL) ||
           (in[i] >= in[stk_top])){
            entry = malloc(sizeof(struct _h));
            entry->v = i;
            _stackpush(stk, entry);
            //printf("push %d\n", i);
        }else{
            entry = (struct _h*)_stackpop(stk);
            height = in[entry->v];
            //printf("pop %d height %d \n", entry->v, height);
            free(entry);
            len = (stk->tail == NULL)?i:i-((struct _h*)(stk->tail->ent))->v-1;
            rslt = MAX(rslt, len*height); 
            //printf("rslt[%d] %d\n",i, rslt);
            i--;
        }
    }
    _stackdel(stk);
    return rslt;
}

int largestRectangleArea_BF(int* heights, int heightsSize) {       
    int rslt = 0;
    int i,j;
    int v1 = 0;
    int v2 = 0;

    for(i=0; i<heightsSize; i++){
        v1 = 0; v2 = 0;
        for(j=0; j<heightsSize; j++){
            if(heights[j]>=heights[i]){
                v2++; 
            }else{
                v1 = MAX(v1,v2);
                v2 = 0;
            }
        }
        v1 = MAX(v1,v2);
        rslt = MAX(rslt, heights[i]*v1);
        printf("[%d,%d,%d,%d]%d, ",i,j,v1,v2,rslt);
    }
    return rslt;
}   
int test[] = {2,1,5,6,2,3};
int test1[] = {2,1,2};
int test2[] = {2};
int main(){
    int ret;
    ret = largestRectangleArea(test, 6);
    printf("%d\n", ret);
    return 0;
}
