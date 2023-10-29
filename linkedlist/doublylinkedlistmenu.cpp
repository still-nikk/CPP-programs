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
        temp2 = head2;
        count = false;
        temp = temp -> next;
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
    display(head3);
}

int main(){
    node* head = NULL;
    node* head2 = NULL;
    int choice;
    int value;
    int pos;

    do {
        cout << "Circular Doubly Linked List Operations:" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert at a specific position" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete a specific value" << endl;
        cout << "7. Reverse the list" << endl;
        cout << "8. Concatenate two lists" << endl;
        cout << "9. Display the list" << endl;
        cout << "10. Find the union of two lists" << endl;
        cout << "11. Find the intersection of two lists" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to insert at the beginning: ";
                cin >> value;
                insertatbegin(head, value);
                break;

            case 2:
                cout << "Enter a value to insert at the end: ";
                cin >> value;
                insertatend(head, value);
                break;

            case 3:
                cout << "Enter a value to insert: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> pos;
                insertatpos(head, value, pos);
                break;

            case 4:
                deleteatbegin(head);
                break;

            case 5:
                deleteatend(head);
                break;

            case 6:
                cout << "Enter a value to delete: ";
                cin >> value;
                deleteval(head, value);
                break;

            case 7:
                reverseList(head);
                break;

            case 8:
                cout << "Creating a second list." << endl;
                cout << "Enter a value to insert at the beginning of the second list: ";
                cin >> value;
                insertatbegin(head2, value);
                cout << "Enter a value to insert at the end of the second list: ";
                cin >> value;
                insertatend(head2, value);
                concatenateLists(head, head2);
                cout << "Concatenated lists." << endl;
                break;

            case 9:
                display(head);
                break;

            case 10:
                unionlist(head, head2);
                break;

            case 11:
                intersectlist(head, head2);
                break;

            case 12:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 12);

    return 0;
}
