class Solution {
public:
    int divide(int dividend, int divisor) {
        long long dividendL = abs((long long) dividend);
        long long divisorL = abs((long long) divisor);
        long long result = 0;
        while (dividendL >= divisorL) {
            long long div = divisorL;
            long long quot = 1;
            while (dividendL >= div * 2) {
                div *= 2;
                quot *= 2;
            }
            dividendL -= div;
            result += quot;
        }
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            result = -result;
        if (result >= (unsigned int)(0x1<<31)) --result;
        return result;
    }
};
