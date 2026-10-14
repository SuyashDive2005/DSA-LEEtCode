class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n=s.length();
        int res=0;
        int i=0;
        int j=0;

        while(j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                res=max(res,j-i+1);
                j++;
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};