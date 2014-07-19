public class Solution {
    private ArrayList<String[]> ans = new ArrayList<String[]>();
    public ArrayList<String[]> solveNQueens(int n) {
        ans.clear();
        int[][] board = new int[n][n];
        sub(board, 0);
        return ans;
    }
     
    private void sub(int[][] board, int i)
    {
        int n = board.length;
        if (i == n)
        {
            // output
            String[] tmp = new String[n];
            for (int x = 0; x < n; x++)
            {
                StringBuilder sb = new StringBuilder();
                for (int y = 0; y < n; y++)
                {
                    sb.append(board[x][y]==1? 'Q' : '.');
                }
                tmp[x] = sb.toString();
            }
            ans.add(tmp);
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                board[i][j] = 1;
                if (isValid(board, i, j))
                {
                    sub(board, i+1);
                }
                board[i][j] = 0;
            }
        }
    }
     
    private boolean isValid(int[][] board, int i, int j)
    {
        // only need to validate column and 'X' direction
        int n = board.length;
        for (int x = 0; x < n; x++)
        {
            if (x != i && board[x][j] == 1) return false;
            if (x!= 0 && (i-x)>=0 && (j-x)>=0 && board[i-x][j-x] == 1) return false;
            if (x!= 0 && (i+x)< n && (j-x)>=0 && board[i+x][j-x] == 1) return false;
            if (x!= 0 && (i-x)>=0 && (j+x)< n && board[i-x][j+x] == 1) return false;
            if (x!= 0 && (i+x)< n && (j+x)< n && board[i+x][j+x] == 1) return false;
        }
        return true;
    }
}