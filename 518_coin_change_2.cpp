//#dp
#if 0
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin. 
#endif
#include <iostream>
#include <vector>
using namespace std;

int coinchange(int amount, vector<int> coins, int denom)
{
    // think in dp 
    // dp[0] = 1
    // dp[amount+coin] += dp[amount]
    vector <int> dp(amount+1,0);
    dp[0] = 1;
    for(auto coin:coins){
        for(int i = 0; i<=amount-coin; i++){
            dp[i+coin] += dp[i];
            cout << "[" << coin << ",";
            cout << i << "]";
            for(auto j:dp) cout << j << ",";
            cout << "\n";
        }
    }
    return dp[amount];

}
class Solution {
    public:
    int change(int amount, vector<int>& coins) {
        return coinchange(amount, coins, 0);         
    }
};

int main(){
    Solution s;
    vector <int> coin={1, 2, 5};
    cout << s.change(5, coin);
}
