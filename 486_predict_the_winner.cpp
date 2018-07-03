#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;
#if 0
Given an array of scores that are non-negative integers. 
Player 1 picks one of the numbers from either end of the array followed by the player 2 and then player 1 and so on. 
Each time a player picks a number, that number will not be available for the next player. 
This continues until all the scores have been chosen. 
The player with the maximum score wins.

Given an array of scores, predict whether player 1 is the winner. 
You can assume each player plays to maximize his score.
[1,5,2] false
[1,5,233,7] true
#endif

//draw the game as a binary tree
//each leve represent different player
//Recursion: 
//  time complexity O(2^n) 
//  space complexity O(n) --> n is the tree height
//DP thinking: (l,r) pair could be query multiple times
//use hashmap to store the l*nums.size()+r
//  time complexity O(n^2) --> n*n keys
//  space complexity O(n^2) + O(n) --> hash size + recursion

class Solution {
public:
     int one_run_recursion(vector<int>& nums, int l, int r){
         if(l==r) return nums[l];
         return max(nums[l] - one_run_recursion(nums, l+1, r),
                    nums[r] - one_run_recursion(nums, l, r-1));
     }
    int one_run(vector<int>& nums, int l, int r, unordered_map<int, int>& dp){
        int key = l*nums.size() + r;
        if(dp.find(key) != dp.end()) return dp[key];
        if(l==r){
            dp[key] = nums[l];
        }else{
            dp[key] =  max(nums[l] - one_run(nums, l+1, r, dp), 
                           nums[r] - one_run(nums, l, r-1, dp));
        }
        return dp[key];
    }
    bool PredictTheWinner(vector<int>& nums) {
        unordered_map<int, int> dp;
 	    //return (one_run_recursion(nums, 0, nums.size()-1)>=0);   
 	    return (one_run(nums, 0, nums.size()-1, dp)>=0);   
    }
};
#if 0
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        int n = nums.size();
        if(n % 2 == 0)
        {
            return true;
        }
        
        std::vector<int> dp(nums.size() , 0);
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int j = i ; j < n ; j++)
            {
                if(i == j)
                {
                    dp[j] = nums[i];
                }
                else
                {
                    dp[j] = std::max(nums[i] - dp[j] , nums[j] - dp[j-1]);
                }
            }
        }
        return dp[n-1] >= 0;
    }
};
#endif
int main(){
    vector<int> t = {1,5,2};
    Solution1 s;
    cout << s.PredictTheWinner(t);
}

