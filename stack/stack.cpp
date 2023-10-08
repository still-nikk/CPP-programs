#include <iostream>
using namespace std; 

class Stack {
private:
    static const int MAX_SIZE = 4;
    int arr[MAX_SIZE];              
    int top;                        

public:
    Stack() {
        top = -1;
    }

    void push(int element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow " << endl;
        } 
        else {
            arr[++top] = element;
            cout << "Pushed " << element << " in the stack." << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } 
        else {
            cout << "Popped " << arr[top--] << " from the stack." << endl;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; 
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isPresent(int element) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Stack myStack;

    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);
    // myStack.push(4);
    // myStack.push(5);

    cout<<"Enter 00 if you want to exit!"<<endl;
    cout<<"Push the elements: "<<endl;
    for(int i = 0; ;i++)
    {
        int val;
        cin >> val;
        if(val == 00)
        {
            break;
        }
        myStack.push(val);
    }

    cout << "Is the stack full? " << (myStack.isFull() ? "Yes" : "No") << endl;
    if(myStack.isPresent(4) == true)
    {
        cout << "4 is present" << endl;
    }   
    else{
        cout << "4 is not present" << endl;
    }
    cout << "Top element: " << myStack.peek() << endl;
    myStack.pop();
    myStack.pop();
    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    myStack.pop();
    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    myStack.pop();
    cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}