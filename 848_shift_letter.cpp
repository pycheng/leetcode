#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
       string res = "";
       //runing sum of shift backward
       //Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times
       vector<int> mod_s = shifts;
       int run_sum = 0;
       for(int i = mod_s.size()-1; i>=0 ; i--)
       {
           run_sum+=mod_s[i]%('z'-'a'+1); //FIXME watch out the run_sum overflow 
           mod_s[i]=run_sum;
       }
       //perform the string shift
       for(int i= 0 ;i<S.size(); i++){
           unsigned int t = S[i]+ mod_s[i]%('z'-'a'+1); //FIXME watch out the char overflow 
           // prevent to overflow the char (unsigned int)
           //wrap around
           if(t > 'z') t = 'a' + (t-'a')%('z'-'a'+1);
           //S[i]=t;
           res+=t;
       }
       return res;
    }
};

int main(){
    Solution s;
    vector<int> t = {3,5,9};
    cout << s.shiftingLetters("abc", t) << "\n"; //rpl
    t={10,20,30};
    cout << s.shiftingLetters("bad", t) << "\n"; //jyh

}
