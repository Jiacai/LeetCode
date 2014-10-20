class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) return 0;
        int res = A[0];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = max(sum + A[i], A[i]);
            res = max(res, sum);
        }
        return res;
    }
};
