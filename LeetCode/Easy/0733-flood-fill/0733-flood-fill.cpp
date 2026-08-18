class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    bool isvalid(int r, int c, int rows, int cols, int startColor, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
        if (visited[r][c]) return false;
        if (grid[r][c] != startColor) return false; 

        return true;
    }

    void griddfs(int r, int c, int rows, int cols, int startColor, vector<vector<int>> &grid, vector<vector<bool>>& visited){
        visited[r][c] = true;

        for (int i = 0; i < 4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (isvalid(nr, nc, rows, cols, startColor, grid, visited)){
                griddfs(nr, nc, rows, cols, startColor, grid, visited);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        int startColor = image[sr][sc];

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<int>> result = image;

        griddfs(sr, sc, rows, cols, startColor, image, visited);

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (visited[i][j]){
                    result[i][j] = color;
                }
            }
        }
        return result;
    }
};