#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
		int v = 0;
		bool sign = false;
		stack<int> stk;
        for(auto c:s){
			cout << c << "$$ ";
			if(isdigit(c)){
				cout << c << "^^ ";
				v+= 10*v + c - '0';
			}else{
				cout << v << "##\n";
				if(c=='+'){ 
					stk.push(sign?-v:v);
					sign = false;
				}else if(c=='-'){
					sign = true;
				}else if(c=='*' || c== '/'){
					int v1 = stk.top();
					stk.pop();
					if(c=='*')
						stk.push(v1*v);
					else
						stk.push(v1/v);
					sign=false;
				}					
				v=0;
			}
		}
		long long ttl=0;
		while(!stk.empty()){
			ttl += stk.top(); stk.pop();
			cout << ttl << ",";
		}
		return ttl;	
    }
};
int main(){
	Solution s;
	cout << s.calculate("3+2*2");
}
