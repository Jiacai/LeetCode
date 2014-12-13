class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk; // this stack stores all unmatched '(' positions
        int lastLeft = -1; // last unmatched ')' position
        int longest = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else { // ')'
                if (!stk.empty()) {
                    stk.pop();
                    if (!stk.empty()) {
                        longest = max(longest, i - stk.top()); 
                    } else {
                        longest = max(longest, i - lastLeft); 
                    }
                    
                } else { // no match
                    lastLeft = i;
                }
            }
        }
        return longest;
    }
};
