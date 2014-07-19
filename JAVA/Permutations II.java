public class Solution {
    ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
    ArrayList<Integer> tmp = new ArrayList<Integer>();
    public ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
        ans.clear();
        tmp.clear();
        Arrays.sort(num);
        int len = num.length;
        boolean[] canUse = new boolean[len];
        for (int i = 0; i < len; i++)
        {
            canUse[i] = true;
        }
        sub(num, canUse);
        return ans;
    }
     
    private void sub(int[] num, boolean[] canUse)
    {
        if (tmp.size() == num.length)
        {
            ans.add(new ArrayList<Integer>(tmp));
        }
        else
        {
            for (int i = 0; i < num.length; i++)
            {
                if (canUse[i])
                {
                    if (i!=0 && num[i] == num[i-1] && canUse[i-1]) continue;
                    tmp.add(num[i]);
                    canUse[i] = false;
                    sub(num, canUse);
                    tmp.remove(tmp.size()-1);
                    canUse[i] = true;
                }
            }
        }
    }
}