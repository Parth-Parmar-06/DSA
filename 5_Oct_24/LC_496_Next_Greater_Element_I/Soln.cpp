#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1);
        stack<int> st;
        for (int i=n2-1; i>=0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();
            if (st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int i=0; i<n1; i++) {
            ans[i] = mpp[nums1[i]];
        } return ans;
    }
};
int main() {
    vector<int> nums1 = {2,4};
    vector<int> nums2 = {1,2,3,4};
    Solution obj;
    vector<int> ans = obj.nextGreaterElement(nums1, nums2);
    cout << "Answer: [ ";
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << "]";
}
