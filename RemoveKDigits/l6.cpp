#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char c : num) {
            while(!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // If still digits left to remove
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build result
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int i = 0;
        while(i < res.size() && res[i] == '0') i++;
        res = res.substr(i);

        if(res == "") return "0";
        return res;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;
    cout << sol.removeKdigits(num, k) << endl; // Output: "1219"
    return 0;
}