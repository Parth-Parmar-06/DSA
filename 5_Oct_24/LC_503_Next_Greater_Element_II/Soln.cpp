#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);
        for (int i=n-1; i>=0; i--) {
            st.push(nums[i]);
        }
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && st.top()<=nums[i]) st.pop();
            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(nums[i]);
        } return ans;
    }
};
int main() {
    vector<int> nums = {1,8,-1,-100,-1,222,1111111,-111111};
    Solution obj;
    vector<int> ans = obj.nextGreaterElements(nums);
    cout << "Answer: [ ";
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << "]" << endl;
}
