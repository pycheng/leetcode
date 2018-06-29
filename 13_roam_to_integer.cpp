#include <iostream>
using namespace std;

//go from tail to head
//tail digit is positive
//if s[i] < s[i+1]  s[i] is negative
//if s[i] > s[i+1]  s[i] is positive
//if s[i] == s[i+1]  s[i]'s signed is the same as s[i+1]
class Solution {
public:
    int rc2int(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5; 
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
        return 0;
    }
    int romanToInt(string s) {
        int res = rc2int(s[s.size()-1]);
        bool neg = false;
        for(int i=s.size()-2; i>=0; i--){
            int cur = rc2int(s[i]);
            int prv = rc2int(s[i+1]);
            if(cur > prv){
                neg=false;
            }else if(cur < prv){
                neg=true;
            }
            res+=(neg?-1:1)*cur;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.romanToInt("CMXI");
}
