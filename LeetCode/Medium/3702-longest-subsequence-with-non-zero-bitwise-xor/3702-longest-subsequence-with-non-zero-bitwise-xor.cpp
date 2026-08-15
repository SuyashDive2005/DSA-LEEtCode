class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int allzero=true;

        int x=0;
        for(int &c:nums){
            x=(x^c);
            if(c!=0){
                allzero=false;
            }
        }

        if(allzero) return 0;

        return (x==0) ? n-1 : n;
    }
};