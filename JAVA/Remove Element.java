public class Solution {
    public int removeElement(int[] A, int elem) {
        int i = 0;
        int j = 0;
        int len = A.length;
        while (j < len)
        {
            if (A[j] == elem)
            {
                j++;
            }
            else
            {
                A[i] = A[j];
                i++;
                j++;
            }
        }
        return i;
    }
}