class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        int size = s1.size();
        if (size == 0) {
            return true;
        }
        // i, j, len
        vector<vector<vector<bool>>> dp(size, vector<vector<bool>>(size, vector<bool>(size + 1)));
        for (int len = 1; len <= size; len++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i + len > size || j + len > size) {
                        dp[i][j][len] = false;
                    } else if (len == 1) {
                        dp[i][j][len] = (s1[i] == s2[j]);
                    } else {
                        int value = false;
                        for (int l1 = 1; l1 <= len - 1; l1++) {
                            int l2 = len - l1;
                            if ((dp[i][j+l2][l1] && dp[i+l1][j][l2]) ||
                                (dp[i][j][l1] && dp[i+l1][j+l1][l2])) {
                                value = true;
                                break;
                            }
                        }
                        dp[i][j][len] = value;
                    }
                }
            }
        }
        return dp[0][0][size];
    }
};
