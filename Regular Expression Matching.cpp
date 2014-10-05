/**
 * the later 2 solutions are from Annie 
 */
 
class Solution {
public:
    vector<vector<int> > dp;
    int lens;
    int lenp;
    bool isMatch(const char *s, const char *p) {
        lens = strlen(s);
        lenp = strlen(p);
        dp.clear();
        dp.resize(lens + 1);
        for (int i = 0; i <= lens; i++)
            dp[i].resize(lenp);
        return isMatchRe(s, p, 0, 0);
    }
    
    bool isMatchRe(const char *s, const char *p, int i , int j) {
        if (i == lens && j == lenp)
            return true;
        if (i > lens || j == lenp)
            return false;
        if (dp[i][j] == -1)
            return false;
        if (dp[i][j] == 1)
            return true;
        bool result = false;
        if (j+1 != lenp && p[j+1] == '*') {
            if (i == lens) {
              result = isMatchRe(s, p, i, j+2);
            } else if (s[i] == p[j] || p[j] == '.') {
                result = isMatchRe(s, p, i+1, j)
                        || isMatchRe(s, p, i, j+2);
            } else {
                result = isMatchRe(s, p, i, j+2);
            }
        } else if (s[i] == p[j] || p[j] == '.') {
            result = isMatchRe(s, p, i+1, j+1);
        } else {
            result = false;
        }
        dp[i][j] = result ? 1 : -1;
        return result;
    }
    
    bool isMatch_1(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        if (*(p+1) == '*') // next is '*'
        {
            while ((*s == *p || *p == '.') && *s != '\0')
            {
                if (isMatch(s, p+2))
                    return true;
                s++;
            }
            return isMatch(s, p+2);
        }
        
        if (*s == '\0') return false;
        return (*s == *p || *p == '.') && isMatch(s+1, p+1);
    }
    
    bool isMatch_2(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        
        if (*s == *p || *p == '.' && *s != '\0')
            return *(p+1) != '*' ? isMatch(s+1, p+1) : 
                                   isMatch(s+1, p) || isMatch(s, p+2);
        else
            return *(p+1) == '*' && isMatch(s, p+2);
    }
};
