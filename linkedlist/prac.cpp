#include<bits/stdc++.h>
using namespace std;

class node
{
    int data;
    node* next;
    public:
    node(int val)
    {
        data = val;
        next = NULL;
    }

    //Function List
    void display(node* head);
    void insertatend(node* &head , int val);
    void insertatbegin(node* &head , int val);
    void insertatpos(node* &head);
    void deleteatbegin(node* &head);
    void deleteatend(node* &head);
    void deleteatpos(node* &head);
    void reverse(node* &head);
    void merge(node* &head,node* &head2);
};

void node :: display(node* head)
{
    node* temp = head;
    cout << "[ ";
    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL ]" << endl;
}

void node ::  insertatbegin(node* &head , int val)
{
    node* temp = head;
    node* newnode = new node(val);
    newnode -> next = temp;
    head = newnode;
    cout << " Inserted " << val << " as the First node."<<endl;
}

void node :: insertatend(node* &head , int val)
{

    if (head == NULL)
    {
        cout << "List was empty! Inserted " << val <<" at First node." << endl;
        node* newnode = new node(val);
        // newnode -> next = NULL;
        head = newnode;
        return;
        // return insertatbegin(head,val);
    }

    node* temp = head;

    node* newnode = new node(val);
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
    newnode -> next = NULL;
    cout << " Inserted " << val << " as the last node."<<endl;
}

void node :: insertatpos(node* &head)
{
    cout << "Enter the value you want to insert: ";
    int val;
    cin >> val;
    cout << "Enter the position you want to insert at: ";
    int pos;
    cin >> pos;

    if(pos <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if(pos == 1)
    {
        insertatbegin(head,val);
        return;
    }

    pos --;
    int count = 1;

    node* temp = head;

    while(temp -> next != NULL && count != pos)
    {

        temp = temp -> next;
        count ++;
    }

    node* newnode = new node(val);
    newnode -> next = temp -> next;
    temp -> next = newnode;
    pos ++;
    cout << "Inserted "<< val << " at " << pos << endl;
}

void node :: deleteatbegin(node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty haha! " << endl;
        return;
    }

    node* temp = head;
    head = head -> next;
    free(temp);
    cout << "Deleted the First node!" << endl;
}

void node :: deleteatend(node* &head)
{
    if(head == NULL)
    {
        cout << "List is empty haha! " << endl;
        return;
    }

    node* temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
    cout << "Deleted the last node! " << endl;
}

void node :: deleteatpos(node* &head)
{
    cout << "Enter the position of the element you want to delete: ";
    int pos;
    cin >> pos;

    if(pos <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    if(pos == 1)
    {
        deleteatbegin(head);
        return;
    }

    pos --;
    int count = 1;

    node* temp = head;
    while(temp -> next != NULL && count != pos)
    {
        temp = temp -> next;
        count ++;
    }
    node* temp2 = temp -> next;
    temp -> next = temp -> next -> next;
    pos++;
    cout << "Deleted " << temp2 -> data << " from " << pos << " position" << endl;
    free(temp2);
}

void node :: reverse(node* &head) 
{
    node* prevpt = NULL;
    node* currpt = head;
    node* nextpt;
    while(currpt != NULL)
    {
        nextpt = currpt -> next;
        currpt -> next = prevpt;
        prevpt = currpt;
        currpt = nextpt;
    }
    head = prevpt;
    cout << "The list has now been reversed." << endl;
}

void node :: merge(node* &head, node* &head2)
{
    node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = head2;
    cout << "Merged both lists. "<< endl;
}

int main()
{
    node* head = NULL;
    head -> insertatend(head,2);
    head -> insertatbegin(head,1);
    head -> display(head);
    head -> insertatend(head,3);
    head -> insertatend(head,4);
    head -> insertatend(head,6);
    head -> insertatbegin(head,0);
    head -> display(head);
    head -> insertatpos(head);
    head -> display(head);
    head -> deleteatbegin(head);
    head -> deleteatend(head);
    head -> display(head);
    head -> deleteatpos(head);
    head -> display(head);
    return 0;
}