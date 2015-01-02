class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs(int(s.size() - t.size())) > 1) {
            return false;
        }
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size() && s[i] == t[j]) {
            i++;
            j++;
        }
        return isEqual(s, t, i + 1, j)
            || isEqual(s, t, i, j + 1)
            || isEqual(s, t, i + 1, j + 1);
    }
    
    bool isEqual(string &s, string &t, int i, int j) {
        while (i < s.size() && j < t.size() && s[i] == t[j]) {
            i++;
            j++;
        }
        return (i == s.size() && j == t.size());
    }
};
