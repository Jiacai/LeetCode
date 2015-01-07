class Solution {
public:
    int sqrt(int x) {
        if (x == 1 || x == 0) {
            return x;
        }
        double last = 0;
        double result = 1;
        while (last != result) {
            last = result;
            result = (last + x / last) / 2;
        }
        return (int) result;
    }
};
