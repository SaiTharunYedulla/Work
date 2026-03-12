#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    long long subArrayMin(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ple(n), nle(n);

        // Previous Less Element
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            ple[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Less Element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left = i - ple[i];
            long long right = nle[i] - i;
            sum += (long long)nums[i] * left * right;
        }

        return sum;
    }

    long long subArrayMax(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pge(n), nge(n);

        // Previous Greater Element
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater Element
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sum = 0;

        for(int i = 0; i < n; i++){
            long long left = i - pge[i];
            long long right = nge[i] - i;
            sum += (long long)nums[i] * left * right;
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) - subArrayMin(nums);
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    cout << sol.subArrayRanges(nums) << endl; // Output: 4
    return 0;
}