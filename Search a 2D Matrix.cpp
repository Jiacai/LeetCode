class Solution {
public:

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        // find row
        int left = 0;
        int right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int row = right;
        if (row == -1) return false;
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
    
    // Solution 2.
    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = M * N - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int row = mid / M, col = mid % M;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};
