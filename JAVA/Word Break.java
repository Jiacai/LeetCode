import java.util.*;
public class Solution {
    private int f[][] = null;
    public boolean wordBreak(String s, Set<String> dict) {
        int len = s.length();
        f = new int[len][len]; // 0 for unvisited, -1 for false, 1 for true
        return wordBreak(s, dict, 0, len-1);
    }
     
    private boolean wordBreak(String s, Set<String> dict, int i, int j) {
        if (f[i][j] == 1) return true;
        if (f[i][j] == -1) return false;
        String s0 = s.substring(i, j + 1);
        if (dict.contains(s0)) {
            f[i][j] = 1;
            return true;
        }
        for (int k = i + 1; k <= j; k++) {
            if (wordBreak(s, dict, i, k-1) && wordBreak(s, dict, k, j)) {
                f[i][j] = 1;
                return true;
            }
        }
        f[i][j] = -1;
        return false;
    }
}