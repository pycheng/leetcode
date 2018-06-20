//#btree, #gps
//watch out the [] tree case
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * Definition for a binary tree node.
 */
class Solution {
    public:
        int dfs(TreeNode *r, int& vmax){
            if(r==NULL) return 0;
            int vr, vl;
            vr = dfs(r->right, vmax);
            vl = dfs(r->left , vmax);
            vr = (r->right && r->right->val == r->val)?vr:0;
            vl = (r->left  && r->left->val  == r->val)?vl:0;
            vmax = max(vmax, vr+vl+1);
            return max(vr,vl)+1;
        }
        int longestUnivaluePath(TreeNode* root) {
            int rslt = 0;
            dfs(root,rslt);
            return max(0,rslt-1);
        }
};


void init_tree(TreeNode *root){
    struct TreeNode *n = new TreeNode(0);
    return;
}
int main(){
    Solution s;
    cout << s.longestUnivaluePath(NULL);
    return 0;
}
#if 0 
tree version
//https://leetcode.com/articles/longest-univalue-path/#
#include <iostream>
#include <vector>
#include <limits.h> //INT_MIN 
#include <set>
using namespace std;


struct TN{
    int v;
    vector<struct TN> c;
    TN(int i){
        v = i;
    };
    TN(){
        v = INT_MIN;
    }
};

class Solution{
    public:
        struct TN* init_tree(vector<int>a, vector<int>e, vector<struct TN> &t){
            for(int i=0; i<a.size(); i++){
                t[i].v = a[i];
            }
            for(int i=0; i<e.size(); i+=2){
                t[e[i]-1].c.push_back(t[e[i+1]-1]);
            }
        }
        int dfs(struct TN * r, int &vmax){
            vector<int> vl(r->c.size());//vl = max path of right.v;

            if(r==NULL) return 0;
            for(int i=0; i<r->c.size(); i++){
               vl[i] = dfs(&r->c[i], vmax);
               vl[i] = (r->c[i].v == r->v)? vl[i]:0;
            }
            
            int sumvl = 0, maxvl = 0;
            
            for(auto i:vl){
                sumvl+= i;
                maxvl = max(maxvl, i);
            }

            vmax = max(vmax, sumvl+1); 

            return maxvl+1; 
        }
        int mp(vector<int> a, vector<int>e){
            vector<struct TN> t(a.size());
            int rslt; 
            //int tree from e
            init_tree(a,e,t);
            //dfs the tree
            dfs(&t[0], rslt);
            //return max path
            return rslt-1;
        }
};

int main(){
    vector<int> a ={1,1,1,2,2};
    vector<int> b ={1,2,1,3,2,4,2,5};
    Solution s;
    cout << s.mp(a, b);
    return 0;
}
#endif
