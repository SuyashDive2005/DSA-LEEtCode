class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) {
                 return abs(a) > abs(b);
             });
        vector<int> arr(nums.size());
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                arr[i] = nums[left++];
            } else {
                arr[i] = nums[right--];
            }
        }
        long long res = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long sq = 1LL * arr[i] * arr[i];

            if (i % 2 == 0) res += sq;
            else res -= sq;
        }
        return res;
    }
};