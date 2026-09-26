class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> keyval;
        for (int i = 0; i < knowledge.size(); i++) {
            keyval[knowledge[i][0]] = knowledge[i][1];
        }
        int n = s.length();
        for (int i = 0; i < n; i++) {
            string dum = "";
            if (s[i] == '(') {
                int j;
                for (j = i+1; j < n && s[j] != ')'; j++) {
                    dum += s[j];
                }
                i=j;
                if (keyval.find(dum) == keyval.end()) {
                    res += '?';
                } else res += keyval[dum];
            } else {
                if(s[i]==')') continue;
                res += s[i];
            }
        }
        return res;
    }
};