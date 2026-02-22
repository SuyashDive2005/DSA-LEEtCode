class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;

        string res = "";

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                int cnt = 0;
                while (i < s.size() && isdigit(s[i])) {
                    cnt = cnt * 10 + (s[i] - '0');
                    i++;
                }
                i--; 
                counts.push(cnt);
            }
            else if (s[i] == '[') {
                result.push(res);
                res = "";
            }
            else if (s[i] == ']') {
                string temp = res;
                int count = counts.top(); counts.pop();
                string prev = result.top(); result.pop();

                res = prev;
                for (int j = 0; j < count; j++) {
                    res += temp;
                }
            }
            else {
                res += s[i];
            }
        }

        return res;
    }
};