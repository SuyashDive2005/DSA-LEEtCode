class Solution {
public:
    int firstMatchingIndex(string s) {
        int ans=INT_MAX;
        for(int i=0;i<s.length();i++){
            if(s[i]==s[s.length()-i-1]){
                ans=min(ans,i);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};