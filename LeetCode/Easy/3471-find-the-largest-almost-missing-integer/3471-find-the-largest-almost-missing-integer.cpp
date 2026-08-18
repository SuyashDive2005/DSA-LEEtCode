class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;

        for (int i = 0; i <= n - k; i++) {
            unordered_map<int, int> sub;
            for (int j = i; j < i + k; j++) {
                sub[nums[j]]++;
            }
            for (auto& p : sub) {
                count[p.first]++;
            }
        }

        int result = -1;
        for (auto& p : count) {
            if (p.second == 1) {
                result = max(result, p.first);
            }
        }

        return result;
    }
};