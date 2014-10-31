class Solution {
public:
    int trap(int A[], int n) {
        stack<int> stk; // descending
        int result = 0;
        int i = 0;
        while (i < n) {
            if (stk.size() == 0 || A[stk.top()] > A[i]) {
                stk.push(i); // the index
                i++;
            } else { // A[i] >= stk.top();
                int j = stk.top();
                stk.pop();
                if (stk.size() != 0) {
                    result += (i - stk.top() - 1) * (min(A[stk.top()], A[i]) - A[j]);
                }
            }
        }
        return result;
    }
};
