class Solution {
public:
    typedef long long ll;
    ll solve(int idx,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(idx>=n)
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        ll ans=LLONG_MIN;
        ll sum=0;

        for(int i=idx;i<min(idx+3,n);i++)
        {
            sum+=nums[i];
            ans=max(ans,sum-solve(i+1,nums,dp));
        }
        return dp[idx]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size(),-1);
        int curr=solve(0,stoneValue,dp);

        if(curr>0)
        {
            return "Alice";
        }else if(curr<0)
        {
            return "Bob";
        }else{
            return "Tie";
        }
    }
};