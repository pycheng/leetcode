#if 0
Given a binary tree, find its maximum depth
The maximum depth is the number of nodes along the longest path from 
the root node down to the farthest leaf node
Note: A leaf is a node with no children
Example:Given binary tree [3,9,20,null,null,15,7],
return its depth = 3
5,
0,-4,
-1,-6,-9,null,
7,null,1,3,null,0,null,9,
null,null,6,0,null,-7,null,null,null,null,null,null,-4,null,1,null,
null,-4
#endif
#ifdef __README__
BFS with stack version: maxDepth
recursive version: maxDepth_rec 
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/** 
 * Definition for a binary tree node. 
 * struct TreeNode {
 *      int val; 
 *      struct TreeNode *left; 
 *      struct TreeNode *right; 
 * }; 
 **/
struct TreeNode {
      int val; 
      struct TreeNode *left; 
      struct TreeNode *right; 
}; 

// non recursive solution can be implemented in 
// DFS with queue
// BFS with stack
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
struct tn{
    struct TreeNode* n;
    int d;
};

int maxDepth(struct TreeNode* root) {
    int rslt = 0;
    struct _stack *stk; 
    struct tn *t;
    int curr_dep;
    struct TreeNode* curr_node;

    if(root == NULL) return 0;

    stk = _stackinit();
   
    t = malloc(sizeof(struct tn));
    t->n = curr_node = root;
    t->d = curr_dep = 1;
    _stackpush(stk,t);

    while(_stackempty(stk) != 0){
       t = (struct tn*)_stackpop(stk);
       rslt = (rslt > t->d)?rslt:t->d;
       curr_node = t->n;
       curr_dep  = t->d+1;
       free(t);
       
       if(curr_node->left != NULL){
           t = malloc(sizeof(struct tn));
           t->n = curr_node->left;
           t->d = curr_dep;
           _stackpush(stk, t);
       }

       if(curr_node->right != NULL){
           t = malloc(sizeof(struct tn));
           t->n = curr_node->right;
           t->d = curr_dep;
           _stackpush(stk, t);
       }
    }
    _stackdel(stk);
    return rslt;
}

//recursive version
int maxDepth_rec(struct TreeNode* root) {
    int left_depth = 0;
    int right_depth = 0;
    if(root == NULL) { return 0; }
    if(root->left!=NULL){
        left_depth = maxDepth(root->left);
    }
    if(root->right!=NULL){
        right_depth = maxDepth(root->right);
    }
    int rslt = (left_depth > right_depth)?left_depth:right_depth;
    rslt ++;
    //printf("%d\n", rslt);
    return rslt;
}

void add_node(int l, int r, struct TreeNode *p){
    struct TreeNode *n;
    if(l>0){
        n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        n->left = NULL;
        n->right = NULL;
        n->val = l;
        p->left = n;
    }
    if(r>0){
        n = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        n->left = NULL;
        n->right = NULL;
        n->val = r;
        p->right = n;
    }
}

void init_bt(struct TreeNode* root){
    root->val = 3;
    add_node(9,20,root);
    add_node(15,7,root->right);
}

void del_bt(struct TreeNode *r){
}

int main(){
    struct TreeNode* test;
    int ret =0;

    test = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    init_bt(test);

    ret = maxDepth(test);
    printf("%d", ret);

    del_bt(test);

    return 0;
}
