class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int tmp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                tmp++;
            }else if(s[i]==')'){
                ans=max(ans,tmp);
                tmp--;
            }else{
                continue;
            }
        }
        return ans;      
    }
};