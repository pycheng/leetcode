#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> *qin, *qout;
    queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {
        qin  = &q1;
        qout = &q2;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        qin->push(x);
        while(!qout->empty()){
            qin->push(qout->front());
            qout->pop();
        }
        swap(qin, qout);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = qout->front();
        qout->pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
       return  qout->front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return qout->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
int main(){
        MyStack obj;
     obj.push(7);
     obj.push(8);
      int param_2 = obj.pop();
      int param_3 = obj.top();
      bool param_4 = obj.empty();
      cout << param_2 << "," << param_3 <<"," <<param_4;
}
