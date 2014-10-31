// Annie's solution is easier to understand
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
    
    // Solution: Find left bound and right bound for each element. O(n).
    int trap_1(int A[], int n) {
        if (n == 0) return 0;
        vector<int> maxLeft(n,0);
        vector<int> maxRight(n,0);
        maxLeft[0] = A[0];
        maxRight[n - 1] = A[n - 1];
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], A[i]);
            maxRight[n - 1 - i] = max(maxRight[n - i], A[n - 1 - i]);
        }
        
        int res = 0;
        for (int i = 1; i < n; ++i) {
            res += min(maxLeft[i], maxRight[i]) - A[i];
        }
        return res;
    }
};
