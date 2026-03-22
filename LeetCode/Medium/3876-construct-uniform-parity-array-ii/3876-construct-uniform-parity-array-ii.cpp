class Solution {
public:
    bool uniformArray(vector<int>& num1) {
        int oddmin=INT_MAX;
        int oddcount=0;

        for(int c:num1){
            if(c%2!=0){
                oddcount++;
                oddmin=min(oddmin,c);
            }
        }

        if(oddcount==0) return true;

        for(int x:num1){
            if(x%2==0){
                if(x<=oddmin) return false;
            }
        }

        return true;
    }
};