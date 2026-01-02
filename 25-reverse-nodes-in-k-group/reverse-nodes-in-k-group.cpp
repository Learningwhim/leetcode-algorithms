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
        if(head == NULL || head->next ==  NULL) return head;
        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode* findK(ListNode* head, int k){
        if(head == NULL) return head;
        ListNode* temp = head, *prev = NULL;
        int i = 0;
        while(i < k && temp!= NULL){
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(i == k) return prev;
        return NULL;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *nextNode = NULL, * prevNode = NULL;
        while(temp != NULL){
            ListNode *kthNode = findK(temp, k);
            if(kthNode){
                ListNode;
                nextNode = kthNode->next;
                kthNode->next = NULL;
                reverse(temp);
                if(temp == head){
                    head = kthNode;
                    prevNode = temp;
                    temp = nextNode;
                }else{
                    prevNode->next = kthNode;
                    prevNode = temp;
                    temp = nextNode;
                }
            }else {
                prevNode->next = temp;
                break;
            }
        }
        return head;
    }
};