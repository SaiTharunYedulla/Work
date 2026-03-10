#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mp;   // element -> next greater
        
        // Process nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; i--) {
            
            // Remove smaller or equal elements
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            
            // If stack empty → no greater element
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } 
            else {
                mp[nums2[i]] = st.top();
            }
            
            // Push current element
            st.push(nums2[i]);
        }
        
        // Build answer for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(mp[num]);
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for (int x : ans) {
        cout << x << " "; // -1 -1 3
    }
    cout << endl;
    return 0;
}