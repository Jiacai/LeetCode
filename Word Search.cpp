class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (existRe(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool existRe(vector<vector<char> > &board, vector<vector<bool>> &visited, int i, int j, string &word, int k) {
        int N = board.size(), M = board[0].size();
        if (k == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[k] || visited[i][j]) return false;
        visited[i][j] = true;
        if (existRe(board, visited, i - 1, j, word, k + 1)) return true;
        if (existRe(board, visited, i, j - 1, word, k + 1)) return true;
        if (existRe(board, visited, i + 1, j, word, k + 1)) return true;
        if (existRe(board, visited, i, j + 1, word, k + 1)) return true;
        visited[i][j] = false;
        return false;
    }
    
};
