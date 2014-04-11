public class Solution {
    public int threeSumClosest(int[] num, int target) {
        Arrays.sort(num);
        int len = num.length;
        int diff = target - (num[0] + num[1] + num[2]);
        for (int i = 0; i < len - 2; i++)
        {
            int tmp = twoSumClosest(num, target - num[i], i + 1);
            if (tmp == 0) return target;
            if (Math.abs(tmp) < Math.abs(diff))
            {
                diff = tmp;
            }
        }
        return target - diff;
    }
     
    private int twoSumClosest(int[] num, int target, int l)
    {
        int r = num.length - 1;
        int diff = target - num[l] - num[r];
        while (l < r)
        {
            int sum = num[l] + num[r];
            if (sum == target)
            {
                return 0;
            }
            else
            {
                int tmp = target - num[l] - num[r];
                if (Math.abs(tmp) < Math.abs(diff))
                {
                    diff = tmp;
                }
                if (sum > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return diff;
    }
}