class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int last = 0;
        for (int i = 0; i < s.size(); i++) {
            int val = getRomanVal(s[i]);
            if (val <= last) {
                result += val;
                last = val;
            } else {
                result += (val - 2 * last);
                last = val;a
            }
        }
        return result;
    }
    
    int getRomanVal(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
        return 0;
    }
    
    // Annie's solution with map
    int romanToInt_1(string s) {
        unordered_map<char, int> roman;
        roman['M'] = 1000;
        roman['D'] = 500;
        roman['C'] = 100;
        roman['L'] = 50;
        roman['X'] = 10;
        roman['V'] = 5;
        roman['I'] = 1;

        int res = 0, N = s.size();
        for (int i = 0; i < N; ++i)
        {
            if (i < N-1 && roman[s[i]] < roman[s[i+1]])
                res -= roman[s[i]];
            else
                res += roman[s[i]];
        }
        return res;
    }
};
