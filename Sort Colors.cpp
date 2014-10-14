class Solution {

public:
    void sortColors(int A[], int n) {
        int i = 0;
        int j = 0;
        int k = n - 1;
        // after every loop
        // 0,0,0,^i,1,1,1,1,^j,.,.,.,^k,2,2,2
        // j >= i, j <= k
        while (j <= k) {
            if (A[j] == 0) {
                swap(A[i], A[j]);
                i++;
                j++;
            } else if (A[j] == 2) {
                swap(A[j], A[k]);
                k--;
            } else {
                j++;
            }
        }
    }
};
