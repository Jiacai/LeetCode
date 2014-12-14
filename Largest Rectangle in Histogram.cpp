class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        height.push_back(-1);
        stack<int> stk;
        int result = 0;
        int i = 0;
        while(i < height.size()) {
            if (stk.empty() || height[stk.top()] < height[i]) {
                stk.push(i);
                i++;
            } else {
                int j = stk.top();
                stk.pop();
                int area = height[j] * (i - 1 - (stk.empty() ? -1 : stk.top()));
                result = max(result, area);
            }
        }
        height.pop_back();
        return result;
    }
};
