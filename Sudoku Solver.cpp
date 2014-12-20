class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuRe(board, 0);
    }
    
    bool isValid(vector<vector<char> > &board, int i, int j) {
        for (int k = 0; k < 9; k++) {
            if ((k != i && board[k][j] == board[i][j])
                || (k != j && board[i][k] == board[i][j])) {
                return false;
            }
        }
        int startX = i / 3 * 3;
        int startY = j / 3 * 3;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (startX + x == i && startY + y == j) {
                    continue;
                }
                if (board[startX + x][startY + y] == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool solveSudokuRe(vector<vector<char>> &board, int n) {
        int size = board.size();
        if (n == size * size) {
            return true;
        }
        int i = n / size;
        int j = n % size;
        if (board[i][j] == '.') {
            for (char ch = '1'; ch <= '9'; ch++) {
                board[i][j] = ch;
                if (isValid(board, i, j)) {
                    bool result = solveSudokuRe(board, n + 1);
                    if (result) return true;
                }
            }
            board[i][j] = '.';
            return false;
        } else {
            return solveSudokuRe(board, n + 1);
        }
    }
};
