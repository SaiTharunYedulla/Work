#include <iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // ENQUEUE
    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1) {   // first element
            front = 0;
        }

        rear++;
        arr[rear] = x;
        cout << x << " inserted into queue\n";
    }

    // DEQUEUE
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << arr[front] << " removed from queue\n";
        front++;

        // reset when queue becomes empty
        if (front > rear) {
            front = rear = -1;
        }
    }

    // FRONT element
    void peek() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element is " << arr[front] << endl;
    }

    // DISPLAY queue
    void display() {
        if (front == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    q.peek();

    q.dequeue();
    q.peek();
    q.display();

    return 0;
}
