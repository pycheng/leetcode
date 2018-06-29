#include <iostream>
using namespace std;


// recursion action: (current->next)->next = current;
// return value: head of the new list;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head==NULL) return NULL;
		if(head->next == NULL) return head;
		ListNode* next = head->next;
		ListNode* newhead = reverseList(next); 
		next->next = head;
		head->next = NULL;
		return newhead;
    }
};
