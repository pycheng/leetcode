// #bm
#include <iostream>
#include <bitset>
using namespace std;

//Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
//  1+1=0(carry 1) 1+0=1 0+1=1 0+0=0 
//  bit = a^b;
//  carry = (a&b)<<1;
//  note that carry will be zero if we iterate though a and b
//  even if a and b are neg the result is the same
class Solution {
public:
	int getSum(int a, int b){
		return b==0?a:getSum(a^b,(a&b)<<1);
	}
    int getSum_1(int a, int b) {
         while(b!=0){
             int s = a^b;
             b = (a&b)<<1;
             a = s;
         }
         return a;
    }
};
int main(){
    Solution s;
    cout << s.getSum(5,6) << "\n";
    cout << s.getSum(-1,1) << "\n";
//    cout << bitset<32>(-3); 
}
