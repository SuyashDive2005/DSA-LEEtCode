class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MIN;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int j = 0;
        int i = 0;
        while (i < n1 && j < n2) {
            if (i > j) {
                j = i;
            }
            if (nums1[i] <= nums2[j]) {
                res = max(res, j - i);
                j++;
            } else {
                i++;
            }
        }
        return res == INT_MIN ? 0 : res;
    }
};