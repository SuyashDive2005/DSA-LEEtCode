class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string pref=strs[0];
        for(int i=1;i<n;i++){
            while(strs[i].find(pref)!=0){
                pref.pop_back();
                if(pref.empty()) return "";
            }
        }
        return pref;
    }
};