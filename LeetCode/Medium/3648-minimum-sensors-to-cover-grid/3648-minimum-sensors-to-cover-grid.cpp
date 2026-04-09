class Solution {
public:
    int minSensors(int n, int m, int k) {
        int s =2*k+1;
        return ceil((double)n / s) * ceil((double)m / s);
    }
};