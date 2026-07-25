class Solution {
public:
    int maxProduct(int n) {
        int ans=1;
        vector<int> tmp;
        while(n!=0){
            int temp=n%10;
            n/=10;
            tmp.push_back(temp);
        }
        sort(tmp.begin(),tmp.end());
        int size=tmp.size();
        ans*=tmp[size-1];
        ans*=tmp[size-2];
        return ans;
    }
};