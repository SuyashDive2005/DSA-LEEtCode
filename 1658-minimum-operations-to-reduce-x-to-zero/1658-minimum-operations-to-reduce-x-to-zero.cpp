class Solution {
public:
    void sumofsubarray(vector<int>& nums, int k, vector<int>& subarray) {
        int sum = 0, i = 0, len = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum > k)
                sum -= nums[i++];

            if (sum == k && j - i + 1 > len) {
                len = j - i + 1;
                subarray = vector<int>(nums.begin() + i, nums.begin() + j + 1);
            }
        }
    }

    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int subsum = sum - x;
        vector<int> subarray;
        if (subsum < 0)
        return -1;
        if (subsum == 0)
            return nums.size();
        sumofsubarray(nums, subsum, subarray);
        if (!subarray.size()) {
            return -1;
        }
        int operation = nums.size() - subarray.size();
        return operation;
    }
};