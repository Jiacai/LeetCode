/*
1, 8 = 0.125
1, 6 = 0.1(6)
-50, 6 = -6.25
0, -3 = 0
-1, -2147483648 = "0.0000000004656612873077392578125"
*/
typedef long long llong;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string result;
        llong n = numerator;
        llong d = denominator;
        if(n < 0 ^ d < 0 ) result+='-'; 
        n = abs(n);
        d = abs(d);
        result += to_string(n / d);
        llong r = n % d;
        if (r == 0) {
            return result;
        } else {
            result += '.';
        }
        unordered_map<int, int> map;
        while (r != 0) {
            if (map.find(r) != map.end()) {
                result.insert(map[r], 1, '(');
                result += ')';
                break;
            }
            map[r] = result.size();
            r *= 10;
            result += to_string(r / d);
            r %= d;
        }
        return result;
    }
};
