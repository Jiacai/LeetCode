public class Solution {
    public int removeDuplicates(int[] A) {
        if (A.length == 0 || A.length == 1) return A.length;
        int pos = 0;
        int current = 0; 
        boolean encounted = false;
        while (current < A.length)
        {
            if (current == 0 || A[current] != A[current-1])
            {
                A[pos] = A[current];
                pos++;
                current++;
                encounted = false;
            }
            else // A[current] == A[current-1]
            {
                if (!encounted)
                {
                    A[pos] = A[current];
                    pos++;
                    current++;
                    encounted = true;
                }
                else
                {
                    current++;
                }
            }
        }
        return pos;
    }
}