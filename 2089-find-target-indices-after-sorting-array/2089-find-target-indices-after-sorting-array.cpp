class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        unordered_map <int,vector<int>> mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        return mp[target];
    }
};