class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        vector<vector<bool>> isP(size, vector<bool>(size + 1, false)); // substr(start, len), isPalindrome
        // calc whether substr(start, len) is a palindrome
        for (int len = 1; len <= size; len++) {
            for (int i = 0; i + len <= size; i++) {
                if (len == 1) {
                    isP[i][len] = true;
                } else if (len == 2) {
                    isP[i][len] = s[i] == s[i+1];
                } else {
                    isP[i][len] = (s[i] == s[i+len-1] && isP[i+1][len-2]);
                }
            }
        }
        
        vector<int> dp(size + 1, INT_MAX); // substr(0, len), how many cut
        for (int len = 1; len <= size; len++) {
            if (isP[0][len]) {
                dp[len] = 0;
            } else {
                for (int i = 1; i <= len - 1; i++) {
                    if (isP[i][len-i]) {
                        dp[len] = min(dp[len], dp[i] + 1);    
                    }
                }
            }
        }
        return dp[size];
    }
};
