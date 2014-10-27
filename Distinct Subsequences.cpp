class Solution {
public:
    int numDistinct(string S, string T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int>> dp(m + 1);
        for (int i = 0; i <= m; i++) {
            dp[i].resize(n + 1);
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (j == 0) {
                    dp[i][0] = 1;
                } else if (i == 0) {
                    dp[0][j] = 0;
                } else if (S[i-1] == T[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
};
