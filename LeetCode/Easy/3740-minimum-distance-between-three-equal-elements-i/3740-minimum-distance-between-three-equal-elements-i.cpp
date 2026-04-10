class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto& it : mp) {
            vector<int>& pos = it.second;

            if (pos.size() >= 3) {
                for (int i = 0; i + 2 < pos.size(); i++) {
                    int first = pos[i];
                    int third = pos[i + 2];

                    int dist = 2 * (third - first);
                    ans = min(ans, dist);
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};