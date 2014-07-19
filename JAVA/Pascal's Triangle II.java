public class Solution {
    public ArrayList<Integer> getRow(int rowIndex) {
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(1);
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        for (int i = 1; i <=rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i) tmp.add(1);
                else
                {
                    tmp.add(ans.get(j-1) + ans.get(j));
                }
            }
            // update ans and clear tmp
            ans.clear();
            ans.addAll(tmp);
            tmp.clear();
        }
        return ans;
    }
}