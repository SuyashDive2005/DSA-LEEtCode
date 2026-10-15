class Solution {
public:
    int dp[101][101];
    int solve(int n,int m,int i,int j){
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>n-1 || j>m-1){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int left = solve(n,m,i+1,j);
        int right=solve(n,m,i,j+1);
        dp[i][j]=left+right;
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n,m,0,0);
    }
};