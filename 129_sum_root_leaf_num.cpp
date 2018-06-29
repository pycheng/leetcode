#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* r, int curr, int &sum){
        if(r==NULL) return; 
        curr = curr*10+r->val;
        if(r->left==NULL && r->right==NULL){
            sum+=curr;
        }
        dfs(r->left,  curr, sum);
        dfs(r->right, curr, sum);
    }
    int sumNumbers(TreeNode* root) {
       int curr = 0;
       int sum  = 0;
       dfs(root, curr, sum); 
       return sum;
    }
};


int main(){
    TreeNode *r, *n;
    r = n = new TreeNode(4);
    n->left = new TreeNode(9);
    n->right = new TreeNode(0);
    n->left->right = new TreeNode(1);
    n->left->left  = new TreeNode(5);
    Solution s;
    cout << s.sumNumbers(r);
}
