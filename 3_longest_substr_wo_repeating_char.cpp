#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;


// brute force is C(2,n) --> Time complexity O(n^2)
//
// O(n) by two pointer (s,e);
// base case s=0, e=0, insert input[0] to hashset
// iterate from input[1] to input[size()-1]
//    if cur_char not in set
//      e++; set.inser(cur_char);
//    else
//      if (set.size() > max_sz) { res = input.substr(s, e-s+1); }
//      do{ 
//          set.erase(input[s--]);
//      }while(set.count(input[s]) <= 0);
//
// corner case when s is empty

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
	    unordered_set<char> cset;
        if(str.size() == 0) return 0;
        int s=0, e=0, max_len=1;
        cset.insert(str[s]);

        for(int i=1; i<str.size(); i++){
            if(cset.count(str[i])>0){
                max_len = max(max_len, (int)cset.size());
                do{
                    cset.erase(str[s]);
                    s++;
                }while(cset.count(str[i])>0);
            }
            e=i;
            cset.insert(str[i]);
        }

        max_len = max(max_len, (int)cset.size()); //e-s+1
        return max_len;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLongestSubstring("pwwkew");
}
