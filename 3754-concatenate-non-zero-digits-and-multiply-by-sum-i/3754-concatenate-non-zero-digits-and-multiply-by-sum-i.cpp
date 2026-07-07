class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;

        int sum = 0;
        while(n>0){

            int digit=n%10;
            n=n/10;
            if(digit){
                sum+=digit;
                x=x*10 + digit;
            }
        }
        long long rev=0;
        while(x!=0){
            int tmp=x%10;
            x/=10;
            rev=rev*10 + tmp;
        }
        return rev*sum;
    }
};