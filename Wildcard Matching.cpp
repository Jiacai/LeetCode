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
};
