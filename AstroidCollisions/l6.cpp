#include <vector>
#include <stack>  
#include <iostream>  
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int a : asteroids){
            bool destroyed = false;

            while(!st.empty() && a < 0 && st.top() > 0){
                
                if(st.top() < -a){
                    st.pop();               // stack asteroid explodes
                    continue;
                }
                else if(st.top() == -a){
                    st.pop();               // both explode
                }

                destroyed = true;
                break;
            }

            if(!destroyed){
                st.push(a);
            }
        }

        vector<int> ans(st.size());
        for(int i = st.size()-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = sol.asteroidCollision(asteroids);
    for(int a : ans){
        cout << a << " ";
    }
    cout << endl;
    return 0;
}   