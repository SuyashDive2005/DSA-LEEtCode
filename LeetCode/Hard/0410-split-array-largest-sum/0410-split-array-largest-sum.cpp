class Solution {
public:
    int splitArray(vector<int>& nums, int subarr) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        int ans;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(isposs(nums,subarr,mid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    bool isposs(vector<int>&nums,int subarr,int mid){
        int partsdivided=1;
        int currmaxsum=0;

        for(int num:nums){
            if(num+currmaxsum<=mid){
                currmaxsum+=num;
            }else{
                currmaxsum=num;
                partsdivided++;
            }
        }
        return partsdivided<=subarr;
    }
};