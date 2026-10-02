class Solution {
public:
    vector<string> res;
    bool valid(string s){
        int cnt = 0;
        for(char &c : s){
            if(c == '(') cnt++;
            else cnt--;
            if(cnt < 0) return false;
        }
        return cnt == 0;
    }

    void solve(string& cur, int n) {
        if (cur.length() == 2 * n) {
            if (valid(cur)) {
                res.push_back(cur);
            }
            return;
        }
        cur.push_back('(');
        solve(cur, n);
        cur.pop_back();
        cur.push_back(')');
        solve(cur, n);
        cur.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(cur, n);
        return res;
    }
};