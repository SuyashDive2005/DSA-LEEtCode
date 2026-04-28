class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int left = 0, right = 0;
        for (auto& c : s) {
            if (c == '(')
                left++;
            else
                right++;
            if (left == right)
                res = max(res, left * 2);
            if (right > left)
                right = left = 0;
        }

        left = 0, right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;
            if (left == right)
                res = max(res, left * 2);
            if (right < left)
                right = left = 0;
        }
        return res;
    }
};