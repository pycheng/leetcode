#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Solution 1. comparing horizontally
//  Time complexity O(s) s is sum of all characters in all strings 
//  Space complexity O(1)
//Solution 2. comapring vertically
//  Time complexity O(s) s is sum of all characters in all strings
//  Space complexity O(1)
//Solution 3. binary search in 1st element 
//  Time complexity O(s*log(m)) m is length of 1st element
//  Space complextiy O(1)
//Sotluion 4. recursively
//  Time complexity O(s)
//  Space complexity O(k*log(n))  
//          n is number of string
//          k is longest string len for stack buffering
//Solution 5. Trie
//  Time complexity O(C)  C is total number of character
//  Space complexity O(C)
//Solution 6. Sorting and compare 1st and last
//  Time complexity O(slogs)
//  Space complexity O(1)

class Solution {
public:
	//option 2
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.size()<1) return "";
		string res = "";
		for(int i=0; i<strs[0].size(); i++){
			char cur = strs[0][i];
			for(int j=1; j<strs.size(); j++){
				if(strs[j][i] != cur) return res;
			}
			res+=cur;
		}
		return res;
    }
    string longestCommonPrefix_option6(vector<string>& strs) {
		if(strs.size()<1) return "";
		sort(strs.begin(), strs.end());
		string head = strs[0];
		string tail = strs[strs.size()-1];
		for(int i=0; i<head.size(); i++){
			if(head[i] != tail[i]) return head.substr(0, i);
		}
		return head;
	}
};

int main(){
	Solution s;
    vector<string> t = {"czr", "cbs", "ca"};
	cout << s.longestCommonPrefix(t) << "\n";
	

    sort(t.begin(), t.end());

    for(auto i:t){
        cout << i << ",";
    }
}
