public class Solution {
    public int minimumTotal(ArrayList<ArrayList<Integer>> triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        int[] sum = new int[len];
        sum[0] = triangle.get(0).get(0);
        for (int i = 1; i < len; i++) {
            ArrayList<Integer> arr = triangle.get(i);
            int tmp = sum[0];
            for (int j = 0; j < i+1; j++) {
                int min = arr.get(j) + tmp;
                if (j + 1 < i) { tmp = Math.min(sum[j], sum[j+1]); }
                else { tmp = sum[j]; }
                sum[j] = min;
            }   
        }
        int min = sum[0];
        for (int i = 0; i < len; i++) {
            if (sum[i] < min) min = sum[i];
        }
        return min;
    }
}