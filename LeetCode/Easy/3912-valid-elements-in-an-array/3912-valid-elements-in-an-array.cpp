class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        
        if(n == 0) return res;
        if(n == 1) return nums;

        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = nums[0];
        for(int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], nums[i]);
        }

        rightMax[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            if(i == 0 || i == n-1) {
                res.push_back(nums[i]);
            }
            else if(nums[i] > leftMax[i-1] || nums[i] > rightMax[i+1]) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};