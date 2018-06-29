#include <iostream>
#include <limits.h>
using namespace std;

// The difference of node can be defined by curr-curr_max 
// The curr_max can be retrived by travrse the BSTin increasing order 
// Thus, in order travese can help to do the trace the BST in increasing order
// Time complexity: O(n) 
// Space complexity: O(logn)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* curr_max;
public:
    Solution():curr_max(NULL){}
    void inorder(TreeNode* root, int& min_diff){
        if(!root) return;

        inorder(root->left, min_diff);

        if(curr_max) min_diff = min(min_diff, abs(root->val - curr_max->val));
        curr_max = root;

        inorder(root->right, min_diff);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
       int min_diff = INT_MAX;
       
       inorder(root, min_diff);
       return min_diff;
    }
};

int main(){
    TreeNode *r, *n;
    r = n = new TreeNode(5);
    n->left = new TreeNode(4);
    n->right= new TreeNode(7);

    Solution s;
    cout << s.getMinimumDifference(r);
}

