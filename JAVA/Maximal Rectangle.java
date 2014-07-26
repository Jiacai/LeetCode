public class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        if (m == 0) return 0;
        int n = matrix[0].length;
        if (n == 0) return 0;
        int h[][] = new int[m][n+1]; // n+1 is for holder 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0') {
                    h[i][j] = 0;
                } else if (i == 0) {
                    h[i][j] = 1;
                } else {
                    h[i][j] = h[i-1][j] + 1;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < m; i++)
        {
            int tmp = maxArea(h[i]);
            if (tmp > max) max = tmp;
        }
        return max;
    }
     
    private int maxArea(int[] h)
    {
        int max = 0;
        int[] stack = new int[h.length];
        int idx = -1;       
        int i = 0;
        while (i < h.length)
        {
            if (idx == -1 || h[i] >= h[stack[idx]])
            {
                idx++;
                stack[idx] = i;
                i++;
            }
            else {
                int t = stack[idx];
                idx--;
                int tmp = h[t] * (idx == -1 ? i : (i - stack[idx] - 1));
                if (tmp > max) max = tmp;
            }
        }
        return max;
    }
}