class Solution {
public:
    bool isDigitorialPermutation(int n) {
        
        int fact[10];
        fact[0] = 1;
        for(int i = 1; i < 10; i++)
            fact[i] = fact[i - 1] * i;

        vector<int> freq1(10, 0), freq2(10, 0);

        int temp = n, sum = 0;

        while(temp > 0){
            int d = temp % 10;
            freq1[d]++;
            sum += fact[d];
            temp /= 10;
        }

        temp = sum;
        while(temp > 0){
            freq2[temp % 10]++;
            temp /= 10;
        }

        return freq1 == freq2;
    }
};