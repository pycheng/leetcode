#if 0
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

#endif
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
   int val;
   struct ListNode *next;
};

struct ListNode v11, v12, v13;
struct ListNode v21, v22, v23;

void init_data(){
    v11.val = 2;
    v11.next = &v12;
    v12.val = 4;
    v12.next = &v13;
    v13.val = 3;
    v13.next = NULL;
    
    v21.val = 5;
    v21.next = &v22;
    v22.val = 6;
    v22.next = &v23;
    v23.val = 4;
    v23.next = NULL;
}


/**
 * Definition for singly-linked list. 
 * * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *ret, *p;
    int more = 0;
    int dig;
    ret = l1;
    p   = l1;
    
    while(l1!=NULL || l2!=NULL || more!=0){
        if(l1!=NULL){more+=l1->val;}
        if(l2!=NULL){more+=l2->val;}
        dig = more % 10;
        more = more/10;

        printf("(%d,%d)",more,dig);
        if(l1!=NULL){
            l1->val = dig;
            p = l1;
            l1 = l1->next;
        }else{
            l1 = malloc(sizeof(struct ListNode));
            l1->val = dig;
            l1->next = NULL;
            p->next = l1;
            p = l1;
            l1 = NULL;
        }

        if(l2!=NULL){
            l2 = l2->next;
        }
    }

    return ret;
}

int main(){
    struct ListNode *rslt;
    init_data();
    rslt = addTwoNumbers(&v11,&v21);
    for (;rslt!=NULL;rslt=rslt->next){
        printf("%d-->", rslt->val);
    }
    printf("\n");
    free(rslt);
    return 0;
}
