#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Push element
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
        cout << x << " pushed to stack\n";  
    }

    // Pop element
    int pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return -1;
        }

        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    // Get top element
    int peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check empty
    bool isEmpty() {
        return top == NULL;
    }
};

// Driver code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.peek() << endl;   // 30
    cout << "Pop: " << s.pop() << endl;    // 30
    cout << "Top: " << s.peek() << endl;   // 20

    return 0;
}
