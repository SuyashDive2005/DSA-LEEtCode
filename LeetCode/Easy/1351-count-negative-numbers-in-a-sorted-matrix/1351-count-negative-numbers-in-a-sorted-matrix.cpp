class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();

        for (auto &row : grid) {
            int low = 0;
            int high = n - 1;
            int firstneg = n;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (row[mid] < 0) {
                    firstneg = mid;
                    high = mid - 1; 
                } else {
                    low = mid + 1;  
                }
            }

            count += (n - firstneg);
        }

        return count;
    }
};