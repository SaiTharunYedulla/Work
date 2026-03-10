#include <iostream>
using namespace std;

#define MAX 5   // stack size

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;  // stack is empty
    }

    // PUSH operation
    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed into stack\n";
    }

    // POP operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << arr[top] << " popped from stack\n";
        top--;
    }

    // PEEK operation
    void peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element is " << arr[top] << endl;
    }

    // DISPLAY stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();
    s.display();

    s.pop();
    s.display();
    s.peek();
    s.display();

    return 0;
}
