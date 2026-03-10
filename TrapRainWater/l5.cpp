#include <bits/stdc++.h>
using namespace std;    


// class Solution {
// public:
//     int trap(vector<int>& height) {
        
//         int n = height.size();
//         vector<int> l(n);
//         vector<int> r(n);

//         l[0] = height[0];
//         r[n-1] = height[n-1];

//         for(int i = 1; i < height.size(); i++){
//             l[i] = max(l[i-1], height[i]);
//         }

//         for(int i = height.size()-2; i >= 0; i--){
//             r[i] = max(r[i+1], height[i]);
//         } 

//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             ans += min(l[i], r[i]) - height[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int l = 0;
        int r = n-1;
        int lmax = 0;
        int rmax = 0;
        int ans = 0;
        while(l <= r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);

            if(lmax < rmax){
                ans += lmax - height[l]; 
                l++;
            } else {
                ans += rmax - height[r];
                r--;
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height) << endl;
}
