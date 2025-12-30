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
    ListNode* reverseList(ListNode* head) {
        if(head ==  NULL || head->next == nullptr) return head;
        ListNode *fwd = NULL, *curr = head, *bkw = NULL;
        //fwd = fwd->next;
        while(curr != NULL){
            fwd = curr->next;
            curr->next = bkw;
            bkw = curr;
            curr = fwd;
        }
        return bkw;
    }
};