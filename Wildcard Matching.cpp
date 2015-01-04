class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int i = 0;
        int j = 0;
        int sBackup = -1;
        int pBackup = -1;
        while (s[i] != '\0') {
            if (s[i] == p[j] || p[j] == '?') {
                i++; j++;
            } else if (p[j] == '*') {
                while (p[j] == '*')
                    j++;
                pBackup = j - 1;
                sBackup = i;
            } else if (s[i] != p[j]) {
                if (pBackup == -1) {
                    return false;
                }
                j = pBackup;
                i = sBackup + 1;
                sBackup = i;
                j++;
            }
        }
        while (p[j] == '*')
            p++;
        return s[i] == '\0' && p[j] == '\0';
    }
    
    bool isMatch_1(const char *s, const char *p) {
        const char *sBackup = NULL;
        const char *pBackup = NULL;
        while (*s != '\0') {
            if (*s == *p || *p == '?') {
                s++;
                p++;
            } else if (*p == '*') {
                sBackup = s;
                pBackup = p++;
            } else if (pBackup != NULL) {
                p = pBackup + 1;
                s = ++sBackup;
            } else {
                return false;
            }
        }
        while (*p == '*') {
            p++;
        }
        return *s == '\0' && *p == '\0';
    }
};
