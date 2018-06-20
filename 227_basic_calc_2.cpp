#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        s = "+" + s + "+";
        int v = 0;
        char optr = ' ';
        stack<int> stk;
        for(auto c:s){
            if(isdigit(c)){
                v = v*10+c-'0';
            }else if(c=='+'||c=='-'||c=='*'||c=='/'){
                if(optr == '+'){
                    stk.push(v);
                }else if(optr == '-'){
                    stk.push(-v);
                }else if(optr == '*' || optr == '/'){
                    int b = stk.top();
                    stk.pop();
                    if(optr == '*'){
                        stk.push(b*v);
                    }else{
                        stk.push(b/v);
                    }
                }
                optr = c;
                v = 0;
            }
        }
        int res = 0;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.calculate("3+5/2");
}
