class Solution {
public:
    int N;
    int M;
    void solve(vector<vector<char>> &board)
    {
        if (board.empty() || board[0].empty()) return;
        N = board.size();
        M = board[0].size();
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    probe(board, i, j);
            }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (board[i][j] != '.')
                    board[i][j] = 'X';
                else
                    board[i][j] = 'O';
            }
    }
 
    void probe(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= N) return;
        if (j < 0 || j >= M) return;
        if (board[i][j] != 'O') return;
        board[i][j] = '.';
        probe(board, i-1, j);
        probe(board, i+1, j);
        probe(board, i, j-1);
        probe(board, i, j+1);
    }
};
