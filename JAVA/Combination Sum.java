public class Solution {
    ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
    ArrayList<Integer> tmp = new ArrayList<Integer>();
    public ArrayList<ArrayList<Integer>> combinationSum(int[] candidates, int target) {
        ans.clear();
        tmp.clear();
        sub(candidates, 0, 0, target);
        return ans;
    }
     
    private void sub(int[] candidates, int pos, int sum, int target)
    {
        if (sum > target) return;
        else if (sum == target)
        {
            ArrayList<Integer> arr = new ArrayList<Integer>(tmp);
            Collections.sort(arr);
            ans.add(arr);
        }
        else
        {
            for (int i = pos; i < candidates.length; i++)
            {
                tmp.add(candidates[i]);
                sub(candidates, i, candidates[i]+sum, target);
                tmp.remove(tmp.size()-1);
            }
        }
    }
}