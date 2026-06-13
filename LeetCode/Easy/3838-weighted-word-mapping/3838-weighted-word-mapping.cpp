class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            int x = 0;
            for (auto& c : words[i]) {
                x += weights[(c - 'a')];
            }

            (x > 25 ? x %= 26 : x);
            ans += char('z' - x);
        }

        return ans;
    }
};