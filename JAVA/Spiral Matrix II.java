public class Solution {
    public int[][] generateMatrix(int n) {
        int cnt = 1;
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int[][] r = new int[n][n];
        while (cnt <= n* n)
        {
            for (int i = left; i <= right; i++)
                r[top][i] = cnt++;
            top++;
            for (int i = top; i <= bottom; i++)
                r[i][right] = cnt++;
            right--;
            for (int i = right; i >= left; i--)
                r[bottom][i] = cnt++;
            bottom--;
            for (int i = bottom; i >= top; i--)
                r[i][left] = cnt++;
            left++;
        }
        return r;
    }
}