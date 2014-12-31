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
    string fractionToDecimal(int numeratorInt, int denominatorInt) {
        llong numerator = numeratorInt;
        llong denominator = denominatorInt;
        bool positive = (numerator >= 0 && denominator > 0) ||
                        (numerator <= 0 && denominator < 0);
        if (numerator < 0) {
            numerator = -numerator;
        }
        if (denominator < 0) {
            denominator = -denominator;
        }
        llong integer = numerator / denominator;
        llong remain = numerator % denominator;
        vector<llong> remains;
        vector<llong> decimals;
        while (remain != 0 && find(remains.begin(), remains.end(), remain) == remains.end()) {
            remains.push_back(remain);
            remain *= 10;
            decimals.push_back(remain / denominator);
            remain %= denominator;
        }
        stringstream ss;
        if (!positive) {
            ss << '-';
        }
        ss << integer;
        if (decimals.size() == 0) {
            return ss.str();
        } else if (remain == 0) {
            ss << '.';
            for (int i = 0; i < decimals.size(); i++) {
                ss << decimals[i];
            }
            return ss.str();
        } else {
            int k = 0;
            for (k = 0; k < remains.size(); k++) {
                if (remains[k] == remain) {
                    break;
                }
            }
            ss << '.';
            for (int i = 0; i < k; i++) {
                ss << decimals[i];
            }
            ss << '(';
            for (int i = k; i < decimals.size(); i++) {
                ss << decimals[i];
            }
            ss << ')';
            return ss.str();
        }
    }
};
