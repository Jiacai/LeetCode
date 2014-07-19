public class Solution {
    public boolean isScramble(String s1, String s2) {
        char[] ca1 = s1.toCharArray();
        char[] ca2 = s2.toCharArray();
        if (s1.length() != s2.length()) return false;
        int len = s1.length();
        if (len == 0) return true;
        int[][][] mx = new int[len][len][len+1];
        for (int i = 0; i < len; i++)
            for (int j = 0; j < len; j++)
                for (int k = 0; k < len+1; k++)
                    mx[i][j][k] = -1; // not visited;
        return isScramble(ca1, ca2, 0, 0, len, mx);
    }
     
    public boolean isScramble(char[] ca1, char[] ca2, int i1, int i2, int len, int[][][] mx)
    {
        if (len == 1) return ca1[i1] == ca2[i2];
        if (mx[i1][i2][len] != -1)
        {
            return mx[i1][i2][len] == 1;
        }
        for (int k = 1; k < len; k++)
        {
            if (isScramble(ca1, ca2, i1, i2, k, mx) && isScramble(ca1, ca2, i1+k, i2+k, len-k, mx))
            {
                mx[i1][i2][len] = 1;
                return true;
            }
            if (isScramble(ca1, ca2, i1, i2+len-k, k, mx) && isScramble(ca1, ca2, i1+k, i2, len-k, mx))
            {
                mx[i1][i2][len] = 1;
                return true;
            }
        }
        mx[i1][i2][len] = 0;
        return false;
    }
}