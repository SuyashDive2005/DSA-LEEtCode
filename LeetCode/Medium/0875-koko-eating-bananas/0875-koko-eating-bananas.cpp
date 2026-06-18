class Solution {
public:
    bool possible(vector<int>&piles,int h,int k){
        long long hr=0;
        for(int pile:piles){
            hr+=((long long)(pile + k - 1)/k);
        }
        return hr<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,high= *max_element(piles.begin(),piles.end());

        while(l<=high){
            int mid = l+(high-l)/2;
            if(possible(piles,h,mid)){
                high=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};