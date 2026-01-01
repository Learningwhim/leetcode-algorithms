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
    ListNode* collision(ListNode* head1, ListNode* head2, int gap){
        ListNode* temp1 = head1, *temp2 = head2;
        for(int i = 0; i < gap; ++i){
            temp2 = temp2->next;
        }
        while(temp1 != NULL && temp2 != NULL){
            if(temp1 == temp2) return temp1;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
            if(t1 == t2) return t1;
            if(t1 == NULL) t1 = headB;
            if(t2 == NULL) t2 = headA;
        }
        return t1;
    }
};