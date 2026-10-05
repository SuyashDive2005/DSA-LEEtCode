class Solution {
public:
    int scoreOfParentheses(string s) {
        int res=0;
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(res);
                res=0;
            }else{
                if(s[i-1]=='('){
                    res=st.top()+1;
                }else{
                    res=st.top()+2*res;
                }

                st.pop();
            }
            
        }
        return res;
    }
};