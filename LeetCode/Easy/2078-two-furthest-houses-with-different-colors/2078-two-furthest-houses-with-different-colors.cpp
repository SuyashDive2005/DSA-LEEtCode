class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int res=INT_MIN;

        int n=colors.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(colors[i]!=colors[j]){
                    res=max(res,abs(i-j));
                }
            }
        }
        return res;
    }
};