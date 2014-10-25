class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        int size = digits.size();
        int carry = 0;
        for (int i = size - 1; i >= 0; i--) {
            int tmp = digits[i] + carry;
            if (i == size - 1) tmp++;
            carry = tmp / 10;
            tmp = tmp % 10;
            result.push_back(tmp);
        }
        if (carry != 0) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
