#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    char data;
    node* next;
    node* prev;

    node(char val){
        next = NULL;
        data = val;
        prev = NULL;
    }
};

void traversal(node* &head)
{
    node* temp = head;
    int count = 0;
    cout << "[ ";
    while(temp != NULL)
    {
        count ++;
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL ]" << endl;
    cout << "The total number of elements in the list excluding NULL are "<< count << endl;
}

void insertatend(node* &head, char val){
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

void insertatbegin(node* &head, char val){
    node* newnode = new node(val);
    newnode -> next = head;
    newnode -> prev = NULL;
    head = newnode;
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

void intersectlist(node* &head, node* &head2)
{
    node* temp = head;
    node* temp2 = head2;
    node* head3 = NULL;
    bool count = false;
    while(temp != NULL)
    {
        while(temp2 != NULL)
        {
            if(temp -> data == temp2 -> data)
            {
                count = true;
            }
            temp2 = temp2 -> next;
        }
        if(count == true)
        {
            insertatbegin(head3 , temp -> data);
        }
        temp2 = head2;
        count = false;
        temp = temp -> next;
    }
    display(head3);
}

int main()
{
    node* head = NULL;
    node* head2 = NULL;
    insertatbegin(head,'d');
    insertatend(head,'e');
    insertatend(head,'f');
    insertatend(head2,'e');
    insertatend(head2,'g');
    insertatend(head2,'z');
    cout << "Intersection List: ";
    intersectlist(head,head2);
    return 0;
}