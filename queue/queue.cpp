#include <bits/stdc++.h>
using namespace std;    
#define MAX_SIZE 4

class Queue {
private:
    // static const int MAX_SIZE = 4;
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue() {
        front = rear = -1;
        count = 0;
    }

    void enqueue(int element) {  //same as push in stack
        if (count == MAX_SIZE) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else {
            rear = (rear + 1) % MAX_SIZE;
            arr[rear] = element;
            count++;
            cout << "Enqueued " << element << " in the queue." << endl;
        }
    }

    void dequeue() {  //same as pop in stack
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
        } else {
            cout << "Dequeued " << arr[front] << " from the queue." << endl;
            front = (front + 1) % MAX_SIZE;
            count--;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    bool isPresent(int element) {
        for (int i = front; i <= rear; i = (i + 1) % MAX_SIZE) {
            if (arr[i] == element) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Queue myQueue;

    cout << "Enter 00 if you want to exit!" << endl;
    cout << "Enqueue the elements: " << endl;
    for (int i = 0;; i++) {
        int val;
        cin >> val;
        if (val == 00) {
            break;
        }
        myQueue.enqueue(val);
    }

    cout << "Is the queue full? " << (myQueue.isFull() ? "Yes" : "No") << endl;
    if (myQueue.isPresent(4)) {
        cout << "4 is present" << endl;
    } else {
        cout << "4 is not present" << endl;
    }
    cout << "Front element: " << myQueue.peek() << endl;
    myQueue.dequeue();
    myQueue.dequeue();
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    myQueue.dequeue();
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    myQueue.dequeue();
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}