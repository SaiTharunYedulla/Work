#include <stack>
#include <iostream> 
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // Opening brackets
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                // If stack empty → invalid
                if(st.empty()) return false;

                // Check matching
                if(s[i] == ')' && st.top() != '(') return false;
                if(s[i] == '}' && st.top() != '{') return false;
                if(s[i] == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        // Stack must be empty at end
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "()[]{}";
    cout << sol.isValid(s) << endl; // 1 (true)
    s = "([)]";
    cout << sol.isValid(s) << endl; // 0 (false)
    s = "{[]}";
    cout << sol.isValid(s) << endl; // 1 (true)
    return 0;
}