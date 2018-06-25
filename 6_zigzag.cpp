#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> buf(numRows, "");
        int dir = 1;
        int cur_row = 0;
        for(auto i: s){
            buf[cur_row]+=i;

            if(cur_row+dir > numRows-1 || cur_row+dir < 0){
                dir = -dir;
            }
            cur_row += dir;
        }
        string res = "";
        for(auto i:buf) res+=i;
        return res;
    }
};

int main(){
    Solution s;
    cout << s.convert("PAYPALISHIRING",1);
}
