#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(const vector<int>& nums) {
       if(nums.size()==0) return 0;
       int max_sum = nums[0];
       int run_sum = max_sum;
       for(int i = 1; i<nums.size(); i++){
           run_sum = max(nums[i], run_sum+nums[i]);
           max_sum = max(max_sum, run_sum);
       }
       return max_sum;
    }
};

int main(){
    Solution s;
    cout << s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4});
}
