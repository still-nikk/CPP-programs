#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = NULL;
    }
};

void traverse(node* head, int pos){
    node* temp = head;
    int count = 1;
    while(temp -> next != NULL && count != pos){
        temp = temp -> next;
        count++;
    }
    if(count < 0){
        cout<<"Invalid Input"<<endl;
    }
    else{
        cout<<"The value at "<<pos<<" is "<<temp -> data<<endl;
    }
}

void insertatend(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = n;
}

void insertatbegin(node* &head, int val){
    node* n = new node(val);
    n -> next = head;
    head = n;
}

void insertatposition(node* head, int val, int position){
    position--;
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    node* newNode = new node(val);
    if (position == 0 || head == NULL) {
        newNode->next = head;
        head = newNode;
        return;
    }
    node *p = head;
    for (int i = 0; i < position - 1 && p != NULL; ++i) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    newNode->next = p->next;
    p->next = newNode;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void sortlist(node* head, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1; j++){
            
        }
    }
}

int main(){
    node* head = NULL;
    insertatend(head,1);
    insertatend(head,3);
    insertatbegin(head,0);
    insertatposition(head,2,3);
    display(head);
    traverse(head,2);
    return 0;
}