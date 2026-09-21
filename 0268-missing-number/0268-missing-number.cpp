class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int requiredsum=0;
        for(int i=0;i<=n;i++){
            requiredsum+=i;
        }

        return requiredsum-totalsum;
    }
};