
class Solution {
public:
    string originalDigits(string s) {
        int mp[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            mp[s[i] - 'a']++;
        }

        int num[10] = {0};

        num[0] = mp['z' - 'a'];
        num[2] = mp['w' - 'a'];
        num[4] = mp['u' - 'a'];
        num[6] = mp['x' - 'a'];
        num[8] = mp['g' - 'a'];

        num[3] = mp['h' - 'a'] - num[8];
        num[5] = mp['f' - 'a'] - num[4];
        num[7] = mp['s' - 'a'] - num[6];

        num[1] = mp['o' - 'a'] - num[0] - num[2] - num[4];

        num[9] = mp['i' - 'a'] - num[5] - num[6] - num[8];

        string ans = "";

        for (int i = 0; i < 10; i++) {
            while (num[i] > 0) {
                ans += char(i + '0');
                num[i]--;
            }
        }

        return ans;
    }
};
