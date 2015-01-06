class Solution {
public:
    vector<int> ways;
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') return 0;
        int N = s.size();
        int f0 = 1, f1 = 1;
        for (int i = 1; i < N; ++i) {
            if (s[i] == '0') f1 = 0;
            int num = s[i] - '0' + (s[i-1] - '0') * 10;
            if (num < 10 || num > 26) {
                f0 = 0;
            }
            int tmp = f1;
            f1 = f1 + f0;
            f0 = tmp;
        }
        return f1;
    }
};
