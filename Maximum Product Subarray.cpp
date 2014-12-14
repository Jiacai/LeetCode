class Solution {
public:
    int maxProduct(int A[], int n) {
        vector<int> positive(n);
        vector<int> minus(n);
        int result = A[0];
        for (int i = 0; i < n; i++) {
            int minVal = A[i];
            int maxVal = A[i];
            if (i > 0) {
                minVal = min(minVal, positive[i - 1] * A[i]);
                minVal = min(minVal, minus[i - 1] * A[i]);
                maxVal = max(maxVal, positive[i - 1] * A[i]);
                maxVal = max(maxVal, minus[i - 1] * A[i]);
            }
            positive[i] = maxVal > 0 ? maxVal : 1;
            minus[i] = minVal < 0 ? minVal : 1;
            result = max(result, maxVal);
        }
        return result;
    }
};
