#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
  		int carry = 0;
		if(digits.size()==0){
			digits.push_back(1);
			return digits;
		}
		digits[digits.size()-1] += 1;
		for(int i = digits.size()-1; i>=0; i--){
			int buf = digits[i] + carry;
			digits[i] = buf%10;
			carry = buf/10;
		}
		if(carry != 0){
			vector<int> res(1,carry);
			for(auto i:digits) res.push_back(i);
			return res;
		}
      	return digits;
    }
};

int main(){
	Solution s;
	vector<int> res={9,9,9};
	res = s.plusOne(res);
	for(auto i:res) cout << i << ",";
	cout << "\n";

	res = {1,9,9};
	res = s.plusOne(res);
	for(auto i:res) cout << i << ",";
	cout << "\n";
}
