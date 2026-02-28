class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength=INT_MAX,i=0,j=0,sum=0;

        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                minLength=min(minLength,j-i+1);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (INT_MAX==minLength? 0:minLength);
    }
};