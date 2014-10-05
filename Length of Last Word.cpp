class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if (s == NULL)
            return 0;
        int start = 0;
        int end = 0;
        int i = 0;
        bool mode = false; // false for space mode, true for char mode
        while (true) {
            if (!mode) {
                if (s[i] == '\0') {
                    break;
                }
                if (s[i] != ' ') {
                    start = i;
                    mode = true;
                }
            } else {
                if (s[i] == '\0') {
                    end = i;
                    break;
                }
                if (s[i] == ' ') {
                    end = i;
                    mode = false;
                }
            }
            i++;
        }
        return end - start;
    }
    
    int lengthOfLastWord_1(const char *s) {
        int res = 0;
        int length = strlen(s);
        for (int i = length - 1; i >= 0; --i)
            if (s[i] != ' ') res++;
            else if(res > 0) break;
        return res;
    }
};
