#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node*head = NULL;
struct node* head2 = NULL;
struct node*current = NULL;

void printlist(){
    struct node *p = head;
    cout<<"[";
    while (p != NULL){
        cout<<" "<<p->data<<" ";
        p = p->next;
    }
    cout<<"]";
}

void revlist(struct node*head){ // ye to cheating hai bhai xD, This function only prints the value in reverse it does not reverse the elements in a linked list.
    if(head == NULL){
        return;
    }
    revlist(head->next);
    cout<<head->data<<"  ";
}

int traverse(int pos){
    struct node* temp = head;
    int count = 1;
    while(temp -> next != NULL && count != pos){
        temp = temp -> next;
        count++;
    }
    return temp -> data;
}

void insertatbegin(int data){
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}

void insertatend(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

void insertatposition(int data, int position) {
    position--;
    if (position < 0) {
        cout << "Invalid position." << endl;
        return;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    if (position == 0 || head == NULL) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node *p = head;
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

void deletefrombegin() {
    if (head == NULL) {
        cout<<"List is already empty."<<endl;
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteatend() {
    if (head == NULL) {
        cout << "List is already empty." << endl;
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct node *p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
}

void deleteatposition(int position) {
    if (position < 0 || head == NULL) {
        cout << "Invalid position or empty list." << endl;
        return;
    }
    if (position == 0) {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct node *p = head;
    struct node *prev = NULL;
    for (int i = 0; i < position && p != NULL; ++i) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Position out of range." << endl;
        return;
    }
    prev->next = p->next;
    free(p);
}

void sort(int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size - 1 ; j++){
            struct node* newNode = (struct node *)malloc(sizeof(struct node));
            struct node* newNode2 = (struct node *)malloc(sizeof(struct node));
            
        }
    }
}

int main(){
    int k = 0;
    insertatend(50);
    insertatbegin(44);
    insertatbegin(30);
    insertatbegin(22);
    insertatbegin(12);
    insertatposition(28,3);
    deletefrombegin();
    deleteatend();
    deleteatposition(3);
    cout<<"Linked list: "<<endl;
    printlist();
    cout<<endl<<endl<<endl;
    cout<<"Reversed list: "<<endl;
    cout<<"[  ";
    revlist(head);
    cout<<"]"<<endl;
    cout<<"The value at 2 is "<<traverse(2)<<endl;
    return 0;
}