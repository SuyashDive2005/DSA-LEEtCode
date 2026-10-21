class Solution {
public:

    vector<int> getLeftMax(vector<int>& height,int& n){
        vector<int>vec(n);

        vec[0]=height[0];
        for(int i=1;i<n;i++){
            vec[i]=max(vec[i-1],height[i]);
        }
        return vec;
    }

    vector<int> getRightMax(vector<int>& height,int& n){
        vector<int>vec(n);

        vec[n-1]=height[n-1];

        for(int i=n-2;i>=0;i--){
            vec[i]=max(vec[i+1],height[i]);
        }

        return vec;
    }

    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<int> leftMax= getLeftMax(height,n);
        vector<int> RightMax= getRightMax(height,n);

        for(int i=0;i<n;i++){
            int h=min(leftMax[i],RightMax[i]) - height[i];
            ans+=h;
        }
        return ans;
    }
};