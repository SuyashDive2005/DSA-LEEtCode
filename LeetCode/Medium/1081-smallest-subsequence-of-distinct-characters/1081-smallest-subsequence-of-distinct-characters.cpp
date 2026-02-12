class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>freq;
        unordered_map<char,bool>used;

        string ans="";

        for(char c:s){
            freq[c]++;
        }

        for(char c:s){
            freq[c]--;

            if(used[c]){
                continue;
            }

            while(!ans.empty() && c<ans.back() && freq[ans.back()]>0){
                used[ans.back()]=false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c]=true;
        }
        return ans;
    }
};
