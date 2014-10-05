/**
 * Annie's solution is better
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0;
        bool dup = false;;
        for (int i = 0; i < n; i++) {
            if (i == 0 || A[i] != A[i-1] || !dup) {
                if (i == 0 || A[i] != A[i - 1]) {
                    dup = false;
                } else {
                    dup = true;
                }
                A[j] = A[i];
                j++;
            }
        }
        return j;
    }
    
    int removeDuplicates_1(int A[], int n) {
        if (n <= 2) return n;
        int j = 2;
        for (int i = 2; i < n; ++i)
            if (A[i] != A[j-1] || A[i] != A[j-2])
                A[j++] = A[i];
        return j;
    }
};
