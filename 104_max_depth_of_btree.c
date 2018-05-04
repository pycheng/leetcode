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

int maxDepth(struct TreeNode* root) {
    int left_depth = 0;
    int right_depth = 0;
    if(root == NULL) { return 0; }
    if(root->left!=NULL){
        left_depth += maxDepth(root->left);
    }
    if(root->right!=NULL){
        right_depth += maxDepth(root->right);
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
