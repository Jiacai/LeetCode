public class Solution {
    public String countAndSay(int n) {
        StringBuilder last = new StringBuilder();
        StringBuilder current = new StringBuilder("1");
        int i = 1;
        while (i < n)
        {
            last = current;
            current = new StringBuilder();
            int idx = 0;
            while (idx < last.length())
            {
                char c = last.charAt(idx);
                int cnt = 1;
                while (idx + 1 < last.length() && c == last.charAt(idx+1))
                {
                    idx++;
                    cnt++;
                }
                idx++;
                current.append(cnt);
                current.append(c);
            }
             
            i++;
        }      
        // give out current
        return current.toString();
    }
}