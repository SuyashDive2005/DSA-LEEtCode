class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        vector<int> nm;
        for (int i = 0; i < n; i++) {
            nm.push_back(i);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != nm[i]) {

                res &=nums[i];
            }
        }
        return res != -1 ? res : 0;
    }
};