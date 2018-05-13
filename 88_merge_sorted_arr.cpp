//#array, #gps
//howto not using buf
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


class Solution {
    public:
       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i1=m-1, i2=n-1, i3=m+n-1;

            for(;i1>=0&&i2>=0;){
                if(nums1[i1] > nums2[i2]){
                    nums1[i3--] = nums1[i1--];
                }else{
                    nums1[i3--] = nums2[i2--];
                }
            }
            while(i2>=0) nums1[i3--] = nums2[i2--];
            while(i1>=0) nums1[i3--] = nums1[i1--];
       }

       void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int>buf(m+n);
            int i1 = 0;
            int i2 = 0;
            for(int i=0; i<m+n; i++){
                if(i1>=m){
                    buf[i] = nums2[i2++];
                }else if(i2>=n){
                    buf[i] = nums1[i1++];
                }else{
                    if(nums1[i1] < nums2[i2]){
                        buf[i] = nums1[i1++];
                    }else{
                        buf[i] = nums2[i2++];
                    }
                }
            }
     
            memcpy(&nums1[0], &buf[0], sizeof(int)*(m+n));
       }
};


int main(){
    vector<int> nums1 = {1,2,3,0,0,0}; 
    vector<int> nums2 = {2,5,6};
    Solution s;
    s.merge(nums1, 3, nums2, 3);
    for(auto i: nums1) cout << i << ",";
    cout << "\n";
    return 0;
}

