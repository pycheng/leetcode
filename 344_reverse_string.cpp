#include <iostream>
using namespace std;

//time complexity O(n)
//space complexity O(1)

class Solution {
public:
    string reverseString(string s) {
  		for(int i = 0, j = s.size()-1; i<j; i++,j--){
			swap(s[i], s[j]);
		}      
		return s;
    }
};


int main(){
	Solution s;
	cout<< s.reverseString("abcdefgh");
}
