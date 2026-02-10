class Solution {
public:

    vector<int> merge(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        if(i<n1){
            while(i<n1){
                ans.push_back(nums1[i]);
                i++;
            }
        }
        else{
            while(j<n2){
                ans.push_back(nums2[j]);
                j++;
            }
        }
        return ans;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans = merge(nums1,nums2);
        int n = ans.size();
        if((n%2)==0){
            int i = 0;
            int j = n-1;
            while(i<j){
                i++;
                j--;
            }
            double a = ans[i];
            double b = ans[j];
            double value = (a+b)/2;
            return value;
        }
        else{
            int mid = (0+(n-1))/2;
            double value = ans[mid];
            return value;
        }
    }
};