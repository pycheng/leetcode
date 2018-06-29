#include <iostream>
#include <vector>
using namespace std;

//two pointer solution
//move left++ and right-- to the next point that height is hieghter than the ori.
// YOU CANNOT MOVE AT THE SAME TIME 
// --> move the one with less height, if height is equal move right;
//calculate the area against the max area
//Time Complexity O(n)

class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() < 2) return 0;
        int left = 0, right = height.size()-1, max_area = 0 ;
        while(left < right){
            max_area = max(max_area, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return max_area;
    }
};


int main(){
    Solution s;
    vector<int> h = {4,6,2,6,4}; //20
    cout << s.maxArea(h);
}
