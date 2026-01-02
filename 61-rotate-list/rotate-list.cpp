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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        ListNode* temp = head;
        int len = 1;
        while(temp && temp->next != NULL){
            temp = temp->next;
            len++;
        }
        int shift = len-(k%len)-1;
        if(k%len == 0) return head;
        temp->next = head;
        temp = head;
        for(int i = 0; i < shift; ++i){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};