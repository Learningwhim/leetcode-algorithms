/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *temp1 = head, *temp2 = head;
        ListNode *temp = new ListNode(0, head);
        temp2 = temp;
        int i = 1;
        while(temp1 != NULL && temp1->next != NULL && i < n){ 
            i++;
            temp1 = temp1->next;
        }
        if(i < n) return head;
        while(temp1 != NULL && temp1->next != NULL){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        //if(temp2-next == head) return temp2->next;
        temp2->next = temp2->next->next;
        return temp->next;
    }
};