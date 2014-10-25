/*
Annie's solution uses a transition table
*/
class Solution {
public:
    bool isSign(const char c) {
        return (c == '+' || c == '-');
    }
    
    bool isNum(const char c) {
        return  (c >= '0' && c <= '9');
    }
    
    bool isNumber(const char *s) {
        if (s == NULL)
            return false;
        int state = 0;
        int i = 0;
        while (s[i] != '\0') {
            switch (state) {
                case 0: // init
                    if (s[i] == ' ') {
                        // do nothing
                    } else if (isSign(s[i])) {
                        state = 1;
                    } else if (isNum(s[i])) {
                        state = 2;
                    } else if (s[i] == '.') {
                        state = 3;  
                    } else {
                        return false;
                    }
                    break;
                case 1: // sign
                    if (isNum(s[i])) {
                        state = 2;
                    } else if (s[i] == '.') {
                        state = 3;
                    } else {
                        return false;
                    }
                    break;
                case 2: // num
                    if (isNum(s[i])) {
                        // do nothing  
                    } else if (s[i] == '.') {
                        state = 4;
                    } else if (s[i] == 'e') {
                        state = 5;
                    } else if (s[i] == ' ') {
                        state = 9;  
                    } else {
                        return false;
                    }
                    break;
                case 3: // start with '.'
                    if (isNum(s[i])) {
                        state = 6;
                    } else {
                        return false;
                    }
                    break;
                case 4: // num + '.'
                    if (isNum(s[i])) {
                        state = 6;
                    } else if (s[i] == 'e') {
                        state = 5;
                    } else if (s[i] == ' ') {
                        state = 9;
                    } else {
                        return false;
                    }
                    break;
                case 5: // 'e'
                    if (isSign(s[i])) {
                        state = 7;
                    } else if (isNum(s[i])) {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case 6: // '.' + num
                    if (isNum(s[i])) {
                        // do nothing
                    } else if (s[i] == 'e') {
                        state = 5;
                    } else if (s[i] == ' ') {
                        state = 9;
                    } else {
                        return false;
                    }
                    break;
                case 7: // sign after 'e'
                    if (isNum(s[i])) {
                        state = 8;
                    } else {
                        return false;
                    }
                    break;
                case 8: // num after 'e'
                    if (isNum(s[i])) {
                        // do nothing
                    } else if (s[i] == ' ') {
                        state = 9;
                    } else {
                        return false;
                    }
                    break;
                case 9: // trailing spaces
                    if (s[i] != ' ') {
                        return false;
                    }
                    break;
            }
            i++;
        }
        return (state == 2 || state == 4 || state == 6 || state == 8 || state == 9);
    }
    
    bool isNumber_1(const char *s) {
        enum InputType {INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT};
        int transitionTable[][SPACEEND] = 
        { /* 0   1   2   3   4   5  */
             0,  1,  2,  3,  4,  0, // 0: INVALID
             0,  1,  2,  3,  4,  0, // 1: SPACE
             0,  0,  0,  3,  4,  0, // 2: SIGN
             0,  6,  0,  3,  7,  5, // 3: DIGIT
             0,  0,  0,  7,  0,  0, // 4: DOT
             0,  0,  2,  8,  0,  0, // 5: EXPONENT
             0,  6,  0,  0,  0,  0, // 6: END WITH SPACE
             0,  6,  0,  7,  0,  5, // 7: DOT AND DIGIT
             0,  6,  0,  8,  0,  0, // 8: END WITH SPACE OR DIGIT
        };
        
        InputType last = INVALID;
        while (*s != '\0')
        {
            InputType state = INVALID;
            if (*s == ' ')
                state = SPACE;
            else if (isdigit(*s))
                state = DIGIT;
            else if (*s == '+' || *s == '-')
                state = SIGN;
            else if (*s == 'e')
                state = EXPONENT;
            else if (*s == '.')
                state = DOT;
            last = (InputType) transitionTable[last][state];
            if (last == INVALID) return false;
            s++;
        }
        bool validFinal[] = {0, 0, 0, 1, 0, 0, 1, 1, 1};
        return val
};
