public class Solution {
    public int candy(int[] ratings) {
        int len = ratings.length;
        if (len == 0) return 0;
        int num[] = new int[len];
        int cnt = 0;
        for (int i = 1; i < len; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            num[i] = cnt;
        }
        cnt = 0;
        for (int i = len - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cnt++;
            }
            else {
                cnt = 0;
            }
            num[i] = Math.max(num[i], cnt);
        }
        int min = len;
        for (int i = 0; i < len; i++) {
            min += num[i];
        }
        return min;
    }
}