#include <iostream>
using namespace std;


//The goal is to solve this by O(1) space complexity and O(n) time complexity
//  1. using fast and slow pointer to find the middle and tail
//  2. revese the linked list from the middle to tail
//  3. compare the list from head++ // tail-- 
//      when(head && tail) comparing node value(even/odd nodes)
//  4. note that middle->next must set to null;
//  5. [] [1] are palindrome
//---------------------------------------------------------------------------
//To solve this by O(n) space complexity, using array and trace from head and tail


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
    bool isPalindrome(ListNode* head) {
 	     ListNode *middle = head, *tail = head;

         //base case
         if(head == NULL) return true;

         //find middle and tail
         while(tail->next!=NULL){
             middle = middle->next;
             tail = (tail->next->next!=NULL)?tail->next->next: tail->next; 
         }
         
         //reverse the middle to tail
         ListNode *cur  = middle;
         ListNode *next = cur->next;
         while(next!=NULL){
             ListNode *prev = cur;
             cur  = next;
             next = next->next;
             cur->next = prev;
         }
         middle->next = NULL;

         while(head && tail){
             if(head->val != tail->val) return false;
             head = head->next;
             tail = tail->next;
         }
         return true;
    }
};

int main(){
    Solution s;
    ListNode *n, *t1, *t2, *t3;
    t1 = n = new ListNode(1);
    t2 = n = new ListNode(1);
    n->next = new ListNode(2);
    n = n->next;
    n->next = new ListNode(3);
    n = n->next;
    n->next = new ListNode(1);


    t3 = n = new ListNode(1);
    n->next = new ListNode(2);
    n = n->next;
    n->next = new ListNode(1);
    cout << s.isPalindrome(t1) << "\n";
    cout << s.isPalindrome(t2) << "\n";
    cout << s.isPalindrome(t3) << "\n";
}

