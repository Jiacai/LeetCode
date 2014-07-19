class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        for (int i = 0; i < n; i++)
        {
            update(board, 0, i);
        }
        for (int i = 1; i < m; i++)
        {
            update(board, i, n-1);
        }
        for (int i = n-2; i >= 0; i--)
        {
            update(board, m-1, i);
        }
        for (int i = m-2; i >=1; i--)
        {
            update(board, i, 0);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j]=='#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
     
    void update(vector<vector<char>> &board, int i, int j)
    {
        if (i >= board.size() || j >= board[0].size()) return;
        if (board[i][j] == 'O')
        {
            board[i][j] = '#';
            update(board, i-1, j);
            update(board, i+1, j);
            update(board, i, j-1);
            update(board, i, j+1);
        }
    }
};