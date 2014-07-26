public class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() == 0) return true;
        int i = 0;
        int j = s.length() - 1;
        while (true)
        {
            while (i < s.length() && !isAlphaNum(s.charAt(i)))
            {
                i++;
            }
            while (j >= 0 && !isAlphaNum(s.charAt(j)))
            {
                j--;
            }
            if (i > j || i == s.length() || j < 0) break;
            int c1 = s.charAt(i);
            int c2 = s.charAt(j);
            if (c1 == c2 || c1-c2 == 'a'-'A' || c1-c2 == 'A' - 'a') {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
     
    private boolean isAlphaNum(char c)
    {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9')) return true;
        else return false;
    }
}