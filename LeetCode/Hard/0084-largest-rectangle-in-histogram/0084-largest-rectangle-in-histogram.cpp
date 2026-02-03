class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=INT_MIN;
        stack<int>st;
        int n=heights.size();;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int x=st.top();
                st.pop();
                int pse=st.empty() ? -1 : st.top();
                int nse=i;
                maxArea=max(maxArea,heights[x]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int x=st.top();
            st.pop();
            int pse=st.empty() ? -1 : st.top();
            int nse=n;
            maxArea=max(maxArea,heights[x]*(nse-pse-1));
        }
        return maxArea;
    }
};