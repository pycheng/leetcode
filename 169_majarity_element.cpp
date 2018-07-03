#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		if(nums.size() <= 0) return -1;
        int maj = nums[0];
		int count = 1;
		for(int i = 1; i<nums.size(); i++){
            if(nums[i] == maj) count++;
            else{
                if(--count == 0){
                    maj = nums[i];
                    count = 1;
                }
            }
		}
        return maj;
    }
};


int main(){
    Solution s;
    vector<int> nums = {3,2,3};
    cout << s.majorityElement(nums); 
}
