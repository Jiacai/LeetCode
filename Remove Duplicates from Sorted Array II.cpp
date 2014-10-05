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
};
