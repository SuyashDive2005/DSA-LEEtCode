class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int tmp=nums[i];
            while(tmp!=0){
                sum+=tmp%10;
                tmp/=10;
            }
            if(sum==i){
                ans=min(ans,i);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};