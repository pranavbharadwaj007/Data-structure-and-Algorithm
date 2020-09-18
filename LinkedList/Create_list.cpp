#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void printList(node *n){
while(n!=NULL){
    cout<<n->data<<endl;
    n=n->next;

}
}

int main(){
    node *head=new node();
    node *second=new node();
    node *third=new node();
    head->data=5;
    head->next=second;

    second->data=9;
    second->next=third;

    third->data=7;
    third->next=NULL;

    printList(head);
}