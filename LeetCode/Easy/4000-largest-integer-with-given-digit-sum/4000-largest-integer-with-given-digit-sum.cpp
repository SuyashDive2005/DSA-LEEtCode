class Solution {
public:
    int largestInteger(int n, int s) {
        string ans="";

        if(s>9*n || s<0) return -1;
        for(int i=0;i<n;i++){
            int digit=min(9,s);
            ans+=to_string(digit);
            s-=digit;
        }
        return stoi(ans);
    }
};