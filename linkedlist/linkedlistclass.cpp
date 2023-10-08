#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertatbegin(node* &head, int val)
{
    node* temp = new node(val);
    temp -> next = head;
    head = temp;
}

void insertatend(node* &head, int val)
{
    if(head == NULL)
    {
        return insertatbegin(head,val);
    }
    node* newnode = new node(val);
    node* temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newnode;
}

void insertatpos(node* &head, int pos , int val)
{
    if(pos == 0 || pos < 0)
    {
        cout<<"Invalid position"<<endl;
    }
    pos--;
    int count = 1;
    node* temp = head;
    node* newnode = new node(val);
    while(temp -> next != NULL && count != pos)
    {
        count++;
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void deletebegin(node* &head)
{
    if(head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    node* temp = head;
    head = temp -> next;
    free(temp);
}

void deleteend(node* &head)
{
    if(head == NULL)
    {
        cout << "Empty List" << endl;
        return;
    }
    node* temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = NULL;
    free(temp -> next);
}

void deleteatpos(node* &head,int pos)
{   
    if(pos == 0 || pos < 0)
    {
        cout << "Invalid Input" << endl;
        return;
    }
    if(pos == 1)
    {
        return deletebegin(head);
    }
    pos--;
    int count = 1;
    node* temp = head;
    while(temp -> next != NULL && count != pos)
    {
        count++;
        temp = temp -> next;
    }
    temp -> next = temp -> next -> next;
    free(temp -> next);
}

void display(node* head)
{
    node* temp = head;
    cout << "[ ";
    while(temp != NULL)
    {
        cout << temp -> data << " -> ";
        temp = temp -> next; 
    }
    cout << "NULL ]"<<endl;
}

void reverse(node* &head)
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
}

node* recursivereverse(node* &head) //I do not get it..?
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    node* newhead = recursivereverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return newhead;
}

void merge(node* &head, node* &head2)
{
    node* temp1 = head;
    node* temp2 = head2;
    while(temp1 -> next != NULL)
    {
        temp1 = temp1 -> next;
    }
    temp1 -> next = head2;
}

void searchelem(node* &head, int val)
{
    int count = 1;
    int c = 0;
    node* temp = head;
    while(temp -> next != NULL && temp -> data != val)
    {
        // if(temp -> data == val)
        // {
        //     c++;
        // }
        temp = temp -> next;
        count++;
    }
    if(temp -> data != val)
    {
        cout << "The searched element was not foung!" << endl;
    }
    else
    {
        cout << val<<" was found at position "<<count<<endl;
    }
}

void bubbleSortDescending(node* &head)
{
    if (head == NULL || head->next == NULL)
    {
        // Nothing to sort for an empty list or a list with a single element
        return;
    }

    bool swapped;
    node* temp;
    node* end = NULL;

    while (true)
    {
        swapped = false;
        temp = head;

        while (temp->next != end)
        {
            if (temp->data < temp->next->data)
            {
                // Swap data values of adjacent nodes
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;
                swapped = true;
            }
            temp = temp->next;
        }

        if (!swapped)
        {
            // If no elements were swapped in this pass, the list is sorted
            break;
        }

        end = temp; // Mark the last swapped node as the new end
    }
}

int main()
{
    node* head = NULL;
    insertatbegin(head,1);
    insertatbegin(head,0);
    insertatend(head,3);
    insertatpos(head,3,2);
    display(head);
    reverse(head);
    display(head);
    reverse(head);
    display(head);
    searchelem(head,2);
    bubbleSortDescending(head);
    display(head);
    // deletebegin(head);
    // display(head);
    // deleteend(head);
    // display(head);
    // deleteatpos(head,2);
    // display(head);
    node* head2 = NULL;
    insertatbegin(head2,5);
    insertatbegin(head2,4);
    insertatend(head2,7);
    insertatpos(head2,3,6);
    display(head2);
    merge(head,head2);
    display(head);
    display(head2);
    return 0;
}