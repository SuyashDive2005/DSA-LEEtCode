class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {

                res &=nums[i];
            }
        }
        return res != -1 ? res : 0;
    }
};