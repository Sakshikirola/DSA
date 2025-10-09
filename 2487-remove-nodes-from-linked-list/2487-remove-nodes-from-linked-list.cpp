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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        ListNode* curr = head;
        int maxVal = curr->val; 
        
        ListNode* prev = curr;
        curr = curr->next;

         while (curr) {
            if (curr->val < maxVal) {
                prev->next = curr->next;
            } else {
                maxVal = curr->val;
                prev = curr;
            }
            curr = curr->next;
        }

        head = reverseList(head);
        return head;
    }
};