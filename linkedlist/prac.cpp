#include<iostream>
#include<vector>
#include<list>
using namespace std;

class node
{
    int data;
    node* next;
    public:
    node(int val):
    data(val), next(NULL){}
    node() : data() {}

    friend void insertatbegin(node* &head , int val);
    friend void insertatend(node* &head, int val);
    friend void insertatpos(node* &head, int val , int pos);
    friend void deletebegin(node* &head);
    friend void display(node* &head);
};

void insertatbegin(node* &head , int val)
{
    node* newnode = new node(val);
    newnode -> next = head;
    head = newnode;
}

void insertatend(node* &head, int val)
{
    node* newnode = new node(val);
    if(head == NULL)
    {
        cout << "List is empty! Inserted " << val << " at beginning." << endl;
        return insertatbegin(head, val);
    }
    node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    // newnode -> next = NULL;
}

void insertatpos(node* &head , int val , int pos)
{
    if(pos < 0)
    {
        cout << "Invalid position! "<< endl;
        return;
    }
    if(pos == 1)
    {
        return insertatbegin(head,val);
    }
    pos --;
    int count = 1;
    node* newnode = new node(val);
    node* temp = head;
    while (temp -> next != NULL && count != pos)
    {
        temp = temp -> next;
        count ++;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void deletebegin(node* &head)
{
    node* temp = head;
    head = temp -> next;
    delete(temp);
}

void display(node* &head)
{
    cout << "Displaying list: [ ";
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << "NULL ]" << endl;
}

int main()
{
    node* head(NULL);
    insertatbegin(head,2);
    insertatend(head,4);
    insertatbegin(head,1);
    insertatpos(head,3,3);
    insertatbegin(head,0);
    deletebegin(head);
    display(head);
    return 0;
}