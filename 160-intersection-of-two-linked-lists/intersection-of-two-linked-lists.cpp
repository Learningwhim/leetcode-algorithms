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
        int l1 = 0, l2 = 0;
        ListNode* temp = headA;
        while(temp != NULL){
            l1++;
            temp = temp->next;
        }    
        temp = headB;                                                                   
        while(temp != NULL){
            l2++;
            temp = temp->next;
        }   
        if(l1 < l2){
            return collision(headA, headB, l2-l1);
        }else return collision(headB, headA, l1-l2);
        return NULL;
    }
};