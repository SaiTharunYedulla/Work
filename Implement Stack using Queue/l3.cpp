#include <queue>
#include <iostream>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() > 1){
            int el = q1.front();
            q1.pop();
            q2.push(el);
        }
        int el1 = q1.front();
        q1.pop();
        swap(q1,q2);
        return el1;
    }
    
    int top() {
        while(q1.size() > 1){
            int el = q1.front();
            q1.pop();
            q2.push(el);
        }
        int el = q1.front();
        q2.push(el);
        q1.pop();
        swap(q1,q2);
        return el;
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // 3
    cout << s.pop() << endl; // 3
    cout << s.top() << endl; // 2
    cout << s.empty() << endl; // 0 (false)
    return 0;
}