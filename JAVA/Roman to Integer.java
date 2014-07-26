public class Solution {
    public int romanToInt(String s) {
        String ss[] = new String[] {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int vv[] = new int[] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        int ans = 0;
        int j = 0;
        while (j < s.length())
        {
            boolean match = true;
            int len = ss[i].length();
            for (int k = 0; k < len; k++)
            {
                if (j+k == s.length() || ss[i].charAt(k) != s.charAt(j+k))
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                j += (len);
                ans += vv[i];
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
}