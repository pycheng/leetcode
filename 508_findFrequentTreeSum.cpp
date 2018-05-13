//#btree
#include <iostream>
#include <unordered_map>
#include <map>
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        vector<int> findFrequentTreeSum(TreeNode* root) {
            int max_cnt=0;
            vector<int> rslt;
            unordered_map<int, int> hash; //(cnt, sum)

            //dfs to contstuct the hash table of subtreesum
            dfs(root, hash, max_cnt);

            for(auto i: hash){
                if(i.second == max_cnt) rslt.push_back(i.first);
                //cout<< max_cnt << "(" << i.first << "," << i.second << "), ";
            }
            return rslt;
        }
    private:
        int dfs(TreeNode* r, unordered_map<int, int>& hash, int& cnt){
            int sum, ls, rs;

            if(r==NULL) return 0;

            ls = dfs(r->left, hash, cnt);
            rs = dfs(r->right, hash, cnt);
            sum = r->val + ls + rs;

            cnt = max(cnt, ++hash[sum]);
            return sum;
        }

};

int main(){
    Solution sol;
    vector<int> rslt;
    struct TreeNode *r=new TreeNode(5);
    struct TreeNode *n1=new TreeNode(2);
    struct TreeNode *n2=new TreeNode(-3);

    r->left = n1;
    r->right = n2;
    rslt = sol.findFrequentTreeSum(r);

    for(auto i: rslt) cout<<i<<",";
    cout << "\n";

    
    return 0;
}

