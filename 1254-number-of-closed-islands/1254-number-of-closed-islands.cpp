class Solution {
public:
    int m, n;
    // int dr[] = {0, 0, -1, 1};
    // int dc[] = {-1, 1, 0, 0};
    bool dfs(vector<vector<int>>& grid, int r, int c) {
        if (r >= m || r < 0 || c >= n || c < 0) {
            return false;
        }

        if (grid[r][c] == 1) {
            return true;
        }

        grid[r][c] = 1;

        bool l_close = dfs(grid, r, c - 1);
        bool r_close = dfs(grid, r, c + 1);
        bool u_close = dfs(grid, r - 1, c);
        bool d_close = dfs(grid, r + 1, c);

        return d_close && u_close && r_close && l_close;
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(grid, i, j)) {
                        res++;
                    }
                }
            }
        }

        return res;
    }
};