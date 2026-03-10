#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    stack<int> st, minStack;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);

        // If minStack empty or new val <= current min
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (st.top() == minStack.top()) {
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl; // -3
    s.pop();
    cout << s.top() << endl; // 0
    cout << s.getMin() << endl; // -2
    return 0;
}