class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(auto& c:s){
            if(c=='(' || c=='{' || c=='['){
                ans.push(c);
            }
            else{
                if(ans.empty()) return false;
                if((c==')' && ans.top()=='(') || (c=='}' && ans.top()=='{') || (c==']' && ans.top()=='[')){
                    ans.pop();
                }
                else{
                    return false;
                }
            }
        }

        return ans.empty();
    }
};