#include<iostream>
using namespace std;


struct node{
int data;
node *next;
node *prev;
};


void addFront(node **head,int ndata){
node *new_node=new node();
new_node->data=ndata;
new_node->next=*head;
new_node->prev=NULL;

if((*head)!=NULL){
    (*head)->prev=new_node;
}
(*head)=new_node;
}
void printList(node *n){
   int cnt=0;
while(n!=NULL){
    cout<<n->data<<endl;
    n=n->next;
cnt++;
}
cout<<"NO of Element inside is :"<<cnt<<endl;
}
void insertAfter(node *prev_node,int new_data){
if(prev_node==NULL){
    cout<<"Previous node can't be null"<<endl;
    return;
}

    node *new_node=new node();
    new_node->data=new_data;
    new_node->next=prev_node->next;

    prev_node->next=new_node;
    new_node->prev=prev_node;

    if(new_node->next!=NULL){
        new_node->next->prev=new_node;
    }

}
void addEnd(node **head,int new_data){
node *new_node=new node();
new_node->data=new_data;
new_node->next=NULL;

node *last=*head;
if(*head==NULL){
    new_node->prev=NULL;
    *head=new_node;
    return;

}
while(last->next!=NULL){
    last=last->next;
}
last->next=new_node;
new_node->prev=last;
return;
}

int main(){
node *head=NULL;

addFront(&head,5);
addFront(&head,7);
addFront(&head,9);

insertAfter(head->next,10);

addEnd(&head,777);
printList(head);
    return 0;
}
