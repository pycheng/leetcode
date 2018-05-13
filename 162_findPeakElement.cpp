//#seaching, #dvide_n_concquer, #gps
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;

        while(l<r){
            int m = (l+r)/2;
            if(num[m] < num[m+1]){ 
                l = m+1;
            }else{
                r = m;
            }
        }

        return l;
    }
};
