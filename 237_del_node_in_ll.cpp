//#linkerlist
//trickey thing is why the input node cannot be the tail!!
//answer it and you get the answer
#include <iostream>
using namespace std;

#if 0
1. The linked list will have at least two elements.
2. All of the nodes' values will be unique.
3. The given node will not be the tail and it will always be a valid node of the linked list.
4. Do not return anything from your function.
#endif

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
    void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode *next = node->next;
		node->next = node->next->next;
		delete next;
    }
};


int main(){
	ListNode *t, *n, *r;
	t = n = new ListNode(4);
	r= n->next = new ListNode(5);
	n=n->next;
	n->next = new ListNode(1);
	n=n->next;
	n->next = new ListNode(3);
	n=n->next;
	Solution s;
	s.deleteNode(t->next);
	while(t!=NULL){
		cout << t->val << ",";
		t = t->next;
	}
}
