class Solution {
public:
    int reverseDegree(string s) {
        long long ans=0;
        for (int i = 0; i < s.length(); i++) {
            int tmp = 'z' - s[i] + 1;
            ans += ((i + 1) * tmp);
        }
        return (int)ans;
    }
};