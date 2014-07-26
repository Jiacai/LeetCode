public class Solution {
    public int numTrees(int n) {
        if (n ==0) return 0;
        int sum[] = new int[n+1];
        sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int j = 1; j <=i; j++) {
                if (j == 1 || j == i) total += sum[i-1];
                else {
                    total+= (sum[j-1]*sum[i-j]);
                }
            }
            sum[i] = total; 
        }
        return sum[n];
    }
}