//#string, #gps
//sting::npos
#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        int repeatedStringMatch(string A, string B) {
            string as;
            int i;
            for(i=0; i<B.size()/A.size()+3; i++){
                as+=A;
                cout << as <<","<<i<<","<<B.size()<< "\n";
                if(as.find(B)!=string::npos) return i+1;
            }
            return -1;
        }
};


int main(){
    string a = "bb";
    string b = "bbbbbbb";
    Solution s;
    
    cout << s.repeatedStringMatch(a,b);
}
