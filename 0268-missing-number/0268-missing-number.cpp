class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        // int sum=accumulate(nums.begin(),nums.end(),0);

        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1){
                return i;
            }
        }
        if(nums[0]!=0){
            return 0;
        }
        return n;
    }
};