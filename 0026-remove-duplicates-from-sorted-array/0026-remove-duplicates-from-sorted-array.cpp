class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=1;
        int uniqpos=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                continue;
            }else{
                nums[uniqpos]=nums[i];
                uniqpos++;
                ans++;
            }
        }
        return ans;
    }
};