#include <iostream> 
#include <math.h>
#include <set>
#include <unordered_set>
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
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum_k = 0;
        long long max_sum_k;
        for(int i = 0; i < nums.size(); i++){
            if(i <= k-1){
                sum_k += nums[i];
                max_sum_k = sum_k;
            }else{
                sum_k = sum_k + nums[i] - nums[i-k];
                max_sum_k = max(max_sum_k, sum_k);
            }
        }
        return (double)max_sum_k/k;
    }
};
//Input: [1,12,-5,-6,50,3], k = 4
//Output: 12.75

int main(){
	Solution s;
	vector<int> v = {1,12,-5,-6,50,3};
	cout << s.findMaxAverage(v, 4);
}

