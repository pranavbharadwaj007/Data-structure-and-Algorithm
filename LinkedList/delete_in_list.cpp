//Pranav Bharadwaj VScode Snipet 5
#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void printList(node *n){
   int cnt=0;
while(n!=NULL){
    cout<<n->data<<endl;
    n=n->next;
cnt++;
}
cout<<"NO of Element inside is :"<<cnt<<endl;
}

// node* addFront(node *head, int newdata){
//   node *newNode=new node();
//   newNode->data=newdata;
//   newNode->next=head;
//   head=newNode;
// return head;
void addFront(node **head, int newdata){
  node *newNode=new node();
  newNode->data=newdata;
  newNode->next=*head;
  *head=newNode;


}
void addThrough_n_position(node *prev,int newData){
node *newNode=new node();
newNode->data=newData;
newNode->next=prev->next;
prev->next=newNode;
}

void addEnd(node **head,int data){

node *newNode=new node;
  newNode->data=data;
  newNode->next=NULL;
   node *last=*head;

   if(*head==NULL){
     *head=newNode;
   return;
   }
   while(last->next!=NULL){
     last=last->next;
   }
   last->next=newNode;
   return;

}
void deleteList(node **head,int key){
    node *prev,*temp;

    temp=*head;
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    return;
    prev->next=temp->next;
    free(temp);

}

int main(){
    node* head=NULL;
    addFront(& head,5);
    addFront(&head,15);
    addFront(&head,510);
    addEnd(&head,78);
    //addThrough_n_position(head->next,75);
    deleteList(&head,15);
      printList(head);

//     //LinkedList Data set..
//     //creation of linked list
//     node *head=new node();
//     node *second=new node();
//     node *third=new node();
//     node *four=new node();
//     node *five=new node();
//     node *six=new node();
//     node *seven=new node();
            
//  //list1   
//     head->data=5;
//     head->next=second;
//  //list2
//     second->data=9;
//     second->next=third;
//  //list3
//     third->data=7;
//     third->next=four;
//  //list4
//     four->data=4;
//     four->next=five;
//  //list5
//     five->data=6;
//     five->next=six;
//  //list6
//     six->data=8;
//     six->next=seven;
//  //list7
//     seven->data=10;
//     seven->next=NULL;

//calling of function

  
}