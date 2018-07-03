#include <iostream>
#include <stack>
#include <limits.h>
using namespace std;

class MinStack {
private:
	class item{
	public:
		int v;
		int m;
		item(int x, int y):v(x){
			m = min(x, y);
		}
	};
	stack<item> stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
		int min = (stk.empty())?x:stk.top().m;
		item i(x,min);
		stk.push(i);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
       	return stk.top().v;
    }
    
    int getMin() {
        return stk.top().m;
    }
};

int main(){
	MinStack s;
	s.push(3);
	s.push(5);
	s.push(2);
	cout << s.top() << "\n";
	cout << s.getMin() << "\n";
	s.pop();
	cout << s.top() << "\n";
	cout << s.getMin() << "\n";
	
}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
