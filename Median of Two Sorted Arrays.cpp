class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ((m + n) % 2 == 1) {
            return findKthSortedArrays(A, m, B, n, (m + n + 1) / 2);
        } else {
            return (findKthSortedArrays(A, m, B, n, (m + n) / 2) +
                    findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
    
    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        // always ensure A is the shorter array
        if (m > n) {
            return findKthSortedArrays(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k-1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int i = min(m, k / 2);
        int j = k - i;
        int a = A[i - 1];
        int b = B[j - 1];
        // always get rid of something in the left
        if (a < b) {
            return findKthSortedArrays(A + i, m - i, B, n, k - i);
        }
        if (a > b) {
            return findKthSortedArrays(A, m, B + j, n - j, k - j);
        }
        return a;
    }
};
