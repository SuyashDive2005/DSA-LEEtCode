class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> dp;

    bool solve(int idx, string &s) {
        if (idx == n) return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int len = 1; idx + len <= n; len++) {
            string temp = s.substr(idx, len);
            if (st.find(temp) != st.end() && solve(idx + len, s)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        dp.assign(n, -1);

        for (string &word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
