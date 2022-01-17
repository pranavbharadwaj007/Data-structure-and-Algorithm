class Solution {
public:
    Node* copyRandomList(Node* head) {
       map<Node*,Node*>mp;
        Node* curr=head;
        Node* nhead=new Node(-1);
        Node* prev=nhead;
        while(curr!=NULL){
            Node* temn=new Node(curr->val);
            prev->next=temn;
            mp[curr]=temn;
            curr=curr->next;
            prev=prev->next;
            
        }
        nhead=nhead->next;
       Node* c1=head;
        Node* c2=nhead;
        while(c1!=NULL){
           c2->random=mp[c1->random];
            c1=c1->next;
            c2=c2->next;
            
        }
        return nhead;
    }
};
