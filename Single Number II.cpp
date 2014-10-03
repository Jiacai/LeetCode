class Solution {
public:
    int singleNumber(int A[], int n) {
        int bits[32] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                int k = (A[i] & (1 << j)) == 0 ? 0 : 1;
                bits[j] = (bits[j] + k) % 3;
            }
        }
        int r = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] != 0) {
                r |= (1 << i);
            }
        }
        return r;
    }
};
