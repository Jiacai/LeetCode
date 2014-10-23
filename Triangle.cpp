class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
        int m = triangle.size();
        vector<int> dp(m);
        for (int i = 0; i < m; i++) {
            vector<int> tmp(i + 1);
            for (int j = 0; j <= i; j++) {
                if (i == 0) {
                    tmp[0] = triangle[0][0];
                } else if (j == 0) {
                    tmp[0] = dp[0] + triangle[i][0];
                } else if (j == i) {
                    tmp[j] = dp[j - 1] + triangle[i][i];
                } else {
                    tmp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
            for (int j = 0; j <= i; j++) {
                dp[j] = tmp[j];
            }
        }
        int result = dp[0];
        for (int i = 0; i < dp.size(); i++) {
            result = min(result, dp[i]);
        }
        return result;
    }
};
