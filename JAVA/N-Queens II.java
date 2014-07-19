public class Solution {
    private int ans;
    private boolean[] visited;
    private int[] col;
    public int totalNQueens(int n) {
        ans = 0;
        col = new int[n];
        visited = new boolean[n];
        sub(0);
        return ans;
    }
     
    private void sub(int i)
    {
        int n = col.length;
        if (i == n)
        {
            ans++;
        }
        else
        {
            for (int j = 0; j < n; j++)
            { 
                if (!visited[j] && isValid(i, j))
                {
                    col[i] = j;
                    visited[j] = true;
                    sub(i+1);
                    visited[j] = false;
                } 
            }
        }
    }
     
    private boolean isValid(int i, int j)
    {
        // only need to validate column and 'X' direction
        for (int k = 0; k < i; k++)
        {
            if (Math.abs(k-i)== Math.abs(col[k]-j)) return false;
        }
        return true;
    }
}