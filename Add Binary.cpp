class Solution {
public:
    string addBinary(string a, string b) {
        int M = a.size();
        int N = b.size();
        int K = max(M, N);
        string s(K, ' ');
        int i = M - 1;
        int j = N - 1;
        int k = K - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            carry = sum / 2;
            s[k--] = '0' + (sum % 2);
        }
        if (carry == 1) {
            s.insert(s.begin(), '1');
        }
        return s;
    }
};
