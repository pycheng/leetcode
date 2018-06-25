#include <iostream>
#include <vector>
using namespace std;

//Option 1 dp[start_idx][end_idx]
//  base case 1: length == 1, return dp[i][i] = true;
//  base case 2: length == 2, return dp[i][i+1] = (s[i]==s[i+1]);
//  case 3: length == 3~s.size()-1  dp[i][j] = dp[i+1][j-1] && (s[i]==s[j]) 
//  Time complexity  = O(n^2) n=s.size()
//  Space complexity = O(n^2)
//
//Option 2 Manacher's algorithm
//  build vector<int> mana to represent the palindrome length centered by idx.
//  palindrome has a symetric architecture abazaba. 
//
//  1. Insert star in between the characters to simply the implementation (even/odd)
//       *a*b*a*z*a*b*a*
//  mana 010301070102010  --> right and left aba has the same mana
//  2. for every character there's two case
//      2.1 <not covered by previous palindrome> barely comparing left and right to find the mana[i]
//      2.2 <covered by previous palindrome> --> it must be the right of the center --> step 3
//  3. for the right of the center there's 4 kindly of case
//      - c: center_index
//      - cr: center_index+mana[c]
//      - cl: center_index-mana[c]  --> cl~cr is the palindorome centered by c
//      - l: l_index
//      - lr: l_index+mana[l]
//      - ll: l_index-mana[l]
//      - r: right_index --> we want to define mana[r]
//      3.1 if r-mana[l]~r+mana[l] covered by cr~cl
//          mana[r] = mana[l]
//      3.2 if cl==s.size()-1  --> c is the last palindrome or palindrome of c is suffix of s
//          mana[r] = -1 //dont care --> palindrome r must be shorter than palindome c
//      3.3 if r+mana[l] < s.size()
//          expand from mana[l] to look for longer palindome centered by r
//      3.4 if ll < cl
//          expand from mana[l] to look for longer palindome centered by r
//
//  Time complexity O(n), Space complexity O(1)
//
class Solution {
public:
    int pal_len(string s1, int i){
        int plen = 1;
        while(i-plen>=0 && i+plen<s1.size() && s1[i-plen]==s1[i+plen]) plen++;
        return plen-1;
    }
    string longestPalindrome(string s) {
        string s1;
        for(auto c:s){
            s1+="*"; s1+=c;
        }
        s1+="*";
        vector<int> mana(s1.size(), -1);
        int pmax = 0;
        int pmax_idx = 0;
        for(int i=0; i<s1.size(); ){
            mana[i] = pal_len(s1, i);
            cout << i << "," << mana[i] << "\n";
            if(mana[i] > pmax){
                pmax = mana[i];
                pmax_idx = i;
            }
            //initial right until cr
            int c=i, cr=c+mana[c], cl=c+mana[c];
            int r = c+1;
            for(; r<cl; r++){
                int l = c-(r-c), lr=l+mana[l], ll=l-mana[l];
                if(cl < r-ll && r+ll < cr){
                    //case 3.1 
                    mana[r] = mana[l];
                }else if(cr>=s1.size()-1){
                    //case 3.2 remain as -1
                }else if(r+ll<s1.size()){
                    //case 3.3
                    break;
                }else if(ll < cl){
                    //case 3.4
                    break;
                }
            
            }
            i = r;
        }
        cout << pmax_idx << "," << pmax;
        return s.substr((pmax_idx-pmax)/2, pmax);
    }
};


int main(){
    Solution s;
    cout << s.longestPalindrome("b");
}
