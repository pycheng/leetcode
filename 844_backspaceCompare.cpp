#include <iostream>
using namespace std;

#if 0
Time complexity O(n+m) Space complexity O(1)
    1. search backward for seeing '#' before the deleted char
    2. when meet string[idx]=='#' move idx to the next valid char --> nxt_nonhash
    3. comparing S[s_idx] == T[t_idx] handle the corner case when idx < 0 
#endif


class Solution {
public:
    int nxt_nonhash(string s, int idx){
        int cnt = 0;
        while(s[idx]=='#' || cnt>0){
            if(s[idx]=='#') cnt++;
            else cnt--;
            idx--;
        }
        return idx;
    }
    bool backspaceCompare(string S, string T) {
        int si, ti;
		//time complexity O(m+n): break case must go through both string entirely (si>=0||ti>=0)
		//space complexity O(1)
		//easy to track back by i--
        for(si=S.size(),ti=T.size(); (si>=0)||(ti>=0); si--,ti--){
            if(si>=0 && S[si] == '#') si = nxt_nonhash(S,si);
            if(ti>=0 && T[ti] == '#') ti = nxt_nonhash(T,ti);
			
            if(si<0 || ti<0){
				//if one of index >= 0 and the other <0 must be false
				//can be realized as if((si>=0)!=(ti>=0))
                if(si>=0 || ti>=0) return false;
            }else{
                if(S[si]!=T[ti]) return false;
            }
        }
        return (si<0&&ti<0)?true:(si==ti);
    }
#if 0
		int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) { // While there may be chars in build(S) or build (T)
            while (i >= 0) { // Find position of next possible char in build(S)
                if (S.charAt(i) == '#') {skipS++; i--;}
                else if (skipS > 0) {skipS--; i--;}
                else break;
            }
            while (j >= 0) { // Find position of next possible char in build(T)
                if (T.charAt(j) == '#') {skipT++; j--;}
                else if (skipT > 0) {skipT--; j--;}
                else break;
            }
            // If two actual characters are different
            if (i >= 0 && j >= 0 && S.charAt(i) != T.charAt(j))
                return false;
            // If expecting to compare char vs nothing
            if ((i >= 0) != (j >= 0))
                return false;
            i--; j--;
        }
        return true;
#endif
};

int main(){
    Solution s;
    cout << s.backspaceCompare("bxj##tw", "bxj###tw") << "\n"; //0
    cout << s.backspaceCompare("bxj#tw", "bxjtw") << "\n"; //0
    cout << s.backspaceCompare("y#fo##f", "y#f#o##f") << "\n"; //1  corner:  si=-1 && ti=-3
    cout << s.backspaceCompare("nzp#0#g", "b#nzp#o#g") << "\n"; //1 corner:  si<0 && (ti>0, T[ti]=#)
}

