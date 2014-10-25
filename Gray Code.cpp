class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) return result;
        int m = 1;
        while (m != 1 << n) {
            for (int i = 0; i < m; i++) {
                result.push_back(result[m-i-1] + m);
            }
            m *= 2;
        }
        return result;
    }
    
    vector<int> grayCode_1(int n) {
        vector<int> result(1 << n, 0);
        for (int i = 0; i < 1 << n; ++i)
            result[i] = (i >> 1) ^ i;
        return result;
    }
};
