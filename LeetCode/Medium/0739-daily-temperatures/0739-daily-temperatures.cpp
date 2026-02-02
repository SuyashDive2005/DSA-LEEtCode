class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int>ans(temp.size(),0);
        stack<int>st;
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[i]>=temp[st.top()]){
                st.pop();
            }if(st.empty()){
                ans[i]=0;
            }else {
                ans[i]=st.top()-i;
            }
            st.push(i);
        }
        return ans;
    }
};