class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0 || n==1) return 0;
        return n/5 + trailingZeroes(n/5);
    }
};