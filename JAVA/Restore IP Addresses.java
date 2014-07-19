public class Solution {
    ArrayList<String> result = new ArrayList<String>();
    ArrayList<String> section = new ArrayList<String>();
    public ArrayList<String> restoreIpAddresses(String s) {
        result.clear();
        section.clear();
        dfs(s, 0, 0);
        return result;
    }
     
    private void dfs(String s, int pos, int depth)
    {
        if (depth == 4)
        {
            int len = 0;
            for (int i = 0; i < 4; i++)
            {
                len += section.get(i).length();
            }
            if (len != s.length()) return;
            else
            {
                result.add(section.get(0) + '.' +
                            section.get(1) + '.' +
                            section.get(2) + '.' +
                            section.get(3));
            }
        }
        else
        {
            if (pos < s.length())
            {
                section.add(s.substring(pos, pos+1));
                dfs(s, pos+1, depth+1);
                section.remove(section.size()-1);
            }
            if (pos + 1 < s.length() && s.charAt(pos) != '0')
            {
                section.add(s.substring(pos, pos+2));
                dfs(s, pos+2, depth+1);
                section.remove(section.size()-1);
            }
            if (pos + 2 < s.length() && isValid(s, pos))
            {
                section.add(s.substring(pos, pos+3));
                dfs(s, pos+3, depth+1);
                section.remove(section.size()-1);
            }
        }
    }
     
    private boolean isValid(String s, int pos)
    {
        if (s.charAt(pos) == '0') return false;
        if (s.charAt(pos) > '2') return false;
        if (s.charAt(pos) < '2') return true;
        // s[pos] == '2'
        if (s.charAt(pos+1) > '5') return false;
        if (s.charAt(pos+1) < '5') return true;
        // s[pos+1] == '5'
        return (s.charAt(pos+2) <= '5');
    }
}