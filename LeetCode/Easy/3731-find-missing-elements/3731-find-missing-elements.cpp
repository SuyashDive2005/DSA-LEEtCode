class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> vec;
        int it = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            while (it < nums[i]) {
                vec.push_back(it);
                it++;
            }
            it = nums[i] + 1;
        }

        return vec;
    }
};