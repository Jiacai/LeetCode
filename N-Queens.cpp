class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        for (int i = 0; i < n; i++) {
            board.push_back(string(n, '.'));
        }
        solveNQueensRe(result, board, 0);
        return result;
    }
    
    void solveNQueensRe(vector<vector<string>> &result, vector<string> &board, int i) {
        int n = board.size();
        if (i == n) {
            result.push_back(board);
            return;
        }
        for (int j = 0; j < n; j++) {
            board[i][j] = 'Q';
            if (isValid(board, i, j)) {
                solveNQueensRe(result, board, i + 1);
            }
            board[i][j] = '.';
        }
    }
    
    bool isValid(vector<string> &board, int i, int j) {
        int n = board.size();
        for (int k = 0; k < i; k++) {
            if (board[k][j] == 'Q') {
                return false;
            }
            int diff = i - k;
            if ((j - diff >= 0 && board[k][j - diff] == 'Q') ||
                (j + diff < n && board[k][j + diff] == 'Q')) {
                return false;
            }
        }
        return true;
    }
};
