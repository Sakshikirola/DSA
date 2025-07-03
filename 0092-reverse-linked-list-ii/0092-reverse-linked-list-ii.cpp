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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL || left==right){ 
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        int i=1; 
        while(curr!=NULL && i!=left){
            prev = curr;
            curr = curr->next;
            i++;
        }

        ListNode* pointertostart = prev;
        ListNode* start = curr;
        prev = NULL;
        while(curr!=NULL && i != right+1){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }

        start->next = curr;
        if(pointertostart != NULL){
            pointertostart->next = prev;
        }else{
            return prev;
        }
        return head;
    }
};