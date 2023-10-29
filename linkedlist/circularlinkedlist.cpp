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

// Function to insert a node at the beginning of a circular linked list
void insertAtBegin(node* &head, int val)
{
    node* newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end of a circular linked list
void insertAtEnd(node* &head, int val)
{
    if (head == NULL)
    {
        insertAtBegin(head, val);
        return;
    }
    node* newNode = new node(val);
    node* temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

// Function to delete a node with a specific value
void deleteNode(node* &head, int val)
{
    if (head == NULL)
    {
        cout << "Circular Linked List is empty." << endl;
        return;
    }

    node* current = head;
    node* previous = NULL;

    while (current->data != val)
    {
        if (current->next == head)
        {
            cout << "Element not found in the list." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }

    if (current == head)
    {
        // If the node to be deleted is the head of the list
        node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
    }
    else
    {
        previous->next = current->next;
    }

    delete current;
}

// Function to reverse a circular linked list
void reverseList(node* &head)
{
    if (head == NULL || head->next == head)
    {
        return;
    }

    node* prev = NULL;
    node* current = head;
    node* nextNode;

    do
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);

    head->next = prev;
    head = prev;
}

// Function to concatenate two circular linked lists
void concatenateLists(node* &head1, node* &head2)
{
    if (head1 == NULL)
    {
        head1 = head2;
    }
    else if (head2 != NULL)
    {
        node* temp = head1;
        while (temp->next != head1)
        {
            temp = temp->next;
        }
        temp->next = head2;
        temp = head2;
        while (temp->next != head2)
        {
            temp = temp->next;
        }
        temp->next = head1;
    }
}

// Function to display the circular linked list
void display(node* head)
{
    if (head == NULL)
    {
        cout << "Circular Linked List is empty." << endl;
        return;
    }
    node* temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << " (Back to Head)" << endl;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    cout << "Menu: " << endl;
    cout << "********************************" << endl;
    cout << "1. Insert at the beginning" << endl;
    cout << "2. Insert at the end" << endl;
    cout << "3. Delete a node" << endl;
    cout << "4. Reverse the list" << endl;
    cout << "5. Concatenate lists" << endl;
    cout << "6. Display" << endl;
    cout << "7. Exit" << endl;
    int selection;
    cin >> selection;
    while (selection != 7)
    {
        switch (selection)
        {
            case 1:
            {
                cout << "Enter the value to insert at the beginning: ";
                int elem;
                cin >> elem;
                insertAtBegin(head1, elem);
                break;
            }
            case 2:
            {
                cout << "Enter the value to insert at the end: ";
                int elem;
                cin >> elem;
                insertAtEnd(head1, elem);
                break;
            }
            case 3:
            {
                cout << "Enter the value to delete: ";
                int elem;
                cin >> elem;
                deleteNode(head1, elem);
                break;
            }
            case 4:
            {
                reverseList(head1);
                cout << "Reversed the list." << endl;
                break;
            }
            case 5:
            {
                cout << "Concatenating two lists." << endl;
                concatenateLists(head1, head2);
                break;
            }
            case 6:
            {
                cout << "Circular Linked List: ";
                display(head1);
                break;
            }
        }
        cout << "Menu: " << endl;
        cout << "********************************" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Reverse the list" << endl;
        cout << "5. Concatenate lists" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cin >> selection;
    }
    return 0;
}
