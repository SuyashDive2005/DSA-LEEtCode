class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int sum=0;
        int i=0,j=0;
        int n=nums.size();

        deque<int>dq;
        vector<long long> cumSum(n,0);
        while(j<n){
            if(j==0) {
                cumSum[j]=nums[j];
            }else{
                cumSum[j]=cumSum[j-1]+nums[j];
            }

            if(cumSum[j]>=k){
                ans=min(ans,j-i+1);
            }

            while(!dq.empty() && cumSum[j] - cumSum[dq.front()] >= k){
                ans=min(ans,j-dq.front());
                dq.pop_front();
            }

            while(!dq.empty() && cumSum[j]<=cumSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};