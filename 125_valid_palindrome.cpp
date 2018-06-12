#include <iostream>
using namespace std;

// the problem define digit and alphabetic as valid item

class Solution {
public:
    bool isPalindrome(string s) {
        int si = 0, ei = s.size()-1;
        while(si < ei){
			//FIXME note that if using while must check string boundary
            if(!isdigit(s[si])&&!isalpha(s[si])) {si++; continue;}
            if(!isdigit(s[ei])&&!isalpha(s[ei])) {ei--; continue;}
            if(tolower(s[si++])!=tolower(s[ei--])) return false;
        }
		cout << si << "," << ei << "\n";
        return true;
    }
};
int main(){
    string t = ".,";
	string t1 = "A man, a plan, a canal: Panama";
    Solution s;

    cout << s.isPalindrome(t);

}
