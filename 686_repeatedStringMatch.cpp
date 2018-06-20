//#string, #gps
//sting::npos
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
    public:
        int repeatedStringMatch(string A, string B) {
	        string t="";
	        int min_cpy = ceil((double) B.size()/A.size());
	        for(int i=0; i<min_cpy*2; i++){
	        	t += A;
	        	if(i >= min_cpy-1){
	        		if(string::npos != t.find(B)) return i+1;
	        	}
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
