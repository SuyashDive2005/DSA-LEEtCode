class Solution {
public:
    string helper(string s){
        string ans;
        vector<int> vec(26,0);
        for( char c:s){
            vec[c-'a']+=1;
        }

        for(int i=0;i<26;i++){
            if(vec[i]>0){
                string curr(vec[i],i+'a');
                ans+=curr;
            }
        }
        cout<<ans<<endl;
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string wrd=strs[i];
            string key=helper(wrd);
            mp[key].push_back(strs[i]);
        }

        for(auto &x:mp){
            res.push_back(x.second);
        }
        return res;
    }
};