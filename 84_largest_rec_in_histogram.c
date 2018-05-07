#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct _h{
    int v;
};

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


int largestRectangleArea(int *heights, int heightsSize){
    int rslt = 0;
    int i, v;
    int *in = malloc(sizeof(int)*(heightsSize+1));
    struct _stack *stk;    
    struct _h *curr = NULL;
    //void _stackpush(struct _stack* s, void* in)

    stk = _stackinit();
    memcpy(in, heights, sizeof(int)*heightsSize);
    in[heightsSize] = 0;

    for(i = 0; i<(heightsSize+1); i++){
        if((stk->tail == NULL) || in[i] > in[((struct _h*)stk->tail->ent)->v]){
            curr = malloc(sizeof(struct _h));
            curr->v = i; 
            _stackpush(stk, curr);
            printf("push %d \n",i );
        }else{
            curr = _stackpop(stk);
            v = ((struct _h*)curr)->v;
            printf("pop %d\n", v);
            free(curr);
            rslt = MAX(rslt, in[v]*((stk->tail == NULL)? i:i-((struct _h*)stk->tail->ent)->v-1));
            v=-99;
            if(stk->tail) v = ((struct _h*)stk->tail->ent)->v;
            printf("rslt[%d,%d] %d\n\n", i, v, rslt);
            i--;
        }

    }

    free(stk);
    printf("%d", rslt);
    return rslt;
}

int test[] = {2,1,5,6,2,3};
int test1[] = {2,2};
int test2[] = {1,3,2,3};
int main(){
    largestRectangleArea(test2, 4);
    return 0;
}
