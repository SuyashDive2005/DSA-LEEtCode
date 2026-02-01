class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int f_min = INT_MAX, s_min = INT_MAX;
        int ans;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < f_min) {
                s_min = f_min;
                f_min = nums[i];
            } else if (nums[i] < s_min) {
                s_min = nums[i];
            }
        }

        return nums[0] + f_min + s_min;
    }
};