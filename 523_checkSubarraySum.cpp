//#hash
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            int sum=0, target;
            //solved by 0 at num[-1]
            unordered_map<int, int> hash{{0,-1}};
            
            for(int i=0; i<nums.size();i++){
                sum += nums[i];

                target = (k==0)?sum:(sum%k);
                if(hash.count(target)>0){
                    //subarray size must > 2 
                    if(i-hash[target]>1) return true; 
                }else{
                    hash[target]=i;
                }
            }
            return false;
        }
};
int main(){
    Solution sol;
    bool rslt;
    vector<int> t = {23,2,4,6,7};
    vector<int> t1 = {0,1,0}; //0  false --> subarray size must > 2 
    vector<int> t2 = {0,0};   //0  true  --> solved by 0 at num[-1]
    vector<int> t2 = {0};     //0  false 
    rslt = sol.checkSubarraySum(t,1);
    cout << rslt <<true;
    return 0;
}
