//#hash, #btree
#if 0
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
#endif
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        bool dfs(TreeNode *root, unordered_set<int> &rem, int k){
            bool res = false;
            if(root == NULL) {return false;}
            res |= dfs(root->left, rem, k);
            res |= dfs(root->right, rem, k);

            if(rem.count(root->val)>0){
                return true;
            }else{
                rem.insert(k-root->val);
                return res|false;
            }
        }
        bool findTarget(TreeNode* root, int k) {
            unordered_set<int> remainer;
            bool res;
            res = dfs(root,remainer,k); 
            return res; 
        }
};
int main(){
    return 0;
}
