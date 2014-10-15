class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int tmp = x;
        int div = 1;
        while ((tmp /= 10) != 0) {
            div *= 10;
        }
        while (div > 1) {
            if (x / div != x % 10)
                return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
};
