class Solution {
public:
    int findOcc(vector<int> &nums,bool left,int target){
        int midocc=-1;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target){
                midocc=mid;
                if(left){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return midocc;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int left=findOcc(nums,true,target);
        int right=findOcc(nums,false,target);
       return {left,right};
    }
};