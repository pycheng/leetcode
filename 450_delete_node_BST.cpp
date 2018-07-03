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
     TreeNode* deleteNode(TreeNode* root, int key) {
         cout << (void*) root << "," << key << "\n";
         if(root==NULL) return root;
         //find the key node
         if(key < root->val){
             root->left  = deleteNode(root->left, key);
         }else if(key > root->val){
             root->right = deleteNode(root->right, key);
         }else{
             if(root->left == NULL && root->right == NULL){
                 //case 1 key_node->left==NULL && key_node->right==NULL
                 delete root;
                 return NULL;
             }else if(root->left == NULL || root->right == NULL){
                 //case 2 key_node->left==NULL --> return right_subtree root;
                 //case 3 key_node->right==NULL -->return left_subtree root;
                 TreeNode* new_root = (root->right)?root->right:root->left;
                 delete root;
                 return new_root;
             }else{
                 //case 4 both left and right subtree existed
                 //          find the min_val of right subtree (i.e. left most node)
                 //          deleteNode(min_val_node, min_val);
                 //          key_node->val = min_val;
                 //          return key_node
                 TreeNode *min_right = root->right;
                 //cout << "root: " << root->val << "\n";
                 while(min_right->left) min_right = min_right->left;
                 root->val = min_right->val;
                 //cout << "min_right: " << min_right->val << "\n";
                 root->right = deleteNode(root->right, min_right->val);
             }
         }
         cout << "return: " << (void*) root << "\n";
         return root;
     }
};

int main(){
    TreeNode* r = new TreeNode(5);
    r->left = new TreeNode(3);
    r->left->left = new TreeNode(2);
    r->left->right = new TreeNode(4);
    r->right = new TreeNode(6);
    r->right->right = new TreeNode(7);
    Solution s;
    TreeNode *res = s.deleteNode(r, 3);
    cout << res->val << "\n";
    cout << res->left->val << res->right->val << "\n";



}
