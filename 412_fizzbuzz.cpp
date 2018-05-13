
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<string> fizzBuzz(int n) {
            vector<string> rslt(n,"");
            for(int i=1; i<=n; i++){
                if(i%3==0) rslt[i-1]+="Fizz";
                if(i%5==0) rslt[i-1]+="Buzz";
                if(i%3!=0&&i%5!=0) rslt[i-1] = to_string(i); 
            }
            return rslt;
        }
        vector<string> fizzbuzz1(int n){
            vector<string> rslt(n,"");

            for(int i=1; i<=n; i++){
                if(i%3 == 0) rslt[i-1]+="fizz";
                if(i%5 == 0) rslt[i-1]+="buzz";
                if(rslt[i-1].size() == 0){
                    rslt[i-1] = to_string(i);
                }
            }
            return rslt;
        }
};


int main(){
    Solution sol;
    vector<string> rslt;
    rslt = sol.fizzBuzz(15);
    for(int i=0; i<15;i++ ) cout << rslt[i] << "\n";
    return 1;
}
