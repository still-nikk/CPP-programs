#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int val){
        next = NULL;
        data = val;
        prev = NULL;
    }
};

void insertatend(node* &head, int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> prev = temp;
    newnode -> next = NULL;
}

void insertatbegin(node* &head, int val){
    node* newnode = new node(val);
    newnode -> data = val;
    newnode -> next = head;
    newnode -> prev = NULL;
    head = newnode;
}

void insertatpos(node* &head, int val, int pos)
{
    int count = 1;
    if(count == )
    {

    }
}

void display(node* head){
    node* temp = head;
    cout<<"[ ";
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL ]"<<endl;
}
int main(){
    node* head = NULL;
    insertatend(head,2);
    insertatend(head,3);
    display(head);
    insertatbegin(head,1);
    display(head);
    return 0;
}