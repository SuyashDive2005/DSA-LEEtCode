class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;

        int i=0,j=0,len=0;

        while(j<s.length()){
            if(set.find(s[j])==set.end()){
                set.insert(s[j]);
                len=max(len,j-i+1);
                j++;
            }else{
                set.erase(s[i]);
                i++;

            }
        }
        return len;

    }
};