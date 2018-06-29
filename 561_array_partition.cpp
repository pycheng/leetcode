#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
Given an array of 2n integers, your task is to group these integers into n pairs of integer, 
say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n 
as large as possible.
Example 1:
Input: [1,4,3,2]
Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

min(a1, b1) + min(a2, b2) = max
2*min(a1, b1) = 2*a1 = (a1+b1)-abs(a1-b1)
Thus we want abs(a1-b1) as small as possible --> sort and group pair from the head
#endif
//time complexity = O(nlogn)
//space complexity = O(1)
// if the range of nums are defined, we can store the array in a big size of array 
// index by the nums[i] and iterate through the array and sum the odd numbers;
// Thus O(n) with O(m) space complexity, m = possible number of nums[i]
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
		int sum = 0;
 		sort(nums.begin(), nums.end());
		for(int i = 0; i<nums.size(); i+=2)
		{
			sum += nums[i];
		}
		return sum;
    }
};

int main(){
	Solution s;
	vector<int> t = {1,2,3,4};
	cout << s.arrayPairSum(t);
	return 1;
}
