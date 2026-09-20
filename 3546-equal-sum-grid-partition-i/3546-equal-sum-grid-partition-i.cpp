class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                total += grid[i][j];
            }
        }

        long long prefix = 0;

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                prefix += grid[i][j];
            }

            if(prefix == total - prefix)
                return true;
        }

        prefix = 0;

        for(int j = 0; j < m - 1; j++) {
            for(int i = 0; i < n; i++) {
                prefix += grid[i][j];
            }

            if(prefix == total - prefix)
                return true;
        }

        return false;
    }
};