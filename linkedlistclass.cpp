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


void deletebegin(node* &head){
    node* temp = head;
    if(temp == NULL){
        cout << "The list is already empty!" << endl;
        return;
    }
    head = temp -> next;
    free(temp);
}

void deleteend(node* &head){
    node* temp = head;
    if(temp == NULL){
        cout << "The list is empty!" << endl;
        return;
    }
    while(temp -> next -> next != NULL){
        temp = temp->next;
    }
    free(temp -> next);
    temp -> next = NULL;
}

void deletevalue(node* &head, int val){
    node* temp = head;
    while(temp -> next -> data != val){
        temp = temp -> next;
    }
    node* del = temp -> next;
    temp -> next = temp -> next -> next; //we could also use del -> next instead of temp -> next -> next;
    free(del); //We could also use delete() here instead of free();
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp -> next;
    }
    cout<<"NULL"<<endl;
}

void iterativereverse(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* nextpt;

    while(curr != NULL)
    {
        nextpt = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = nextpt;
    }
    head = prev;
}

node* recursivereverse(node* &head) //I do not get it..?
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node* newnode = recursivereverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newnode;
}

void sortlist(node* head, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - 1; j++)
        {

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
    iterativereverse(head);
    display(head);
    traverse(head,2);
    // deletevalue(head,2);
    // display(head);
    // deleteend(head);
    // display(head);
    node* newhead = recursivereverse(head); // this bs works but how...?
    display(newhead);
    return 0;
}