public class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len-i; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len-j-1][len-i-1];
                matrix[len-j-1][len-i-1] = tmp;
            }
        }
        for (int i = 0; i < len/2; i++)
        {
            for (int j = 0; j < len; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[len-i-1][j];
                matrix[len-i-1][j] = tmp;
            }
        }
    }
}