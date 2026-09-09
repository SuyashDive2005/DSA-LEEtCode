class Solution {
public:
    typedef long long ll;

    long long countCommas(long long n) {
        ll ans = 0;
        
        ll p = 1000;

        while (p <= n) {
            ans += n - p + 1;
            p *= 1000;
        }

        return ans;
    }
};