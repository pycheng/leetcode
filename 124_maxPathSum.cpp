//#btree, #gps
#include <iostream>
#include <climits>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        int dfs(TreeNode *r, int &vmax){
            int vr=0, vl=0;
            int max_sub;

            if(r==NULL){
                return 0;
            }
            vl=max(dfs(r->left, vmax),0);
            vr=max(dfs(r->right,vmax),0);
            vmax = max(vmax, r->val+vr+vl);
            //cout << vmax << "\n"; 
            return max(vr,vl)+r->val; 
        }
        int maxPathSum(TreeNode* root) {
            //watch out if tree = [-3] ;
            int rslt=INT_MIN;
            dfs(root, rslt);
            return rslt;
        }
};
TreeNode * init(){
#if 0
    TreeNode *n1 = new TreeNode(-10);
    TreeNode *n2 = new TreeNode(9);
    TreeNode *n3 = new TreeNode(20);
    TreeNode *n4 = new TreeNode(15);
    TreeNode *n5 = new TreeNode(7);
    
    n1->left  = n2;
    n1->right = n3;
    n3->left  = n4;
    n3->right = n5;

    //case 1: node itself is local max
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(-1);
    n1->left  = n2;
#else
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(8);
    TreeNode *n4 = new TreeNode(11);
    TreeNode *n5 = new TreeNode(13);
    TreeNode *n6 = new TreeNode(4);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(2);
    TreeNode *n9 = new TreeNode(1);
    n1->left  = n2;
    n1->right = n3;
    n2->left  = n4;
    n4->left  = n7;
    n4->right = n8;
    n3->left  = n5;
    n3->right = n6;
    n6->right = n9;
#endif
    return n1;
}

int main(){
    Solution s;
    int rslt;
    TreeNode *t;
    t = init();

    rslt = s.maxPathSum(t);
    cout << rslt;
    return 0;
}
