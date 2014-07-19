public class Solution {
    public int numDistinct(String S, String T) {
        int sLen = S.length();
        int tLen = T.length();
        int[][] mx = new int[sLen+1][tLen+1];
        mx[0][0] = 1;
        for (int i = 1; i <= sLen; i++)
        {
            mx[i][0] = 1;
        }
        for (int j = 1; j <= tLen; j++)
        {
            mx[0][j] = 0;
        }
 
        for (int i = 1; i <= sLen; i++)
        {
            for (int j = 1; j <= tLen; j++)
            {
                if (i < j) mx[i][j] = 0;
                else if (S.charAt(i-1) != T.charAt(j-1))
                {
                    mx[i][j] = mx[i-1][j];
                }
                else
                {
                    mx[i][j] = mx[i-1][j-1] + mx[i-1][j];
                }
            }
        }
        return mx[sLen][tLen];
    }
}