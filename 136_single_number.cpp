// bm
#include <iostream>
#include <vector>
using namespace std;

#if 0
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
Example 1:
Input: [2,2,1]
Output: 1
Example 2:
Input: [4,1,2,1,2]
Output: 4
#endif

// this is a bit manipulation problem for xor
// 0^0 = 0
// i^i = 0
// xor has a memory form
// time complexity = O(n) space complexity O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		if(nums.size() == 0) return -1;
		unsigned long long buff = 0;
		for(auto i: nums){
			buff^=i;
		}        
		return (buff!=0)?buff:0;
    }
};
int main(){
	Solution s;
	vector<int> t = {4,1,2,1,2};
	cout << s.singleNumber(t); //4
}
