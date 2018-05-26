#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *res = NULL;
        ListNode *res_t = NULL;
        while(l1 || l2){
            sum += (l1!=NULL)?l1->val:0;
            sum += (l2!=NULL)?l2->val:0;
        
            ListNode *n = new ListNode(sum%10);
            if(res == NULL){
                res = res_t = n;
            }else{
                res_t->next = n;
                res_t = n;
            }
            sum /= 10;
            if(l1!=NULL) l1 = l1->next;
            if(l2!=NULL) l2 = l2->next;
        }
        if(sum!=0){res_t->next = new ListNode(sum%10);}
        
        return res;
	}

    ListNode* addTwoNumbers_old(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr=head;
        ListNode* prev=head;
        while(l1 || l2){
            sum += (l1==NULL)?0:l1->val;
            l1   = (l1==NULL)?l1:l1->next;
            sum += (l2==NULL)?0:l2->val;
            l2   = (l2==NULL)?l2:l2->next;

            curr->val = sum%10;
            sum /= 10;
            curr->next = new ListNode(0);
            prev=curr;
            curr=curr->next;
        }
        if(sum>0) curr->val = sum%10;
        if(curr!=head && curr->val==0){
            prev->next = NULL;
            delete curr;
        }
        return head;
    }
};
