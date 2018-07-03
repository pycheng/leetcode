#include<iostream>
#include<math.h>
using namespace std;
#if 0
case 1.  () has score 1
case 2.  AB has score A + B, where A and B are balanced parentheses strings.
case 3.  (A) has score 2 * A, where A is a balanced parentheses string.
#endif

//option 1. recussion score(s, l, r)
// 1. find the case 2 prefix
// 2. recusion call score(prefix, l+1, r-1)+score(suffix, l, r)
// base case (case 1) if(r-l == 1) return 1
// time complexity
//      best case:  O(n)    e.g., ()()()()
//      worst case: O(n^2)  e.g., (((())))   requests n/2 recursion call
// pace complexity: O(n)

//option 2. specific for this question scoring method
// 1. if s[i] == '(' and s[i+1] == ')', add score 2^d-1, d is the '(' count before i
//      e.g., (() (())) --> (()) + ((()))
// time complexity  O(n)
// space complextiy O(1)

class Solution{
private:
    int score(string& S, int l, int r){
        if(r-l == 1) return 1;
        int d = 0;
        for(int i=l; i<r; i++){
            if(S[i] == ')') d--;
            else if(S[i] == '(') d++;
            if(d==0)
                return score(S, l, i) + score(S, i+1, r);
        }
        return 2*score(S, l+1, r-1);
    }
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.size()-1);
    }
};
class Solution2{
public:
    int scoreOfParentheses(string S) {
        int ans=0, d=0;
        for(int i=0; i<S.size(); i++){
            if(S[i] == '(' && S[i+1] == ')') ans+=(int)pow(2,d);
            if(S[i] == '(') d++;
            if(S[i] == ')') d--;
        }
        return ans;
    }
};

int main(){
    string t = "(()(()))";
    Solution s;
    cout << s.scoreOfParentheses(t);
}
