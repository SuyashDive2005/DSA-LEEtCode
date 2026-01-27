class Solution {
public:
    bool isPalindrome(int x) {
        long long  temp=x;
       long long  revno=0;
       while(temp>0){
            long long last= temp % 10;

            temp /= 10;
            revno=(revno*10)+last;    
        }

        return (revno==x?true:false);
    }
};