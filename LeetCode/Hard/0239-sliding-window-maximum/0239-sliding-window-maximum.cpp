/*
Story Points:
 
1. When new element comes nums[i], make space for it (window size can't be greater than k)

2. Now, when nums[i] comes, there is no need to keep small elements in that window, pop them

3. Now push i in deque -> for nums[i]

4. If (i >= k-1), then deq.front() is our answer for that window

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>deq;
        vector<int>res;

        for(int i=0;i<n;i++){
            while(!deq.empty() && deq.front()<=i-k){
                deq.pop_front(); //pop the elements at front that are not in the curr window
            }
            while(!deq.empty() && nums[i]> nums[deq.back()]){
                deq.pop_back();
            }
            
            deq.push_back(i);

            if(i>=k-1){
                res.push_back(nums[deq.front()]);
            }
        }

        return res;
    }
};