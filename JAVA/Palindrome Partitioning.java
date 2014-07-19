public class Solution {
    private ArrayList<ArrayList<String>> ans = new ArrayList<ArrayList<String>>();
    public ArrayList<ArrayList<String>> partition(String s) {
        ans.clear();
        int len = s.length();
        boolean[][] dp = new boolean[len][len];
        ArrayList<Integer> pos = new ArrayList<Integer>(); // the position to split
        pos.add(-1);
        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                dp[i][j] = true;
                for (int l=i,r=j; l<=r; l++,r--)
                {
                    if (s.charAt(l)!=s.charAt(r)) dp[i][j] = false;
                }
            }
        }
        sub(s, 0, dp, pos);
        return ans;
    }
    private void sub(String s, int depth, boolean[][] dp, ArrayList<Integer> pos)
    {
        if (depth == s.length()-1)
        {
            int last = pos.get(pos.size()-1)+1;
            if (dp[last][depth])
            {
                pos.add(depth);
                ArrayList<String> res = new ArrayList<String>();
                for (int i = 0; i < pos.size()-1; i++)
                {
                    res.add(s.substring(pos.get(i)+1, pos.get(i+1)+1));
                }
                ans.add(res);
                pos.remove(pos.size()-1);
            }
        }
        else
        {
            int last = pos.get(pos.size()-1)+1;
            if (dp[last][depth])
            {
                pos.add(depth);
                sub(s, depth+1, dp, pos);
                pos.remove(pos.size()-1);
            }
            sub(s, depth+1, dp, pos);
        }
    }
}