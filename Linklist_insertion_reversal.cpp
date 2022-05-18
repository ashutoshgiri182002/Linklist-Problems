#include<iostream>
using namespace std;

class node{

public:
  int data;
  node * next;

  node(int data){
    this->data = data;
    next = NULL;
  }
};

//------------Linked List---------//

void insertAtHead(node * &head,int data){
  if(head==NULL){
    head = new node(data);
    return;
  }
  //otherwise
  node *n = new node(data);
  n->next = head;
  head = n;
}

void inserInMiddle(node *&head,int data,int pos){
  if(pos==0){
    insertAtHead(head,data);
  }
  else{
    node * temp = head;
    for(int jump = 1;jump<=pos-1;jump++){
      temp = temp->next;
    }
    node *n = new node(data);
    n->next = temp->next;
    temp->next = n;
  }
}

void insertAtTail(node *& head,int data){
  if(head==NULL){
    head = new node(data);
  }

  //otherwise
  node*temp = head;
  while(temp->next!=NULL){
    temp = temp->next;
  }

  node * n = new node(data);
  temp->next = n;
  temp = n;
}

node *recReverse(node *head){
  //base case
  if(head ==NULL or head->next ==NULL){
    return head;
  }
  //otherwise
  node *sHead = recReverse(head->next);
  head->next->next = head;
  head->next = NULL;
  return sHead;
}

void reverse(node *&head){
  node* prev = NULL;
  node*current = head;
  node*temp;

  while(current!=NULL){
    //store next
    temp = current->next;
    //update the current
    current ->next = prev;

    //prev and current
    prev = current;
    current = temp;
  }
  head = prev;
  return;
}

void printLL(node *head){
  while(head!=NULL){
    cout<<head->data<<"-->";
    head = head->next;
  }
  cout<<endl;
}


int main(){

node* head = NULL;
insertAtHead(head,4);
insertAtHead(head,3);
insertAtHead(head,2);
insertAtHead(head,1);
insertAtHead(head,0);

inserInMiddle(head,100,3);

insertAtTail(head,5);
printLL(head);

//head = recReverse(head);
reverse(head);
printLL(head);
return 0;
}
