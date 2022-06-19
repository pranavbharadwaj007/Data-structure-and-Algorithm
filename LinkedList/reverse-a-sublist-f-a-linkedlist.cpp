
// Link : https://practice.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1#

class Solution
{
    public:
 Node* reverse(Node* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* prev = NULL;
        Node* curr = head;
        Node* forward = NULL;
        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        
        return prev;
    }
Node* reverseBetween(Node* head, int m, int n)
    {
        if(m==1){
           int cnt = 1;
           Node* temp = head;
           while(cnt<n){
               temp=temp->next;
               cnt++;
           }
           Node* part2 = temp->next;
           temp->next = NULL;
           Node* revList = reverse(head);
           head->next = part2;
           
           return revList;
        }else{
        int cnt = 1;
        Node* subHead = head;
        Node* subTail = head;
        while(cnt< m-1){
            subHead = subHead->next;
            cnt++;
        }
        
        cnt = 1;
        while(cnt < n){
            subTail = subTail->next;
            cnt++;
        }
        Node* subList = subHead ->next;
        subHead ->next = NULL;
        Node* part2 = subTail->next;
        subTail->next = NULL;
        Node* revSubList = reverse(subList);
        subHead->next = revSubList;
        
        cnt = 1;
        Node* temp = head;
        while(cnt<n){
            temp = temp->next;
            cnt++;
        }
        
        temp->next = part2;
        
        return head;
        

        }
    }
};
