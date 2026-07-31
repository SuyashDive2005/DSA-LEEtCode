class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int press = i / 8 + 1;
            res += press * freq[i];
        }
        return res;
    }
};