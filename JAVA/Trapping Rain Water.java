public class Solution {
    public int trap(int[] A) {
        // Start typing your Java solution below
        // DO NOT write main() function
        int len = A.length;
        if (len == 0) return 0;
        int maxIndex = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] > A[maxIndex]) {
                maxIndex = i;
            }
        }       
         
        int water = 0;
        int curMax = 0;
        // left to max
        for (int i = 0; i < maxIndex; i++) {
            if (A[i] > curMax) {
                curMax = A[i];
            }
            else if (A[i] < curMax) {
                water += (curMax - A[i]);
            }
        }
        curMax = 0;
        // right to max
        for (int i = len - 1; i > maxIndex; i--) {
            if (A[i] > curMax) {
                curMax = A[i];
            }
            else if (A[i] < curMax) {
                water += (curMax - A[i]);
            }
        }
         
        return water;
    }
}