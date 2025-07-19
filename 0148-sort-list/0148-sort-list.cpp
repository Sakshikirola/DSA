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
    ListNode* getmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast!=NULL && fast->next !=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != NULL){
            prev->next = NULL;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1 , ListNode* l2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            }else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if (l1) tail->next = l1;
        if (l2) tail->next = l2; 

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* mid = getmid(head); 
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        return merge(left,right); 
    } 
};

