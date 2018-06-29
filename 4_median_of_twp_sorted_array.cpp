#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Requires to implement in less than O(log(n+m))
// vector<int> a(n) a is sorted, the median of a is 
//  n is even (a[n/2-1]+a[n/2])*0.5
//  n is odd  a[n/2]         
// a is seperated to vector<int> b(m), c(k), b and c is insorted order
// ***** n = m+k;
// b[i-1], b[i], c[j-1], c[j]  j = (n/2)-i;
// if(b[i] > c[j-1]){
// }
//      a[n/2-1] = max(c[j-1], b[i-1]);
//      a[n/2]   = min(c[j], b[i]);
// 
// Using binary search to find the i in shortest array;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size()+nums2.size();
        int left = 0, right = nums1.size(); //note here you want to seach for nums1[n-1], nums1[n]
        while(left <= right){
            // partition nums1/nums2
            int partition_nums1 = (left+right)/2;
            int partition_nums2 = n/2-partition_nums1;
            
            int nums1_leftmax = (partition_nums1-1 >= 0)? nums1[partition_nums1-1]:INT_MIN;
            int nums1_rightmin= (partition_nums1 < nums1.size())? nums1[partition_nums1]:INT_MAX;
            int nums2_leftmax = (partition_nums2-1 >= 0)? nums2[partition_nums2-1]:INT_MIN;
            int nums2_rightmin= (partition_nums2 < nums2.size())? nums2[partition_nums2]:INT_MAX;

            if(nums1_leftmax <= nums2_rightmin && nums2_leftmax <= nums1_rightmin){
                if(n%2 == 1){ //odd
                    return min(nums1_rightmin, nums2_rightmin);
                }else{
                    return 0.5*(min(nums1_rightmin, nums2_rightmin)+
                        max(nums1_leftmax, nums2_leftmax));
                }
            }else if(nums1_leftmax > nums2_rightmin){
                right = partition_nums1-1;
            }else if(nums2_leftmax > nums1_rightmin){
                left = partition_nums1+1;
            }
        }
    }
};

int main(){
    Solution s;
    vector<int> t1 = {1,2};
    vector<int> t2 = {3,4};
    cout << s.findMedianSortedArrays(t1,t2) << "\n";
    t1 = {1,3};
    t2  = {2};
    cout << s.findMedianSortedArrays(t1,t2) << "\n";
    t1 = {-1,1,3,5,7,9};
    t2  = {2,4,6,8,10,12,14,16};
    cout << s.findMedianSortedArrays(t1,t2) << "\n";
    t1 = {};
    t2  = {2,3};
    cout << s.findMedianSortedArrays(t1,t2) << "\n";
    cout << s.findMedianSortedArrays_20180622(t1,t2) << "\n";
}
