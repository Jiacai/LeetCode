class Solution {
public:
    const string rom[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
        {"", "M", "MM", "MMM"}
    };

    string intToRoman(int num) {
        string result;
        int i = 3;
        while (num > 0) {
            int divisor = pow(10, i);
            result += rom[i][num / divisor];
            num %= divisor;
            i--;
        }
        return result;
    }
};
