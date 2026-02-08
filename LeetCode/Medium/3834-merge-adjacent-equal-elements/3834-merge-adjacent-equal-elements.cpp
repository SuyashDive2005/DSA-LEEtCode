class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        vector<long long> ans;
        for (int i = 0; i < nums.size(); i++) {
           long long curr = nums[i];
           
            while (!st.empty() && st.top() == curr) {
                curr += st.top();
                st.pop();
            }

            st.push(curr);
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};