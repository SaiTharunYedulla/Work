#include <stack>
#include <iostream> 
using namespace std;
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()){
            int el = s1.top();
            s1.pop();
            s2.push(el);
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int el = s1.top();
        s1.pop();
        return el;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl; // 1
    cout << q.pop() << endl; // 1
    cout << q.peek() << endl; // 2
    cout << q.empty() << endl; // 0 (false)
    return 0;
}