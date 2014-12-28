class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        vector<vector<int>> height(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    if (i == 0) {
                        height[i][j] = 1;
                    } else {
                        height[i][j] = height[i-1][j] + 1;
                    }
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            result = max(result, maxRect(height[i]));
        }
        return result;
    }
    
    int maxRect(vector<int> &arr) {
        stack<int> stk; // increasing
        arr.push_back(-1);
        int result = 0;
        int i = 0;
        while (i < arr.size()) {
            if (stk.empty() || arr[i] >= arr[stk.top()]) {
                stk.push(i);
                i++;
            } else {
                int idx = stk.top();
                stk.pop();
                int width = (stk.empty() ? i : i - stk.top() - 1);
                result = max(result, width * arr[idx]);
            }
        }
        arr.pop_back();
        return result;
    }
};
