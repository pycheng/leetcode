//#stack #linked-list
//Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 8 -> 0 -> 7
//reverse order please use stack
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            stack<int> s1, s2;
            ListNode *p;
            p = l1;
            while(p!=NULL){
                s1.push(p->val);
                p=p->next;
            }
            p = l2;
            while(p!=NULL){
                s2.push(p->val);
                p=p->next;
            }
            ListNode *c = new ListNode(0);
            while(!s1.empty()&&!s2.empty()){
                int v;
                v = (s1.empty()?0:s1.top())+
                    (s2.empty()?0:s2.top()); 
                s1.pop(); s2.pop();
               
                c->val += v%10;
                ListNode *n = new ListNode(c->val/10);
                c->val %=10;
                cout << c->val <<"," << n->val << "\n";
                c = n;
            }
            if(c->val >= 10){
                ListNode *n = new ListNode(c->val/10);
                c->val %= 10;
                c = n;
            }

            return c;
        }
};
int main(){
    return 0;
}
