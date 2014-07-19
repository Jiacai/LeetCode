public class Solution {
    public int minCut(String s) {
        int len = s.length();
        boolean[][] valid = new boolean[len][len]; // 0-len-1
        for (int L = 0; L < len; L++) // L: j-i
        {
            for (int i = 0; i < len; i++)
            {
                if (L+i>=len) continue;
                if (L==0) valid[i][i] = true;
                else if (L==1) valid[i][i+L] = s.charAt(i)==s.charAt(i+L);
                else
                {
                    valid[i][i+L] = s.charAt(i)==s.charAt(i+L) && valid[i+1][i+L-1];
                }
            }
        }
        int[] cut = new int[len]; // the cuts for 0 to i
        cut[0] = 0;
        for (int i = 1; i < len; i++)
        {
            if (valid[0][i]) cut[i] = 0;
            else
            {
                cut[i] = Integer.MAX_VALUE;
                for (int j = 0; j < i; j++)
                {
                    if (valid[j+1][i] && cut[j]+1 < cut[i])
                        cut[i] = cut[j]+1;
                }
            }
        }
        return cut[len-1];
    }
}