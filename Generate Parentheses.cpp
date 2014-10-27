class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisRe(n, n, "", result);
        return result;
    }
    
    void generateParenthesisRe(int left, int right, string current, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        if (left > 0) {
            generateParenthesisRe(left - 1, right, current + "(", result);
        }
        if (right > left) {
            generateParenthesisRe(left, right - 1, current + ")", result);
        }
    }
};
