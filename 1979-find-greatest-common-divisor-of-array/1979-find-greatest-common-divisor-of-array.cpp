class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int mx=nums[0],mn=nums[0];
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        return gcd(mn,mx);
    }
};