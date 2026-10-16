class Solution {
public:
    int sumCounts(vector<int>& nums) {

        long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            int di;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                di = st.size();
                ans += (di * di);
            }
        }
        return ans;
    }
};