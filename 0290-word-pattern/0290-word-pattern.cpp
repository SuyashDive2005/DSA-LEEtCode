class Solution {
public:
    bool wordPattern(string pat, string s) {
        string tmp = "";
        unordered_map<char, string> mp;
        int j = 0;
        string ch = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c != ' ') {
                tmp += c;
            }

            if (c == ' ' || i == s.length() - 1) {
                if (j >= pat.length()) return false;

                if (mp.find(pat[j]) != mp.end() && mp[pat[j]] != tmp) {
                    return false;
                }

                for (auto it : mp) {
                    if (it.second == tmp && it.first != pat[j]) {
                        return false;
                    }
                }

                mp[pat[j]] = tmp;
                ch += tmp;
                ch += ' ';
                tmp = "";
                j++;
            }
        }

        if (j != pat.length()) return false;

        ch.pop_back();
        return ch == s;
    }
};