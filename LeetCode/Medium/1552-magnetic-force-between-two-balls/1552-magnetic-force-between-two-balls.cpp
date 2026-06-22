class Solution {
public:

    bool ispos(vector<int>&pos,int m,int frc){
        int ball=1;
        int lastpos=pos.front();

        for(int p:pos){
            if(p-lastpos>=frc){
                ball++;
                lastpos=p;
            }
        }
        return ball>=m;
    }

    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(),pos.end());
        int low = 1;
        int high = pos.back();

        while(low<=high){
            int mid = low + (high-low)/2;

            if(ispos(pos,m,mid)){
                low=mid+1;
            }else{
                high= mid-1;
            }
        }
        return high;
    }
};