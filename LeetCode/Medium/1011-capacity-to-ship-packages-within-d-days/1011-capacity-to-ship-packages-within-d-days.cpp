class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int occans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isposs(weights,days,mid)){
                high=mid-1;
                occans=mid;
            }else{
                low=mid+1;
            }
        }
        return occans;
    }

    bool isposs(vector<int>& wts,int days,int cap){
        int currw=0,usedDay=1;
        for(int w:wts){
            if(currw+w<=cap){
                currw+=w;
            }else{
                currw=w;
                usedDay++;
            }
        }
        return usedDay<=days;
    }
};