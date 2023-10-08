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
    newnode -> next = head;
    newnode -> prev = NULL;
    head = newnode;
}

void insertatpos(node* &head, int val, int pos)
{
    pos--;
    int count = 1;
    if(pos == 0 )
    {
        return insertatbegin(head,val);
    }
    node* temp = head;
    while(temp->next != NULL && count != pos)
    {
        temp = temp -> next;
        count++;
    }
    node* newnode = new node(val);
    newnode -> next = temp -> next;
    newnode -> prev = temp;
    temp -> next = newnode;
    temp -> next -> prev = newnode;
}

void deleteatbegin(node* &head)
{
    node* temp = head;
    temp -> next -> prev = NULL;
    head = temp -> next;
    free(temp);
}

void deleteatend(node* &head)
{
    if(head == NULL || head -> next == NULL)
    {
        return deleteatbegin(head);
    }
    node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
}

void deleteval(node* &head, int val)
{
    if(head -> data == val)
    {
        return deleteatbegin(head);
    }
    node* temp = head;
    while(temp -> data != val && temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;
    free(temp);
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

void reverseList(node* &head) {
    node* current = head;
    node* temp = NULL;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
}

void concatenateLists(node* &head, node* &head2) {
    if (head == NULL) {
        head = head2;
    } else if (head2 != NULL) {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
        head2->prev = temp;
    }
}

void sortList(node* &head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    node *current, *index;
    int temp;
    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}

int searchElement(node* head, int val) {
    int index = 0;
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == val) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // Element not found
}

void deleteDuplicates(node* &head) {
    if (head == NULL || head->next == NULL) {
        return; // No duplicates to delete in an empty or single-element list.
    }

    node* current = head;

    while (current != NULL) {
        node* runner = current;

        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // Duplicate found, delete the duplicate node.
                node* duplicate = runner->next;
                runner->next = runner->next->next;

                if (runner->next != NULL) {
                    runner->next->prev = runner;
                }

                free(duplicate);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}


void unionlist(node* &head, node* &head2)
{
    node* temp = head;
    node* temp2 = head2;
    node* head3 = NULL;
    bool count = false;
    while(temp != NULL)
    {
        insertatend(head3,temp->data);
        temp = temp -> next;
    }
    // while(temp -> next != NULL)
    // {
    //     while(temp2 -> next != NULL)
    //     {
    //         if(temp -> data == temp2 -> data)
    //         {
    //             count = true;
    //         }
    //         temp2 = temp2 -> next;
    //     }
    //     if(count == false)
    //     {
    //         insertatbegin(head3 , temp2 -> data);
    //     }
    //     temp2 = head2;
    //     insertatbegin(head3,temp -> data);
    //     temp = temp -> next;
    // }
    // insertatbegin(head3,temp -> data);
    temp = head;
    while(temp2 != NULL)
    {
        while(temp != NULL)
        {
            if(temp2 -> data == temp -> data)
            {
                count = true;
            }
            temp = temp -> next;
        }
        if(count == false)
        {
            insertatbegin(head3 , temp2 -> data);
        }
        temp = head;
        count = false;
        temp2 = temp2 -> next;
    }
    sortList(head3);
    display(head3);
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
    sortList(head3);
    // deleteDuplicates(head3);
    display(head3);
}

int main(){
    node* head = NULL;
    insertatend(head,2);
    // insertatend(head,3);
    // display(head);
    // insertatbegin(head,1);
    // display(head);
    // insertatpos(head,4,2);
    // display(head);
    // deleteatend(head);
    // display(head);
    // deleteatbegin(head);
    // display(head);
    // deleteval(head,4);
    // display(head);
    insertatpos(head,1,1);
    insertatpos(head,3,3);
    insertatpos(head,4,4);
    cout<<"List 1: ";
    display(head);
    // traversal(head);
    node* head2 = NULL;
    insertatbegin(head2,5);
    insertatbegin(head2,3);
    insertatend(head2,4);
    insertatend(head2,6);
    cout<<endl<<"List 2: ";
    display(head2);
    // concatenateLists(head,head2);
    // display(head);
    cout<<endl<<"Union List: ";
    unionlist(head,head2);
    cout<<endl<<"Instersection List: ";
    intersectlist(head,head2);
    return 0;
}