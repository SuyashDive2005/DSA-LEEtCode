class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int res = INT_MIN;

        int n = colors.size();

        int j = 0;
        int i = 0;
        while (i < n) {
            if (colors[i] != colors[j]) {
                res = max(res, abs(i - j));
            }
            i++;
        }
        return res;
    }
};