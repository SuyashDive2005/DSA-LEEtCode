class Solution {
public:
    string check(string x){
        stack<int>st;
        string news="";
        for(char &v:x){
            if(st.empty() && v=='#'){
                continue;
            }
            if(!st.empty() && v=='#'){
                st.pop();
            }else{
                st.push(v);
            }

        }

        while(!st.empty()){
            news+=st.top();
            st.pop();
        }

        reverse(news.begin(),news.end());

        return news;

    }

    bool backspaceCompare(string s, string t) {
        return (check(s)==check(t)); 
    }
};