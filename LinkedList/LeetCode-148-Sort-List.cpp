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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
               slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
       ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        ListNode* res=new ListNode(0);
        ListNode* p=res;
        ListNode* c1=l1;
        ListNode* c2=l2;
        
        while(c1!=NULL && c2!=NULL){
            if(c1->val<c2->val){
                p->next=c1;
                c1=c1->next;
            }
            else{
                p->next=c2;
                c2=c2->next;
            }
            p=p->next;
        }
//         while(c1!=NULL){
//             p->next=c1;
//             c1=c1->next;
//             p=p->next;
//         }
//               while(c2!=NULL){
//             p->next=c2;
//             c2=c2->next;
//             p=p->next;
//         }
//         p->next=NULL;
      
//         return res->next;
        p->next=c1!=NULL ? c1:c2;
        return res->next;
        
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* mid=middleNode(head);
        ListNode* nhead=mid->next;
        mid->next=NULL;
         ListNode* L1=sortList(head);
         ListNode* L2=sortList(nhead);
        
        return mergeTwoLists(L1,L2);
        
    }
};
