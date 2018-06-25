#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> digits2roman = {
		{"" , "I" , "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
		{"" , "X",  "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
		{"" , "C",  "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
		{"" , "M",  "MM", "MMM"}
		 
	};
    string intToRoman(int num) {
		int digit = 0;
		string res = "";
		if(num > 3999) return "invalid";
		while(num > 0){
			res = digits2roman[digit][num%10]+res;
			num /= 10; digit++;
		}
		return res;
    }
};
int main(){
	Solution s;
	cout << s.intToRoman(1994);
}
