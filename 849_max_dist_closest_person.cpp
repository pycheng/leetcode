#include <iostream>
#include <vector>
using namespace std;

//1,0,0,0,1,0,1 ==> 2
//1,0,0,0     ==> 3
//boundary(-1, size()) 
// search for the longest consecutive 0
// case 1, n leading 0 --> n
// case 2, m tailing 0 --> m
// case 3, k between 1 --> k/2+k%2 or (k+1)/2
//      --> even: k/2 example:4 odd: k/2+1 example:3

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
		bool is_leading_zero = true;
		int leading_zero = 0;
		int tailing_zero = 0;
		int max_zero_bt_one = 0;
		int consecutive_zero = 0;
		for(int i=0; i<seats.size(); i++){
			if(seats[i]==0){ 
				consecutive_zero++;
			}else{
			    if(is_leading_zero){
					is_leading_zero = false;
					leading_zero = consecutive_zero;
				}else{
					max_zero_bt_one = max(max_zero_bt_one, consecutive_zero);
				}	
			    consecutive_zero = 0;
			}
		}
		tailing_zero = consecutive_zero;
		int res = max(tailing_zero, leading_zero);
		res = max(res, max_zero_bt_one/2+max_zero_bt_one%2);
		return res;
    }
};
int main(){
	Solution s;
	vector<int> s0 = {1,0,0,0,1,0,1}; //2
	vector<int> s1 = {1,0,0,0};	      //3
	cout << s.maxDistToClosest(s0) << "\n";
	cout << s.maxDistToClosest(s1) << "\n";
}
