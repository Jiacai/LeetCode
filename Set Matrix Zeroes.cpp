class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        if (n == 0) return;
        bool zeroFirstRow = false;
        bool zeroFirstCol = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) {
                        zeroFirstRow = true;
                    } else {
                        matrix[i][0] = 0;
                    }
                    if (j == 0) {
                        zeroFirstCol = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (zeroFirstCol) {
            for (int k = 0; k < m; k++) {
                matrix[k][0] = 0;
            }
        }
        if (zeroFirstRow) {
            for (int k = 0; k < n; k++) {
                matrix[0][k] = 0;
            }
        }
    }
};
