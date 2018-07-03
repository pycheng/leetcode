#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
		if(n == 1) return "1";
		string res = "1";
		for(int i=1; i<n; i++){
            string buf = "";
			for(int j=0; j<res.size(); j++){
                int  count=1;
                char curr=res[j];
                while((j+1)<res.size() && res[j+1]==curr){
                    count++; j++;
                }
                buf+=to_string(count)+curr;
			}
            res = buf;
		}
        return res;
    }
};
int main(){
    Solution s;
    cout << s.countAndSay(4);
}
