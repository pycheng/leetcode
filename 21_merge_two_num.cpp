#include <iostream>
#include <limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(INT_MAX);
		ListNode* cur = head;
		if(l1 == NULL || l2 == NULL) return (l1==NULL)?l2:l1;
		
	    while(l1!=NULL && l2!=NULL){
			if(l1->val < l2->val){ 
				cur->next = l1; 
				l1 = l1->next;
			}else{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}		
		cur->next = (l1==NULL)?l2:l1;

		cur = head->next;
		delete head;
		return cur;
    }
};
