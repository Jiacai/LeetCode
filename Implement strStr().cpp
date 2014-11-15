typedef long long llong;

class Solution {
public:
    int strStr(char *s, char *p) {
        llong MOD = 100000007;
        llong BASE = 257;
        int plen = strlen(p);
        int slen = strlen(s);
        if (plen > slen) return -1;
        llong target = 0;
        llong power = 1;
        for (int i = 0; i < plen; i++) {
            target = (target * BASE + p[i]) % MOD;
            power = power * BASE % MOD;
        }
        
        llong sum = 0;
        for (int i = 0; i < plen; i++) {
            sum = (sum * BASE + s[i]) % MOD;
        }
        for (int i = 0; i <= (slen - plen); i++) {
            if (sum == target && compare(s, p, i)) {
                return i;
            }
            sum = (sum * BASE + s[i + plen]) % MOD;
			sum = (sum - power * s[i]) % MOD;
			if (sum < 0) sum += MOD;
        }
        return -1;
    }
    
    bool compare(char *s, char *p, int idx) {
        int i = idx;
        int j = 0;
        while (p[j] != '\0' && s[i] == p[j]) {
            i++;
            j++;
        }
        return p[j] == '\0';
    }
};
