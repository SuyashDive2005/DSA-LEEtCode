class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        map<pair<int,int>, int> mp;
        int ans = 0;

        for(auto &d : dominoes){
            
            int a = d[0];
            int b = d[1];

            if(a > b) swap(a,b);  

            pair<int,int> key = {a,b};

            ans += mp[key];   
            mp[key]++;        
        }

        return ans;
    }
};