class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        const int mod = 1e9 + 7;
        vector<int >prev(n),next(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else prev[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) next[i]=n;
            else next[i]=st.top();

            st.push(i);
        }

        long long ans=0;

        for(int i=0;i<n;i++){
            long long L=i-prev[i];
            long long R= next[i]-i;

            ans=(ans+ (arr[i]*L%mod)*R%mod)%mod;
        
        }
        return ans;
    }
};