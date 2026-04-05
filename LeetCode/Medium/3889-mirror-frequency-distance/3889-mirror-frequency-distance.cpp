class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> mp;

        for(char c : s) {
            mp[c]++;
        }

        int res = 0;

        for(auto &x: mp) {
            char c = x.first;
            char mir;

            if(isalpha(c)) {
                mir = 'a' + ('z' - c);
            } else {
                mir = '0' + ('9' - c);
            }

            if(c <= mir || !mp.count(mir)){
                int fc = mp[c];
                int fm = mp.count(mir) ? mp[mir] : 0;

                res += abs(fc - fm);
            }
        }

        return res;
    }
};