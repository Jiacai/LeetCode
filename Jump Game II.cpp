class Solution {
public:
    int jump(int A[], int n) {
        int i = 0;
        int step = 0;
        while (i < n-1) {
            if (A[i] + i >= n-1) return step + 1;
            int max_dist = i;
            int max_k = i;
            for (int k = i + 1; k <= A[i] + i; k++) {
                int dist = A[k] + k;
                if (dist > max_dist) {
                    max_k = k;
                    max_dist = dist;
                }
            }
            i = max_k;
            step++;
        }
        return step;
    }
};
