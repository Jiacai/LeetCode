public class Solution {
    ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
    ArrayList<Integer> tmp = new ArrayList<Integer>();
    public ArrayList<ArrayList<Integer>> combinationSum2(int[] candidates, int target) {
        ans.clear();
        tmp.clear();
        Arrays.sort(candidates);
        boolean used[] = new boolean[candidates.length];
        sub(candidates, 0, 0, target, used);
        return ans;
    }
      
    private void sub(int[] candidates, int pos, int sum, int target, boolean used[])
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
                if (i!=0 && candidates[i] == candidates[i-1] && !used[i-1]) continue;
                tmp.add(candidates[i]);
                used[i] = true;
                sub(candidates, i+1, candidates[i]+sum, target, used);
                tmp.remove(tmp.size()-1);
                used[i] = false;
            }
        }
    }
}