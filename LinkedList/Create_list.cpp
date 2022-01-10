//.......................................This program is used to define Link least using structure.........................................................
#include<iostream>
using namespace std;

//.......................node is user define datatype , which contain two elements in it....................................
// 1) integer data (its own data)  
// 2) node type pointer, used to store address of next node
struct node{
    int data;
    node *next;
};

// printList() function is used to print data stores in all nodes
void printList(node *n)
{
    while(n!=NULL){
    cout<<n->data<<endl;
    n=n->next;

}
}

int main(){
    
    // defining three pointers of type node, use to point elements of node
    node *head=new node();
    node *second=new node();
    node *third=new node();
    
    head->data=5;
    // next pointer of head node stores addresscof second node 
    head->next=second;

    second->data=9;
    // next pointer of second node stores address of third node
    second->next=third;

    third->data=7;
    // next pointer of third node stores NULL value in it, because there is no next node
    third->next=NULL;
    
    // calling to print data of all nodes, using only head node
    printList(head);
}
