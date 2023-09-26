// #include<bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node *next;

//     Node(int data) {
//         this->data = data;
//         this->next = nullptr;
//     }
// };

// class LinkedList {
// private:
//     Node *head;

// public:
//     LinkedList() {
//         head = nullptr;
//     }

//     void printlist() {
//         Node *p = head;
//         cout << "[";
//         while (p != nullptr) {
//             cout << " " << p->data << " ";
//             p = p->next;
//         }
//         cout << "]";
//     }

//     void revlist(Node *node) {
//         if (node == nullptr) {
//             return;
//         }
//         revlist(node->next);
//         cout << node->data << "  ";
//     }

//     void insertatbegin(int data) {
//         Node *newNode = new Node(data);
//         newNode->next = head;
//         head = newNode;
//     }

//     void insertatend(int data) {
//         Node *newNode = new Node(data);
//         if (head == nullptr) {
//             head = newNode;
//             return;
//         }
//         Node *p = head;
//         while (p->next != nullptr) {
//             p = p->next;
//         }
//         p->next = newNode;
//     }

//     void insertatposition(int data, int position) {
//         position--;
//         if (position < 0) {
//             cout << "Invalid position." << endl;
//             return;
//         }
//         Node *newNode = new Node(data);
//         if (position == 0 || head == nullptr) {
//             newNode->next = head;
//             head = newNode;
//             return;
//         }
//         Node *p = head;
//         for (int i = 0; i < position - 1 && p != nullptr; ++i) {
//             p = p->next;
//         }
//         if (p == nullptr) {
//             cout << "Position out of range." << endl;
//             return;
//         }
//         newNode->next = p->next;
//         p->next = newNode;
//     }

//     void deletefrombegin() {
//         if (head == nullptr) {
//             cout << "List is already empty." << endl;
//             return;
//         }
//         Node *temp = head;
//         head = head->next;
//         delete temp;
//     }

//     void deleteatend() {
//         if (head == nullptr) {
//             cout << "List is already empty." << endl;
//             return;
//         }
//         if (head->next == nullptr) {
//             delete head;
//             head = nullptr;
//             return;
//         }
//         Node *p = head;
//         while (p->next->next != nullptr) {
//             p = p->next;
//         }
//         delete p->next;
//         p->next = nullptr;
//     }

//     void deleteatposition(int position) {
//         if (position < 0 || head == nullptr) {
//             cout << "Invalid position or empty list." << endl;
//             return;
//         }
//         if (position == 0) {
//             Node *temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }
//         Node *p = head;
//         Node *prev = nullptr;
//         for (int i = 0; i < position && p != nullptr; ++i) {
//             prev = p;
//             p = p->next;
//         }
//         if (p == nullptr) {
//             cout << "Position out of range." << endl;
//             return;
//         }
//         prev->next = p->next;
//         delete p;
//     }

//     ~LinkedList() {
//         Node *current = head;
//         while (current != nullptr) {
//             Node *nextNode = current->next;
//             delete current;
//             current = nextNode;
//         }
//         head = nullptr;
//     }
// };

// int main() {
//     LinkedList linkedList;
//     linkedList.insertatend(50);
//     linkedList.insertatbegin(44);
//     linkedList.insertatbegin(30);
//     linkedList.insertatbegin(22);
//     linkedList.insertatbegin(12);
//     linkedList.insertatposition(28, 3);
//     linkedList.deletefrombegin();
//     linkedList.deleteatend();
//     linkedList.deleteatposition(3);
    
//     cout << "Linked list: " << endl;
//     linkedList.printlist();
//     cout << endl << endl << endl;
    
//     cout << "Reversed list: " << endl;
//     cout << "[  ";
//     linkedList.revlist(linkedList.head);
//     cout << "]";
    
//     return 0;
// }


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