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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        if(head == NULL || head->next == NULL) return false;
        ListNode* fast = head->next->next, *slow = head;
        //int cnt == 0;
        while(fast != NULL && fast->next != NULL){
            if(fast == slow) return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
        
    }
};