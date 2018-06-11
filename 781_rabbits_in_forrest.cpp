#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// every unique number in the answers means there's number+1 rabbits with that color
// Time complexity: O(n) insert to hash 
// Space complexity: O(n) hash
#if 0
For rabits with same colors, the answers must be the same. 
However, when the total amount of that same answer exceeds  'that answer + 1', there must be a new color. 
(say [3,3,3,3,3], the first four 3s indicates 4 rabits with the same color. 
  The 5th 3 must represent a new color that contains 4 other rabits). 
 We only calculate the amount of rabits with the same color once. 
 Hashmap is used to record the frequency of the same answers. 
 Once it exceeds the range, we clear the frequency and calculate again.
#endif
class Solution {
public:
    int numRabbits(vector<int>& answers) {
  		unordered_map<int, int> hash;
        if(answers.size() == 0) return 0;
		for(auto i:answers) hash[i]++;
		int res=0;
		for(auto i:hash) res+=(i.first+i.second)/(i.first+1)*(i.first+1);
		return res;		      
    }
};


int main(){
	vector<int> t0 = {1,1,2}; //5
	vector<int> t1 = {10,10,10}; //10
	vector<int> t2 = {0,1,0,1,0}; //5
	Solution s;
	cout << s.numRabbits(t0) << "\n";
	cout << s.numRabbits(t1) << "\n";
	cout << s.numRabbits(t2) << "\n";

}
