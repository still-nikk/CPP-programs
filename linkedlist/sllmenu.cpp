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
    node* head2 = NULL;
    insertatbegin(head2,5);
    insertatbegin(head2,4);
    insertatend(head2,7);
    insertatpos(head2,3,6);
    node* head = NULL;
    cout << "Menu: " << endl;
    cout << "******************************** "<< endl;
    cout << "\n    1.Insert in beginning \n    2.Insert at last\n    3.Insert at any random location\n    4.Delete from Beginning\n    5.Delete from last\n    6.Delete node after specified location\n    7.Reverse linked list\n    8.Concatenate linked lists\n    9.Display\n    10.Exit\n";
    int selection;
    cin >> selection;
    while(selection < 10)
    {
        switch(selection)
        {
            case 1: 
            {
                cout << "Enter the value to enter at the beginning: ";
                int elem;
                cin >> elem;
                insertatbegin(head,elem);
                break;
            }
            case 2: 
            {
                cout << "Enter the value: ";
                int elem;
                cin >> elem;
                insertatend(head,elem);
                break;
            }
            case 3: 
            {
                cout << "Enter the value: ";
                int elem;
                cin >> elem;
                cout << "Enter the position: ";
                int pos;
                cin >> pos;
                insertatpos(head,pos,elem);
                break;
            }
            case 4: 
            {
                cout << "Deleted first element! " << endl;
                deletebegin(head);
                break;
            }
            case 5: 
            {
                cout << "Deleted last element! " << endl;
                deleteend(head);
                break;
            }
            case 6: 
            {
                cout << "enter the position of the element to delete: ";
                int elem;
                cin >> elem;
                deleteatpos(head,elem);
                break;
            }
            case 7:
            {
                reverse(head);
                cout << "Reversed the list, The new list is as following: " << endl;
                display(head);
                break;
            }
            case 8:
            {
                cout << "Merged a sample list to the original list: "<< endl;
                merge(head,head2);
                break;
            }
            case 9:
            {
                cout << "Displaying the list: "<< endl;
                display(head);
                break;
            }
        }
        cout << "Menu: " << endl;
        cout << "******************************** "<< endl;
        cout << "1.Insert in beginning \n    2.Insert at last\n    3.Insert at any random location\n    4.Delete from Beginning\n    5.Delete from last\n    6.Delete node after specified location\n    7.Reverse linked list\n    8.Concatenate linked lists\n    9.Display\n    10.Exit\n";
        cin >> selection;
    }
    return 0;
}