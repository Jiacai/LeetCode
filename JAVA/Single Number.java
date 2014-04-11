public class Solution {
    public int singleNumber(int[] A) {
        int a = A[0];
        for (int i = 1; i < A.length; i++)
        {
            a ^= A[i];
        }
        return a;
    }
}