class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_map<char, int> row;
            unordered_map<char, int> col;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[board[i][j]]++;
                    if (row[board[i][j]] > 1) return false;
                }

                if (board[j][i] != '.') {
                    col[board[j][i]]++;
                    if (col[board[j][i]] > 1) return false;
                }
            }
        }
        
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_map<char, int> Check;

                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (board[k][l] != '.') {
                            Check[board[k][l]]++;
                            if (Check[board[k][l]] > 1) return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
