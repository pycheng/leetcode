// #dp
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//numsquare(n) can be compute by min(numsquare(n-i)) for i=1,2^2,sqrt(n)^2
//time complexity = O(sqrt(n)^n), space complexity = O(n)
//      depth=n, node=sqrt(n)
//
//Think in dp
//time complexity = n+(n-pow(2,2))+(n-pow(3,2))+...+(n-pow(sqrt(n),2))
//space complexity = O(n)                
//dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3 ( -->dp[n-1]+1)
//dp[4] = min(dp[3]+1, dp[4-pow(2,2)]+1) = min(4,1) = 1
//dp[5] = min(dp[4]+1, dp[5-pow(2,2)]+1) = min(2,2) = 2
//dp[6] = min(dp[5]+1, dp[6-pow(2,2)]+1) = min(3,3) = 3
//dp[7] = min(dp[6]+1, dp[7-pow(2,2)]+1) = min(4,4) = 4
//dp[8] = min(dp[7]+1, dp[8-pow(2,2)]+1) = min(5,2) = 2
//...
//dp[n] = min(dp[n-1]+1, dp[n-pow(2,2)]+1, dp[n-pow(3,2)]+1, ...dp[n-pow(sqrt(n),2)]+1)

class Solution {
public:
    int numSquares(int n) {
       vector<int> dp(n, INT_MAX);


    }

};


int main(){
    int t = 49;
    Solution s;
    cout << s.numSquares(t)<< "\n";
    //cout << s.le_sqrt(146) << "\n";
    //cout << s.le_sqrt(1) << "\n";
    //cout << s.le_sqrt(2) << "\n";
    //cout << s.le_sqrt(9) << "\n";
}

