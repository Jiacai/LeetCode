import java.util.*;
public class Solution {
    private ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
    private HashSet<String> ansSet = new HashSet<String>();
    private HashSet<String> posSet = new HashSet<String>();
    public ArrayList<ArrayList<Integer>> fourSum(int[] num, int target) {
        ans.clear();
        ansSet.clear();
        posSet.clear();
        Arrays.sort(num);
        int len = num.length;
        ArrayList<Pair> pairs = new ArrayList<Pair>();
        for (int i = 0; i < len; i++)
        {
            for (int j = i+1; j < len; j++)
            {
                pairs.add(new Pair(num[i], num[j], i, j));
            }
        }
        Collections.sort(pairs);
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(0); stack.push(pairs.size()-1);
        while (!stack.empty())
        {
            int r = stack.pop();
            int l = stack.pop();
            if (l >= r) continue;
            String posKey = "" + l + "_" + r;
            if (posSet.contains(posKey)) continue;
            else posSet.add(posKey);
            int sum = pairs.get(l).sum + pairs.get(r).sum;
            if (sum < target)
            {
                stack.push(l+1);
                stack.push(r);
            }
            else if (sum > target)
            {
                stack.push(l);
                stack.push(r-1);
            }
            else // ==
            {
                if (pairs.get(l).aIdx != pairs.get(r).aIdx &&
                    pairs.get(l).aIdx != pairs.get(r).bIdx &&
                    pairs.get(l).bIdx != pairs.get(r).aIdx &&
                    pairs.get(l).bIdx != pairs.get(r).bIdx)
                {
                    // add to result;
                    ArrayList<Integer> arr = new ArrayList<Integer>();
                    arr.add(pairs.get(l).a);
                    arr.add(pairs.get(l).b);
                    arr.add(pairs.get(r).a);
                    arr.add(pairs.get(r).b);
                    Collections.sort(arr);
                    String key = "";
                    for (int k = 0; k < 4; k++)
                    {
                        key = key + arr.get(k) + "_";
                    }
                    if (!ansSet.contains(key))
                    {
                        ansSet.add(key);
                        ans.add(arr);
                    }
                }     
                stack.push(l);
                stack.push(r-1);
                stack.push(l+1);
                stack.push(r);
            }
        }
        return ans;
    }
}
 
class Pair implements Comparable<Pair>
{
    int a;
    int b;
    int sum;
    int aIdx;
    int bIdx;
     
    public Pair (int a, int b, int aIdx, int bIdx)
    {
        this.a = a;
        this.b = b;
        this.sum = a + b;
        this.aIdx = aIdx;
        this.bIdx = bIdx;
    }
     
    public int compareTo(Pair that)
    {
        return this.sum - that.sum;
    }
}