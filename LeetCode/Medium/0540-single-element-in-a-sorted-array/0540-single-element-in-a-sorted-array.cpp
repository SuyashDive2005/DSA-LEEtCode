class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int>mp;
        for(int &c: nums){
            mp[c]++;
        }

        for(auto x:mp){
            if(x.second==1){
                ans=x.first;
            }
        }

        return ans;
    }
};