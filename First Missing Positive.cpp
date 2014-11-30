class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (A[i] > 0) {
                i++;
            } else if (A[j] <= 0) {
                j--;
            } else {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                i++;
                j--;
            }
        }
        int cnt = j + 1;
        for (int i = 0; i < cnt; i++) {
            int x = A[i];
            if (x < 0)
                x = -x;
            if (x - 1< cnt && A[x - 1] > 0) {
                A[x - 1] = -A[x - 1];
            }
        }
        for (int i = 0; i < cnt; i++) {
            if (A[i] > 0)
                return i + 1;
        }
        return cnt + 1;
    }
    
    int firstMissingPositive_1(int A[], int n) {
        int i = 0;
        while (i < n)
        {
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i])
                swap(A[i], A[A[i]-1]);
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
};
