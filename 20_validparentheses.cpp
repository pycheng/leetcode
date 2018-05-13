//#stack, #gps
#include <iostream>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;


class Solution {
    public:
    bool isValid(string s) {
        stack<char> s1;
        set<char> left = {'(','[','{'};
        //set<char> right= {')',']','}'};
        map<char, char> m = {{')', '('}, {']','['}, {'}','{'}};
        char c;

        for(auto i: s){
            if(left.count(i)>0){
                s1.push(i);
            }else{
                if(s1.empty()) return false;
                if(s1.top() != m[i]){
                    return false;
                }
                s1.pop();
            }
        }
        if(s1.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution sol;
    string t0 = "[]";
    cout << sol.isValid(t0);

    return 0;
}
