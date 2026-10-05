class Solution {
public:
    int scoreOfParentheses(string s) {
        int res=0;
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            if(s[i]==')' && st.top()=='('){
                res++;
                st.pop();
                
            }
        }
        return res;
    }
};