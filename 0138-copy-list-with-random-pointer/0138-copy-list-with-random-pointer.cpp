class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }

        unordered_map<Node*, Node*>m;
        
        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        m[head] = newhead;

        while(oldtemp != NULL){
         Node* copyNode = new Node(oldtemp->val);
         m[oldtemp] = copyNode;
         newtemp->next = copyNode;
         oldtemp = oldtemp->next;
         newtemp = newtemp->next;
        }

        oldtemp = head ; newtemp = newhead;
        while(oldtemp!=NULL){
           newtemp->random = m[oldtemp->random] ;
           oldtemp = oldtemp->next;
           newtemp = newtemp->next;
        }
        return newhead;
    }
};