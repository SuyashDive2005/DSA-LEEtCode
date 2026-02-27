class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        // This deque will store INDICES (not values)
        // Why indices?
        // Because we need to:
        // 1. Check if element is outside window
        // 2. Compare values using nums[index]
        deque<int> deq;
        
        vector<int> res;

        for(int i = 0; i < n; i++) {

            // -----------------------------
            // STEP 1: Remove elements that are outside the current window
            // -----------------------------
            // Current window range is:
            // [i - k + 1 ... i]
            //
            // If deq.front() <= i - k,
            // that index is outside the window.
            //
            // We remove from front because
            // front holds the oldest index.
            while(!deq.empty() && deq.front() <= i - k) {
                deq.pop_front();
            }

            // -----------------------------
            // STEP 2: Maintain decreasing order in deque
            // -----------------------------
            // If current element nums[i] is greater than
            // elements at back of deque,
            // those smaller elements can NEVER become maximum
            // in this or future windows.
            //
            // So remove them.
            //
            // This keeps deque values in decreasing order.
            while(!deq.empty() && nums[i] > nums[deq.back()]) {
                deq.pop_back();
            }

            // -----------------------------
            // STEP 3: Push current index
            // -----------------------------
            // Now current element becomes candidate
            // for future windows.
            deq.push_back(i);

            // -----------------------------
            // STEP 4: Record answer when first window forms
            // -----------------------------
            // First window is complete when i >= k - 1
            //
            // Since deque is maintained in decreasing order,
            // front always contains index of maximum element.
            if(i >= k - 1) {
                res.push_back(nums[deq.front()]);
            }
        }

        return res;
    }
};