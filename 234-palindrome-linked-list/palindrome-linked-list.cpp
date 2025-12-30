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
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == nullptr) return head;
        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == nullptr) return true;
        ListNode* slow = head, *fast = head;
        
        while(fast->next != NULL && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* first = head;
        ListNode* second = reverse(slow->next);
        while(second != nullptr){
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        return true;

    }
};