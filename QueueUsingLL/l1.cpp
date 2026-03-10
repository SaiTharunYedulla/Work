#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next; // next is a variable of type pointer which stores address of next node
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {} 
    Node(int val, Node* nxt) : data(val), next(nxt) {}  
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Enqueue element
    void enqueue(int x) {
        Node* newNode = new Node(x);
        if (rear == NULL) { // first element. Here we can write if (front == NULL) also..
            front = rear = newNode; 
            return;
        }

        rear->next = newNode; // link new node at the end of queue
        rear = newNode;
        cout << x << " inserted into queue\n";  
    }

    // Dequeue element
    int dequeue() {
        if (front == NULL) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int removedValue = front->data;
        Node* temp = front; // temporary pointer to hold the front node to delete it later and not lose its address
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout<< removedValue << " removed from queue\n";

        delete temp;
        return removedValue;
    }

    // Get front element
    int peek() {
        if (front == NULL) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return front->data;
    }

    // Check empty
    bool isEmpty() {
        return front == NULL;
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.peek() << endl;   // 10
    cout << "Dequeue: " << q.dequeue() << endl; // 10
    cout << "Front: " << q.peek() << endl;   // 20

    return 0;
}
