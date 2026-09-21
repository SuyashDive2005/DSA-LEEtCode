class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int requiredsum=n*(n+1)/2;

        return requiredsum-totalsum;
    }
};