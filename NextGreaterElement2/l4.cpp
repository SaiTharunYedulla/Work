#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans (n, -1);    // initialize the answer vector with -1, so that we don't have to worry about the case when there is no greater element.
        stack<int> st;
        for(int i = (2*n) - 1 ; i >=0 ; i--){       // just assume that the array is copied but access it with %..
            while(!(st.empty()) && st.top() <= nums[i%n]){
                st.pop();
            }
            if(st.empty()){
                ans[i%n] = -1;
            } else {
                ans[i%n] = st.top();
            }
            st.push(nums[i%n]);
        }

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,1};
    vector<int> ans = sol.nextGreaterElements(nums);
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}