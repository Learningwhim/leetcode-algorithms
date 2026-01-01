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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newHead = new ListNode(0), *temp = newHead;
        int carry = 0;
        while(l1 != NULL && l2 != NULL){
            int newval = l1->val + l2->val + carry;
            ListNode* newNode = new ListNode(newval%10);
            temp->next = newNode;
            carry = newval/10;
            l1 = l1->next;
            l2 = l2->next;
            temp = temp->next;
        }
        while(l1 != NULL){
            int newval = l1->val + carry;
            ListNode* newNode = new ListNode(newval%10);
            temp->next = newNode;
            carry = newval/10;
            l1 = l1->next;
            temp = temp->next;
        }

        while(l2 != NULL){
            int newval = l2->val + carry;
            ListNode* newNode = new ListNode(newval%10);
            temp->next = newNode;
            carry = newval/10;
            l2 = l2->next;
            temp = temp->next;
        }
        while(carry){
            ListNode* newNode = new ListNode(carry%10);
            temp->next = newNode;
            carry = carry/10;
            temp = temp->next;
        }
        return newHead->next;
    }
};