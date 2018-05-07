#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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

#if 0
struct _t{
    int v;
};

int main(){
    struct _stack *tmp;
    struct _t *t;
    int i;

    

    tmp = _stackinit();

    printf(" 1\n");
    for(i = 0; i<10;i++){
        t = malloc(sizeof(struct _t));
        t->v = i;
        _stackpush(tmp, (void*) t);
    }
    
    printf(" 2\n");
    for(i = 0; i<10;i++){
        t = (struct _t*)_stackpop(tmp);
        printf("%d,", t->v);
    }

    printf(" 3\n");
    _stackdel(tmp);
    printf("\n");
    return 0;
}
#endif
