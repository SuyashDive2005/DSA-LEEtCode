class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mx_in=0,mn_in=0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[mn_in]){
                mn_in=i;
            }
            if(nums[i]>nums[mx_in]){
                mx_in=i;
            }
        }
        int ans;
        int front=max(mn_in,mx_in)+1;
        int back=n-min(mn_in,mx_in);
        int both = (min(mn_in, mx_in) + 1) + (n - max(mn_in, mx_in));
        return min({front, back, both});

    }
};