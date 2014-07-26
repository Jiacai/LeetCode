public class Solution {
    public int maxSubArray(int[] A) {
        int len = A.length;
        if (len == 0) return 0;
        int[] max = new int[len];
        max[0] = A[0];
        int ans = max[0];
        for (int i = 1; i < len; i++)
        {
             if (max[i-1] <= 0)
             {
                 max[i] = A[i];
             }
             else {
                 max[i] = max[i-1] + A[i];
             }
             if (max[i] > ans) ans = max[i];
        }
        return ans;
    }
}