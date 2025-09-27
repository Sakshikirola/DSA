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
    int pairSum(ListNode* head) {
        if(!head && !head->next) return NULL;

       ListNode* slow = head;
       ListNode* fast = head;
       int sum = 0;

       while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
       }

       ListNode* prev = nullptr;
       ListNode* curr = slow;
       while(curr){
        auto nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
       }

       while(prev){ 
        sum = max(head->val + prev->val,sum) ;
        head = head->next;
        prev = prev->next;
       }
       return sum;
    }
};