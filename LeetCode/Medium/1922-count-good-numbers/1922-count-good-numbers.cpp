class Solution {
public:
    const int M=1e9+7;
    long long power(long long x,long long n){
    
        if(n==0) return 1;
        if(n==1) return x;

        long long half = power(x,n/2);
        long long res = (half*half) %M;

        if(n%2==1){
            res=(res*x)%M;
        }

        return res;

    }
    int countGoodNumbers(long long n) {
     return (long long)power(5,(n+1)/2) * power(4,n/2) %M;   
    }
};